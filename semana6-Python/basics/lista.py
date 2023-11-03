from cs50 import get_int

notas = [] # lista vazia
i = 1

for _ in range(3):
    nota = get_int(f"Nota {i}: ")
    i += 1
    notas.append(nota)
    # ou notas += [nota] -> junção de listas

print(f"Média: {sum(notas) / len(notas):.2f}")