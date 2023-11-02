#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b);

int main(void)
{
    int a = 3;
    int b = 5;

    printf("a: %i, b: %i\n", a, b);

    swap(&a , &b); // passei os endereços das variáveis (passagem por referência)

    printf("a: %i, b: %i\n", a, b);
}

void swap(int *a, int *b) // recebi os endereços e armazenei em ponteiros
{
   int temp = *a; // temp recebe o valor contido no local que '*a' aponta
   *a = *b; // *a recebe o valor que o endereço contido em *b aponta
   *b = temp; // o endereço que *b aponta recebe o valor contido em temp
}
