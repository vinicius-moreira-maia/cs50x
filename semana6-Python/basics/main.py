# como em C, toda função deve ser definida antes de chamada
# não há constantes em Python

def main():
    printa_miaus(numero_miaus())

def numero_miaus():
    try:
        n = int(input("número de miaus: "))
    except ValueError:
        print("não é inteiro")
        exit()

    return n

def printa_miaus(n):
    for _ in range(n): # _ , pois não uso essa variável para nada além de iterar
        print("miau")

main()

