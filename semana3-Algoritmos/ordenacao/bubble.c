#include <stdio.h>
#include <cs50.h>

int vetor[] = {6, 5, 78, 5, 444, 3, 2, 9, -1};

void bolha(void);

int main(void)
{
   bolha();
}

void bolha(void)
{
        int tam = 9;

        for (int i = 0; i < tam - 1; i++) // menos um, pois o último elemento não tem com o que ser comparado
        {
            for (int j = 0; j < tam - i - 1; j++) // menos i para ir atualizando o tamanho do subarray, e menos um por conta do último elemento
            {
                if (vetor[j] > vetor[j + 1])
                {
                    int temp = vetor[j];  // essa parte de troca de valores tava dando erro quando escrita como outra função
                    vetor[j] = vetor[j + 1];
                    vetor[j + 1] = temp;
                }
            }
        }

        for (int i = 0; i < 9; i++)
        {
            printf("%i\n", vetor[i]);
        }
}

