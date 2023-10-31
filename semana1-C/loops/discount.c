#include <stdio.h>
#include <cs50.h>

float desconto(float p, int d);

int main(void)
{
    // a entrada de um float pode ser um inteiro
    float preco = get_float("Preço: ");
    int desc = get_int("Desconto: ");
    float res = desconto(preco, desc);

    // %.2f -> mostra com 2 casas decimais
    printf("valor com desconto: %.2f\n", res);
}

// criar uma variavel somente para armazenar a operação e retornar o resultado não faz muito sentido, pois esta variável não será usada em outro lugar (por ser local da função desconto())
float desconto(float p, int d)
{
   // .75 ou 0.75 ou 75 / 100 (75 % de desconto)
   return p * (100 - d) / 100;
}