def main():

    desenha_piramide(altura())

def altura():

    while True:
        try:
           a = int(input("Height: "))
           if a <= 0 or a >= 9:
                raise ValueError
           else:
                return a
        except ValueError:
           pass

def desenha_piramide(alt):

   i = alt - 1

   j = 1
   
   for _ in range(alt):
      print(" " * i, end = "")
      print("#" * j, end = "")
      print()
      i -= 1
      j += 1

main()