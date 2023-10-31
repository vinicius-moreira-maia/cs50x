#include <cs50.h>
#include <stdio.h>

void cria_tijolos(int alt);
void cria_piramide(int alt);
void cria_espacos(void);

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
}

void cria_piramide(int alt)
{
    int tijolos = 0;
    // colunas
    for (int i = alt; i > 0; i--)
    {
       // linhas
       for (int j = i; j > 1; j--)
       {
          printf(" ");
       }
       // exemplo perfeito de como é importante modularizar/abstrair os programas que eu for criar
       cria_tijolos(tijolos);
       cria_espacos();
       cria_tijolos(tijolos);
       tijolos ++;
       printf("\n");
    }
}

void cria_espacos(void)
{
   for (int i = 0; i < 2; i++)
   {
      printf(" ");
   }
}