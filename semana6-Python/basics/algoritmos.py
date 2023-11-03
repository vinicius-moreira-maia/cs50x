import sys

lista = {
  "Vini": "123456",
  "Zé" : "654321"
}

if len(sys.argv) != 2:
    print("quantidade inválida de argumentos")
    sys.exit(1)

if sys.argv[1] in lista:
    n = lista[sys.argv[1]]
    print(f"Nome: {sys.argv[1]}, Número: {n} ")
    sys.exit(0)
else:
    print(f"'{sys.argv[1]}' não está na lista")
    sys.exit(1)

