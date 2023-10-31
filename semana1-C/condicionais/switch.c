#include <stdio.h>
#include <cs50.h>

int main(void)
{
   char n = get_int("N: ");

   switch(n)
   {
    case 1:
    case 2:
    case 3:
       printf("3\n");
    default:
       printf("^^\n");
   }
}