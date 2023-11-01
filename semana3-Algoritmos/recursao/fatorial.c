#include <stdio.h>
#include <cs50.h>

int fat(int t);

int main(void)
{
    int n = get_int("Fatorial: ");
    int f = fat(n);
    printf("Fatorial de %i é %i\n", n, f);
}

int fat(int n)
{
    if (n == 0)
    {
        return 1;
    }

   return n * fat(n - 1);
}