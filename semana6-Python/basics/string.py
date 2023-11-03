antes = input("Nome: ")

print("depois: ", end = "")

for c in antes:
    # poderia usar .upper() de uma vez só, sem precisar iterar
    print(c.upper(), end = "")

print()