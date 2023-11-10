# adiciona um formulário, segunda rota

from flask import Flask, render_template, request

app = Flask(__name__)

# o caminho padrão '/' vai mostrar o formulário para o usuário
# '@' em cima da função é um decorador, que é outra função que modifica o comportamento desta
# executar esse código sempre que o usuário estiver na página padrão

'''
@app.route("/")
def index():
    return render_template("index.html")

# o caminho '/greet' vai passar o nome para a página
@app.route("/greet", methods=['POST'])
def greet():
    return render_template("greet.html", name=request.form.get("name", "world"))
'''

# usando uma única rota para os dois
@app.route("/", methods=["GET", "POST"])
def index():
    if request.method == "POST":
        # 'name' é o nome do placeholder Jinja, na direita estou pegando o valor do input presente no formulário cujo valor do atributo 'name' é 'name'
        return render_template("greet.html", name=request.form.get("name", "world"))
    # GET
    return render_template("index.html")