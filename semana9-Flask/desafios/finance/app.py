import os

from cs50 import SQL
from flask import Flask, flash, redirect, render_template, request, session
from flask_session import Session
from tempfile import mkdtemp
from werkzeug.security import check_password_hash, generate_password_hash
from time import ctime

from helpers import apology, login_required, lookup, usd

# criando aplicação Flask
app = Flask(__name__)

# Custom filter -> não acho que esteja sendo usado
app.jinja_env.filters["usd"] = usd

# configurando sessão
app.config["SESSION_PERMANENT"] = False
app.config["SESSION_TYPE"] = "filesystem"
Session(app)

# criando banco de dados (implementação abstraída pelo módulo cs50)
db = SQL("sqlite:///finance.db")

# garantindo que a chave da API foi fornecida via terminal
if not os.environ.get("API_KEY"):
    raise RuntimeError("API_KEY not set")

# ?
@app.after_request
def after_request(response):
    """Ensure responses aren't cached"""
    response.headers["Cache-Control"] = "no-cache, no-store, must-revalidate"
    response.headers["Expires"] = 0
    response.headers["Pragma"] = "no-cache"
    return response

@app.route("/")
@login_required # decorador que dá acesso à rota somente se o usuário estiver logado
def index():

    #----------------------------------------------------------------------
    '''portfolio = {}

    rows = db.execute('SELECT * FROM transactions')

    for row in rows:
        if row['type'] == 'buy':
            if row['stock'] not in portfolio:
                portfolio[row['stock']] = row['amount']
            else:
                portfolio[row['stock']] += row['amount']
        if row['type'] == 'sell':
                # se eu tratar isso na rota de venda, não tem como dar erro aqui (eu acho)
                portfolio[row['stock']] -= row['amount']

    for p in portfolio:
        current = lookup(p)
        current = current['price']
        if portfolio[p] != 0:
            db.execute("INSERT OR IGNORE INTO portfolio(stock, amount, actual_price, user_id) VALUES(?,?,?,?)", p, portfolio[p], current, session["user_id"])'''
    #----------------------------------------------------------------------


    port = db.execute('SELECT * FROM portfolio')

    cash = db.execute('SELECT cash FROM users WHERE id=?', session['user_id'])
    cash = usd(cash[0]['cash'])

    return render_template("index.html", port=port, cash=cash)

@app.route("/buy", methods=["GET", "POST"])
@login_required
def buy():
    if request.method == "POST":

        # possíveis exceçõs
        try:
            shares = int(request.form.get("shares"))
        except:
            return apology("enter a integer number")
        if shares < 1:
            return apology("invalid amount")
        symbol = request.form.get("symbol")
        if len(lookup(symbol)) <= 0:
            return apology('symbol is not found')

        # selecionando o caixa mais atual
        cash = db.execute("SELECT cash FROM users WHERE id=?", session["user_id"])
        cash = cash[0]['cash']

        # selecionando o preço(em tempos distintos) para manter registro de transação
        price = lookup(symbol)
        price = price['price']

        if cash >= shares * price:
            # inserir nova linha em transactions
            db.execute("INSERT INTO transactions(type, stock, amount, price, time, user_id) VALUES(?, ?, ?, ?, ?, ?)", 'buy', symbol, shares, price, ctime(), session["user_id"])

            #atualizar portfolio
            db.execute('UPDATE portfolio SET amount=amount + ?', shares)

            # atualizar cash em users
            db.execute("UPDATE users SET cash=? WHERE id=?", cash - shares * price, session["user_id"])

            return redirect("/")
        else:
            return apology("not enough cash")

    # via GET
    return render_template("buy.html")


@app.route("/history")
@login_required
def history():
    hist = db.execute("SELECT * FROM transactions WHERE user_id=?", session['user_id'])
    return render_template("history.html", hist=hist)

