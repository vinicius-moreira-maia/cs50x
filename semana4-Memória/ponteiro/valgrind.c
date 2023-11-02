#include <stdio.h>
#include <cs50.h>
#include <stdlib.h>

int main(void)
{
   // alocando 3 vezes o tamanho de um int na memória
   int *x = malloc(3 * sizeof(int));

   // se um int possui 4 bytes, o comando acima aloca 12 bytes, é como se fosse um array de 3 inteiros

   x[0] = 72;
   x[1] = 73;
   x[2] = 33;

   // x[3] = 100 -> ultrapassei o limite, mas não é o suficiente para dar erro

   free(x);

   string nome = "Vinicius";
   printf("%lu\n", sizeof(nome));

}