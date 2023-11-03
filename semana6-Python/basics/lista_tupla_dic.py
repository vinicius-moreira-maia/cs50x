# lista de tuplas
frutas = [
    ("banana", 4),
    ("maçã", 30)
]

# dicionário
doces = {
    "pirulito" : 300,
    "chiclete" : 123,
    "jujuba" : 30
}

# assim consigo exibir todos os valores da tupla de uma só vez
for fruta, qtd in frutas:
    print("{} : {}".format(fruta, qtd))

print("----")

# mostrando todos os pares do dicionário
for doce in doces:
    print(f"{doce} : {doces[doce]}")

print("----")

# o método items() retorna uma tupla para cada par chave-valor do dicionário
for qtd in doces.items():
    print(qtd)
    print(type(qtd)) # tupla

print("----")

for doce, qtd in doces.items():
    print(f"{doce} : {qtd}")