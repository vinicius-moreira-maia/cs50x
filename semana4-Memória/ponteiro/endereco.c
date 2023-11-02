#include <stdio.h>

int main(void)
{
   int n = 50;
   int *p = &n;
   printf("%i\n", *p); // apontando para o endereço
   printf("%p\n", p); // exibindo o endereço (não é importante)
}