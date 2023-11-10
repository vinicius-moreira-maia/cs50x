''' PYTHON COM SQL '''

from cs50 import SQL

# abrindo o banco de dados
db = SQL("sqlite:///times.db")

while True:
    selecao = input("Seleção: ").strip()
    try:
       # o método execute() retorna uma lista de dicionários
       linhas = db.execute("SELECT * FROM times WHERE team LIKE ?", selecao)
       if len(linhas) == 0:
          print("Não há essa seleção.")
          raise ValueError
       else:
          break
    except ValueError:
        pass

for linha in linhas:
    print(linha)