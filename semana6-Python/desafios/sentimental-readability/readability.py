from cs50 import get_string

def main():

    texto = get_string("Text: ")

    l = n_letras(texto)
    p = n_palavras(texto)
    s = n_sentencas(texto)

    print(grade(l, p, s))

def n_letras(texto):
    qtd = 0
    for letra in texto:
        if letra.isalpha():
            qtd += 1
    return qtd

def n_palavras(texto):
    qtd = 1
    for espaco in texto:
        if espaco.isspace():
            qtd += 1
    return qtd

def n_sentencas(texto):
    qtd = 0
    for pontuacao in texto:
        if pontuacao in ".!?":
            qtd += 1
    return qtd

def grade(letras, palavras, sentencas):
    l = letras / palavras * 100
    s = sentencas / palavras * 100
    cli = 0.0588 * l - 0.296 * s - 15.8

    if cli >= 16:
        return "Grade 16+"
    elif cli < 1:
        return "Before Grade 1"
    else:
        return f"Grade {round(cli)}"

main()
