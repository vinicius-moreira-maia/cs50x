#include <stdio.h>

int main(void)
{
   char *s = "OI!"; // o mesmo que string = "OI!";
   printf("%p\n", s); // não precisa do &, pois s já é um endereço
   printf("%p\n", &s[0]); // o & é justamente para exibir o endereço de memória
   printf("%p\n", &s[1]);
   printf("%p\n", &s[2]);
   printf("%p\n", &s[3]);

   // os endereços dos caracteres tem a diferença de um byte para o outro, pois trata-se de um array (valores contínuos na memória)
}