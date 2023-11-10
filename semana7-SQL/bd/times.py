import cs50
import csv

# criando o banco de dados
open("times-tabelas.db", "w").close()
db = cs50.SQL("sqlite:///times-tabelas.db")

# criando 2 tabelas e a relação entre elas
db.execute("CREATE TABLE times(id INTEGER, time TEXT NOT NULL, PRIMARY KEY(id))")
db.execute("CREATE TABLE pontos(times_id INTEGER, pontuacao TEXT NOT NULL, FOREIGN KEY(times_id) REFERENCES times(id))")

# passando os dados do csv para os tabelas
with open("times.csv", "r") as file:
    reader = csv.DictReader(file)
    for row in reader:
        time = row["team"].strip().upper()
        times_id = db.execute("INSERT INTO times(time) VALUES(?)", time) # quando faço a inserção a id é criada e assim já a armazeno em 'times_id'
        db.execute("INSERT INTO pontos(times_id, pontuacao) VALUES(?, ?)", times_id, row["rating"])