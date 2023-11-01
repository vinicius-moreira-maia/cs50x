#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int n = get_int("N° de pontos: ");
    int pontos[n];

    for (int i = 0; i < n; i++)
    {
        pontos[i] = get_int("Pontos: ");
    }

    // dividido por 4.0 pois o resultado da divisão de inteiros é um float
    printf("Média dos pontos: %f\n", (pontos[0] + pontos[1] + pontos[2] + pontos[3]) / 4.0);
}