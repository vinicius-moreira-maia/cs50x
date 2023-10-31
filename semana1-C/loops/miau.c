#include <stdio.h>
#include <cs50.h>

void miau(int n); // protótipo da função

int main(void){
    miau(3);

    int cont = 1;
    while(cont <= 5)
    {
        printf("%i\n", cont);
        cont++;
    }
}

// o tipo do parâmetro também deve ser indicado
void miau(int n)
{
   for (int i = 0; i < n; i++)
   {
      printf("miau\n");
   }
}