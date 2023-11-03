from cs50 import get_float

def main():

    # loop para não aceitar números negativos
    while True:
       troco = get_float("Change owed: ")
       if troco < 0:
          pass
       else:
          break

    print(num_moedas(troco))

def num_moedas(troco):
    
    # essa variável é meio que desnecessária
    resto = troco

    moedas = 0

    while resto > 0:
        if resto >= 0.25:
            resto -= 0.25
            resto = round(resto, 2)
            moedas += 1
        elif resto >= 0.10 and resto < 0.25:
            resto -= 0.10
            resto = round(resto, 2)
            moedas += 1
        elif resto >= 0.05 and resto < 0.10:
            resto -= 0.05
            resto = round(resto, 2)
            moedas += 1
        elif resto < 0.05:
            resto -= 0.01
            resto = round(resto, 2)
            moedas += 1

    return moedas

main()
