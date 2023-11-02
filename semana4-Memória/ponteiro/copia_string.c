#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int main(void)
{
    // para copiar strings há a função strcpy()

    char *s = get_string("nome: ");
    char *t = malloc(strlen(s) + 1);

    if (t == NULL) // NULL é um ponteiro que aponta para 0 bits, ou seja, não há endereço para apontar
    {
        return 1;
    }


    strcpy(t, s);

    // checando se a string 't' possui de fato um tamanho antes de converter o primeiro caractere
    if (strlen(t) > 0)
    {
        t[0] = toupper(t[0]);
    }

    /*int tam = strlen(s) + 1;

    for (int i = 0; i < tam; i++)
    {
        t[i] = s[i];
    }*/

    t[0] = toupper(t[0]);
    printf("s: %s\n", s);
    printf("t: %s\n", t);

    free(t);
}