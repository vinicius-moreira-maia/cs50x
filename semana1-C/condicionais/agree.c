#include <stdio.h>
#include <cs50.h>

int main(void)
{
   char r = get_char("Você concorda? ");

   if(r == 'y' || r == 'Y')
   {
      printf("sim\n");
   }
   else if(r == 'n' || r == 'N')
   {
      printf("não\n");
   }
   else
   {
      printf("resposta inválida\n");
   }
}