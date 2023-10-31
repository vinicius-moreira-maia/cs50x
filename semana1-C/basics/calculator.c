#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // Valor 1
    int x = get_int("X: ");

    // Valor 2
    int y = get_int("Y: ");

    // Resultado
    int z = x + y;

    // Imprimir o resutado
    printf("%i\n", z);
}