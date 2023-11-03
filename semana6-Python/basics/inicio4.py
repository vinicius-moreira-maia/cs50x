from cs50 import get_int

x = get_int("x: ")
y = get_int("y: ")

# dividindo dois inteiros em python pode-se obter um float, não dará erro
print(x / y)

# retorna a parte inteira da divisão
print(x // y)

z = 1 / 10

# 50 casas decimais (imprecisão de ponto flutuante)
print(f"{z:.50f}")