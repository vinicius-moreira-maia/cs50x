#include <cs50.h>
#include <stdio.h>

bool checa_soma(long num);
bool checa_tamanho(long num);
string checa_bandeira(long num);
int tam_i = 0; // variável para usar em mais de uma função

int main(void)
{
    long numero = get_long("Number: ");
    bool soma = checa_soma(numero);
    bool tam = checa_tamanho(numero);
    string bandeira = checa_bandeira(numero);

    if (soma && tam)
    {
         printf("%s", bandeira);
    }
    else
    {
         printf("INVALID\n");
    }
}

string checa_bandeira(long num)
{
    long x = num; // x para testar e guardar o valor se começar com número de um dígito (4, no caso)
    long y = num; // y para testar e guardar o valor se começar com número de 2 dígitos

    do
    {
        x /= 10;
    }
    while(x > 10);

    do
    {
        y /= 10;
    }
    while(y > 100);

    // lembrar que operadores lógicos são binários (usar parênteses corretamente)
    if (x == 4 && (tam_i == 13 || tam_i == 16))
    {
        return "VISA\n";
    }else if((y == 34 || y == 37) && tam_i == 15)
    {
        return "AMEX\n";
    }else if((y == 51 || y == 52 || y == 53 || y == 54 || y == 55) && tam_i == 16)
    {
        return "MASTERCARD\n";
    }
    else
    {
        return "INVALID\n";
    }
}

bool checa_tamanho(long num)
{
   do
   {
      num /= 10;
      tam_i++; // aqui o tamanho, em dígitos, do número é contado
   }
   while(num > 1);

   if (tam_i == 15 || tam_i ==16 || tam_i == 13)
   {
     return true;
   }
   else
   {
     return false;
   }
}

bool checa_soma(long num)
{
    int resto = 0;
    int i = 0;
    int total = 0;
    int soma_parcial = 0;
    int aux_dec = 0;
    float aux_intf = 0.0;
    int aux_int = 0;
    int total2 = 0;

    do
    {
      resto = num % 10; // utilizando sempre o último dígito da direita para esquerda
      num /= 10;
      num = (long)num; // retirar a parte inteira (que é bem grande)
      soma_parcial = resto * 2;

      // para dígitos em posições ímpares (de trás para frente)
      if (i % 2 != 0)
      {
          // separar em 2 dígitos caso seja um número maior que 10
          if (soma_parcial >= 10)
          {
             aux_dec = soma_parcial % 10; // guardar a parte decimal (em forma de inteiro)
             aux_intf = (float)soma_parcial / (float)10; // guardando o valor decimal da divisão por 10
             aux_int = (int)aux_intf; // retirando a parte inteira
             total = total + aux_dec + aux_int; // somando os dígitos com o total
          }
          else
          {
             total = total + soma_parcial;
          }
      }
      else // para dígitos em posições pares (de trás para frente)
      {
         total2 += resto;
      }
      i++;
    }
    while(num > 1);

    // somando o total de todos os dígitos segundo o algoritmo "Luhn's Algorithm"
    int total_vdd = total + total2;
    total_vdd = total_vdd % 10;

    // checando se o segundo dígito da soma é zero
    if (total_vdd == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}
