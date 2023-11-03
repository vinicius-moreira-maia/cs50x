from cs50 import get_string

def main():

    card = get_string("Number: ")

    # checando o número de dígitos, a validade segundo o algoritmo e se só possui números
    if len(card) in [15, 13, 16] and luhn(card) and card.isdigit():

        # checando se é uma bandeira reconhecida ou não
        print(bandeira(card))
    else:
        print("INVALID")

# Luhn’s Algorithm -> O(n) ou 2 x O(n)? Pois usei 2 loops
def luhn(card):

    total = 0

    # primeiro o somatório dos dígitos (x2)
    # incremento de -2 começando no penúltimo e indo até o elemento -1 (não incluso)
    for i in range(len(card) - 2, -1, -2):
            # se o produto for maior ou igual a 10, somar os 2 dígitos
            if int(card[i]) * 2 >= 10:
                aux = str(int(card[i]) * 2)
                n1 = int(aux[0])
                n2 = int(aux[1])
                total += n1 + n2
            else:
                total += int(card[i]) * 2

    # depois o somatório dos dígitos começando pelo último
    for i in range(len(card) - 1, -1, -2):
        total += int(card[i])

    if total % 10 == 0:
        return True
    else:
        return False

# checagem da bandeira
def bandeira(card):
    
    if card.startswith(str(4)):
      if len(card) == 16 or len(card) == 13:
        return "VISA"

    for i in range(51, 56, 1):
        if card.startswith(str(i)):
          if len(card) == 16:
            return "MASTERCARD"

    if card.startswith(str(34)) or card.startswith(str(37)):
        if len(card) == 15:
           return "AMEX"

    return "INVALID"

if __name__ == "__main__":
    main()
