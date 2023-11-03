import csv # biblioteca só para arquivos do tipo 'comma separated values'
from cs50 import get_string

# abrindo o arquivo
file = open("listatel.csv", "w") # 'a' para append

nome = get_string("Nome: ")
tel = get_string("Telefone: ")

writer = csv.writer(file) # instanciando um objeto (objeto writer)
writer.writerow([nome, tel]) # usando um método deste objeto

file.close() # fechando o arquivo

nome2 = get_string("Nome: ")
tel2 = get_string("Telefone: ")

# essa estrutura já fecha o arquivo automaticamente
with open("listatel2.csv", "w") as file:
    writer2 = csv.writer(file)
    writer2.writerow([nome2, tel2]) # um método que recebe uma lista com dois valores