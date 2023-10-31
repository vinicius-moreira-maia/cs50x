#include <stdio.h>
#include <cs50.h>

int main(void)
{
   int n = get_int("N: ");

   /*
        if (n >= 0)
        {
            res = "positivo";
        }
        else
        {
            res = "negativo";
        }
   */

   string res = (n >= 0) ? "positivo": "negativo";

   printf("%s\n", res);
}