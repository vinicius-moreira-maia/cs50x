import csv
import sys
import collections

def main():

    # Checando os argumentos da CLI
    if len(sys.argv) != 3:
        print("Quantidade insuficiente de argumentos.")
        sys.exit(1)

    # Carregando o banco de dados em um DictReader e passando cada linha para uma lista (lista de dicionários)
    lista_bd = []
    with open(sys.argv[1], "r") as dados_str:
        str_dict = csv.DictReader(dados_str)
        for linha in str_dict:
            lista_bd.append(linha)
        # lista que contém os nomes de cada STR
        lista_chaves = str_dict.fieldnames
        lista_chaves.remove("name")

    # lendo o arquivo de sequencia de dna em uma string
    with open(sys.argv[2], "r") as dna:
        seq_dna = dna.readlines()
        string_dna = seq_dna[0]

    # Contagem das sequências
    lista_cont = []
    for str in lista_chaves:
        lista_cont.append(longest_match(string_dna, str))

    # Checando se a sequência bate com alguém do banco de dados
    for linha in lista_bd:
        valores = list(linha.values())
        valores.pop(0)
        for i in range(len(valores)):
            valores[i] = int(valores[i])
        if collections.Counter(valores) == collections.Counter(lista_cont):
            print(linha['name'])
            sys.exit(0)

    print("No match")
    sys.exit(0)

def longest_match(sequence, subsequence):
    """Returns length of longest run of subsequence in sequence."""

    # Initialize variables
    longest_run = 0
    subsequence_length = len(subsequence)
    sequence_length = len(sequence)

    # Check each character in sequence for most consecutive runs of subsequence
    for i in range(sequence_length):

        # Initialize count of consecutive runs
        count = 0

        # Check for a subsequence match in a "substring" (a subset of characters) within sequence
        # If a match, move substring to next potential match in sequence
        # Continue moving substring and checking for matches until out of consecutive matches
        while True:

            # Adjust substring start and end
            start = i + count * subsequence_length
            end = start + subsequence_length

            # If there is a match in the substring
            if sequence[start:end] == subsequence:
                count += 1

            # If there is no match in the substring
            else:
                break

        # Update most consecutive matches found
        longest_run = max(longest_run, count)

    # After checking for runs at each character in seqeuence, return longest run found
    return longest_run

main()
