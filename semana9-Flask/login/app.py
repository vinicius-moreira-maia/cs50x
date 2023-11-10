from flask import Flask, redirect, render_template, request, session
from flask_session import Session

# configurando o app
app = Flask(__name__)

# configurando a sessão
app.config["SESSION_PERMANENT"] = False
app.config["SESSION_TYPE"] = "filesystem"
Session(app)

@app.route("/")
def index():
    # ou seja, se não houver valor para a chave 'name' de 'session', redirecionar para a página de login
    if not session.get("name"):
        return redirect("/login")
    return render_template("index.html")

@app.route("/login", methods=["GET", "POST"])
def login():
    if request.method == "POST":
        session["name"] = request.form.get("name")
        return redirect("/")
    return render_template("login.html")

@app.route("/logout")
def logout():
    # de forma simples: se o botão que aciona essa rota for pressionado, o valor 'name' de 'session' será setado para 'None' e a página será redirecionada para o 'index' -> E no index, já que não há 'name' em 'session', serei redirecionado para a página de login
    session["name"] = None
    return redirect("/")