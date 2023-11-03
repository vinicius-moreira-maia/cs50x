from cs50 import get_string

s = get_string("sim ou não? ").lower()

# posso comparar strings com == e não há o tipo caractere em Python, é tudo string
# and e or no lugar de || e &&
# strings em python são imutáveis, toda alteração nelas retornará uma cópia, já com a memória automaticamente alocada levando em consideração as mudanças feitas

if s in ["sim", "s"]:
    print("Positivo")
elif s in ["não", "n"]:
    print("Negativo")
else:
    print("Resposta Inválida")