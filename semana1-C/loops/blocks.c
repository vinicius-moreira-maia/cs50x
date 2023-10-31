#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int n;

    // looop com teste lógico no fim (executa no mínimo uma vez)
    do
    {
       n = get_int("Tamanho: ");
    }
    while (n < 1);

    /*
    -> indução de loop infinito com teste lógico para a condição de saída usando o break
    while (true)
    {
        n = get_int("Tamanho: ");
        if (n < 1)
        {
            break;
        }
    }
    */

    for (int i = 0; i < n; i++) // linha
    {
        for (int j = 0; j < n; j++) // coluna
        {
            printf("#");
        }
        // ir para a próxima linha
        printf("\n");
    }
}