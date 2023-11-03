from cs50 import get_string

"""
- não é necessário usar uma função main(), o programa é executado sempre de forma estruturada
- comentário -> # e aspas triplas """ """
"""

# get_string() é da biblioteca do cs50
resp = get_string("Nome 1: ")

# input() é do python (entrada SOMENTE de strings)
# para outros tipos é necessário converter
resp2 = input("Nome 2: ")

# concatenação
print("oi, " + resp)

# string formatada (interpolação)
print(f"Oi, {resp} {resp2}")