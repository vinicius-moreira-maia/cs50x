from flask import Flask, render_template, request, redirect
import sqlite3

# usando a lógica do PY4E, e não a do CS50x
con = sqlite3.connect('froshims.db', check_same_thread=False)

db = con.cursor()
db.execute('CREATE TABLE IF NOT EXISTS registrants (name TEXT NOT NULL, sport TEXT NOT NULL, id INTEGER PRIMARY KEY)')

app = Flask(__name__)

SPORTS = [
    "Basquete",
    "Futebol",
    "MMA"
]

@app.route("/")
def index():
    return render_template("index.html", sports=SPORTS)

@app.route("/deregister", methods=["POST"])
def deregister():
    # esquecendo registrados
    id = request.form.get("id") # pegando o valor do input cujo 'name' é 'id', o 'value' é o que é recebido
    if id:
        db.execute("DELETE FROM registrants WHERE id= ?", id)
        con.commit()
    return redirect("/registrants")

@app.route("/register", methods=["POST"])
def register():

    # validar o nome
    name = request.form.get("name") # dado recebido do input de texto em "index.html"
    sport = request.form.get("sport") # dado recebido do input de 'radio button' em 'index.html'
    # validar inputs no back E no front
    if not name or sport not in SPORTS:
        return render_template("failure.html")

    # lembrando registrados
    # notar que, vendo de uma maneira objetiva, quando eu clico no botão de submeter eu adiciono uma linha ao banco de dados (se os dados forem aceitos)
    db.execute("INSERT INTO registrants (name, sport) VALUES(?, ?)", (name, sport))
    con.commit()

    # confirmar registro
    return redirect("/registrants")

@app.route("/registrants")
def registrants():
    registrants = db.execute("SELECT * FROM registrants") # retorna um objeto iterável (lista de tuplas) da classe sqlite
    return render_template("registrants.html", registrants=registrants)