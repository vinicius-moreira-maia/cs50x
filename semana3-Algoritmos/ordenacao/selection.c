#include <stdio.h>
#include <cs50.h>

int vetor[] = {6, 5, 78, 5, 444, 3, 2, 9, -1};

void selecao(void);

int main(void)
{
   selecao();

   printf("-------------\n");
   for (int i = 0; i < 9; i++)
   {
      printf("%i\n", vetor[i]);
   }
}

void selecao(void)
{
      int tam = 9;

      for (int i = 0; i < tam ; i++)
      {
         int indice_menor = i; // assumindo que o atual é o menor
         for (int j = i + 1; j < tam; j++) // com o j, eu começo a contar sempre do próximo valor (i + 1)
         {
               if (vetor[j] < vetor[indice_menor]) // se o vetor na pos i + 1 for menor que o vetor na posição i
               {
                     indice_menor = j;

                     // troca (o i com o i + 1)
                     int temp = vetor[indice_menor];
                     vetor[indice_menor] = vetor[i];
                     vetor[i] = temp;
               }
         }
      }

      for (int i = 0; i < 9; i++)
      {
          printf("%i\n", vetor[i]);
      }
   }
