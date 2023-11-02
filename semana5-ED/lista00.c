// alocação dinâmica para "inserção" de valores em vetores

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    // int lista[3]; -> memória da 'stack'

    // memória da 'heap' (área de memória que malloc() pode usar)
    int *lista = malloc(3 * sizeof(int));

    if (lista == NULL)
    {
         free(lista);
         return 1;
    }

    // quando aloco espaço suficiente, posso assumir que trata-se de um vetor
    // a notação de colchete faz uma aritmética básica com o ponteiro
    lista[0] = 1; // *lista = 1;
    lista[1] = 2; // *(lista + 1) = 2;
    lista[2] = 3; // *(lista + 2) = 3;

    // int *temp = malloc(4 * sizeof(int));
    int *temp = realloc(lista, 4 * sizeof(int));

    if (temp == NULL)
    {
       free(lista);
       return 1;
    }

    // com realloc() não preciso mais copiar os elementos
    /*for (int i = 0; i < 3; i++)
    {
        temp[i] = lista[i];
    }*/

    temp[3] = 4;

    lista = temp; // lista agora aponta para temp

    for (int i = 0; i < 4; i++)
    {
        printf("%i\n", lista[i]);
    }

    // liberando após o resultado obtido
    free(lista);
    return 0;
}