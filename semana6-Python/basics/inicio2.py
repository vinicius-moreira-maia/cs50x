import cs50

# get_int() já lida com as exceções
# caso eu importe toda a biblioteca, preciso referenciá-la nas funções

x = cs50.get_int("x: ")
y = cs50.get_int("y: ")

print(x + y)