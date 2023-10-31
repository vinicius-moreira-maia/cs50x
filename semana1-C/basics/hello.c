#include <stdio.h> // biblioteca padrão
#include <cs50.h> // biblioteca de funções do cs50 (sem ela não teríamos a função "get_string()")

int main(void)
{
   string nome = get_string("Qual é seu nome, camarada? ");
   printf("Oi, %s\n", nome);

   // não é um design muito bom
   // printf("Oi, %s\n", get_string("Qual é seu nome, camarada? "));
}