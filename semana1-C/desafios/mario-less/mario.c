#include <cs50.h>
#include <stdio.h>

void cria_tijolos(int alt);
void cria_piramide(int alt);

int main(void)
{
    int a;
    
    // input do usuário
    while (true)
    {
        a = get_int("Altura: ");
        if (a >= 1 && a <= 8)
        {
            break;
        }
    }

    cria_piramide(a);
}

void cria_tijolos(int tij)
{
    for (int i = 0; i <= tij; i++)
    {
        printf("#");
    }
    printf("\n");
}

// 2 loops aninhados que desenham uma piramide invertida
void cria_piramide(int alt)
{
    int tijolos = 0;
    // colunas
    for (int i = alt; i > 0; i--)
    {
       // linhas (j > 1 para desenhar um caractere a menos em cada linha)
       for (int j = i; j > 1; j--)
       {
          printf(" ");
       }
       cria_tijolos(tijolos);
       // contador para imprimir os tijolos conforme o valor vai sendo acrescido
       tijolos ++;
    }
}