from flask import Flask, render_template, request

# criação do objeto 'app' da classe 'Flask', '__name__' é o nome do arquivo python atual ('app.py') que é passado para a classe
app = Flask(__name__)

CORES=[
    "red",
    "green"
]

@app.route("/", methods=["GET", "POST"]) # -> um decorador é uma função!
def index():
    if request.method == "GET":
        return render_template("index.html")

    cor = request.form.get("cor")

    # nunca confiar em inputs do usuário, sempre checar as informações no back-end também
    if cor not in CORES:
        return render_template("index.html", msg="cor inválida!")

    print("Formulário enviado!")
    return render_template("cor.html", cor=cor)