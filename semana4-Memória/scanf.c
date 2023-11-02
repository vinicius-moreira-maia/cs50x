#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int x; // a alocação aqui já funciona, pois todo inteiro possui 4 bytes
    printf("x: ");
    scanf("%i", &x);
    printf("x: %i\n", x);

    char *s;
    // espaço de memória da 'heap'
    s = malloc(4); // get_string() do cs50.c lida com a necessária alocação dinâmica de bytes para strings
    printf("s: ");
    scanf("%s", s);
    printf("s: %s\n", s);

    // espaço de memória da 'stack'
    char nome[4];  // aqui a alocação é automática, pois 4 chars já reservam 4 bytes
    printf("s: ");
    scanf("%s", nome);
    printf("s: %s\n", nome);
}