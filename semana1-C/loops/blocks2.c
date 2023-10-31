#include <cs50.h>
#include <stdio.h>

void cria_blocos(int tam);

int main(void)
{
    int n;
    do
    {
       n = get_int("Tamanho: ");
    }
    while (n < 1);

    cria_blocos(n);
}

void cria_blocos(int tam)
{
    // linha
    for (int i = 0; i < tam; i++)
    {
        // coluna
        for (int j = 0; j < tam; j++)
        {
            printf("#");
        }
        // ir para a próxima linha
        printf("\n");
    }
}