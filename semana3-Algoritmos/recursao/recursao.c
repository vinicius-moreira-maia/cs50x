#include <stdio.h>
#include <cs50.h>

void desenha(int t);

int main(void)
{
    int t = get_int("Tamanho: ");
    desenha(t);
}

void desenha(int t)
{
    if (t <= 0)
    {
        return;
    }

    // uma piramide de tamanho 4 é igual uma piramide de tamanho 3 mais uma linha
    // uma piramide de tamanho t é igual uma piramide de tamanho t - 1 mais uma linha

    // t - 1
    desenha(t-1);

    // mais uma linha
    for (int j = 0; j < t; j++)
    {
        printf("#");
    }
    printf("\n");
}

/*
pilha de chamado:

             desenha(0) // caso base (não há retorno, há efeito colateral)
#            desenha(1)
##           desenha(2)
###          desenha(3)
####         desenha(4)
#####        desenha(5)
retorna 0    main()









*/