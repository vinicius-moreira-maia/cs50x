#include <stdio.h>

void swap(int a, int b);

int main(void)
{
    int a = 3;
    int b = 5;

    printf("a: %i, b: %i\n", a, b);

    swap(a , b); // cópias são passadas (passagem por valor)

    // printf("a: %i, b: %i\n", a, b); -> mostra os mesmos valores de a e b
}

void swap(int a, int b)
{
   int temp = a;
   a = b;
   b = temp;
   printf("a: %i, b: %i\n", a, b); // agora dá certo, pq manipulei as cópias dos valores localmente
}
