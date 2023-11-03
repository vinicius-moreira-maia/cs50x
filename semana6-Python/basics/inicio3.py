# conversão de tipo
# se eu digitar algo que não seja um dígito, o interpretador levantará uma exceção do tipo 'ValueError', portanto usa-se o conjunto try/except, para tentar fazer algo

# x = int(input("x: "))
# y = int(input("y: "))
# print(x + y)

try:
    x = int(input("x: "))
except ValueError:
    print("Não é um inteiro")
    exit() # encerra o programa

try:
    y = int(input("y: "))
except ValueError:
    print("Não é um inteiro")
    exit()

print(x + y)