@app.route("/login", methods=["GET", "POST"])
def login():
    """Log user in"""

    # Forget any user_id
    session.clear()

    # User reached route via POST (as by submitting a form via POST)
    if request.method == "POST":

        # Ensure username was submitted
        if not request.form.get("username"):
            return apology("must provide username", 403)

        # Ensure password was submitted
        elif not request.form.get("password"):
            return apology("must provide password", 403)

        # Query database for username
        rows = db.execute("SELECT * FROM users WHERE username = ?", request.form.get("username"))

        # Ensure username exists and password is correct
        if len(rows) != 1 or not check_password_hash(rows[0]["hash"], request.form.get("password")):
            return apology("invalid username and/or password", 403)

        # Remember which user has logged in
        session["user_id"] = rows[0]["id"]

        # Redirect user to home page
        return redirect("/")

    # User reached route via GET (as by clicking a link or via redirect)
    else:
        return render_template("login.html")

@app.route("/logout")
def logout():
    """Log user out"""

    # Forget any user_id
    session.clear()

    # Redirect user to login form
    return redirect("/")


@app.route("/quote", methods=["GET", "POST"])
@login_required
def quote():
    if request.method == "POST":
        symbol = request.form.get("symbol")

        if not symbol:
            return apology("stock symbol does not exist")

        quote = lookup(symbol)

        if not quote:
            return apology("enter a valid stock symbol")

        quote['price'] = usd(quote['price'])

        return render_template("quoted.html", quote=quote)

    return render_template("quote.html")


@app.route("/register", methods=["GET", "POST"])
def register():
    if request.method == "POST":
        username = request.form.get("username")
        password = request.form.get("password")
        check_password = request.form.get("check_password")

        if not username:
            return apology("must provide a username")
        if not password:
            return apology("must provide a password")
        if not password == check_password:
            return apology("passwords don't match")

        rows = db.execute("SELECT * FROM users WHERE username=?", username)

        if len(rows) == 1:
            return apology("username already exists")

        hash = generate_password_hash(password)
        db.execute("INSERT INTO users(username, hash) VALUES(?,?)", username, hash)

        return redirect("/login")
    return render_template("register.html")


@app.route("/sell", methods=["GET", "POST"])
@login_required
def sell():
    """Sell shares of stock"""
    port = db.execute("SELECT * FROM portfolio")
    if request.method == 'POST':
        id_port = request.form.get("symbol")
        num = request.form.get("shares")

        if not id_port or not num:
            return apology("missing shares or stock")

        try:
            num = int(num)
            if num <= 0:
                raise ValueError
        except ValueError:
            return apology("invalid share")

        shares_available = db.execute('SELECT amount FROM portfolio WHERE id=?', id_port)
        if len(shares_available) < 1:
            return apology("not shares available")

        shares_available = shares_available[0]['amount']


        if shares_available - num < 0:
            return apology("can't sell this much")
        else:
            stock = db.execute('SELECT stock FROM portfolio WHERE id=?', id_port)
            stock = stock[0]['stock']

            # selecionando o preço(em tempos distintos) para manter registro de transação
            ap = lookup(stock)
            ap = ap['price']

            db.execute("INSERT INTO transactions(type, stock, amount, price, time, user_id) VALUES(?, ?, ?, ?, ?, ?)", 'sell', stock, num, ap, ctime(), session["user_id"])

            # deletar a linha caso as ações fiquem = 0 ou atualizar
            if shares_available - num == 0:
                db.execute('DELETE FROM portfolio WHERE id=?', id_port)
            elif shares_available - num > 0:
                db.execute('UPDATE portfolio SET amount=?', shares_available - num)

            # atualizar cash em users
            cash = db.execute('SELECT cash FROM users WHERE id=?', session['user_id'])
            cash = cash[0]['cash']
            db.execute("UPDATE users SET cash=? WHERE id=?", cash + num * ap, session["user_id"])

            return redirect("/")

    return render_template("sell.html", port=port)

