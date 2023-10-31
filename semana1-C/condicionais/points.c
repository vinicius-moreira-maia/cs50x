#include <stdio.h>
#include <cs50.h>

int main(void)
{
   const int MEU = 2;
   int pontos = get_int("quantos pontos vc perdeu? ");

   if (pontos < MEU)
   {
      printf("perdeu menos pontos que eu\n");
   }
   else if(pontos > MEU)
   {
      printf("perdeu mais pontos que eu\n");
   }
   else
   {
      printf("perdeu o mesmo número de pontos que eu\n");
   }
}