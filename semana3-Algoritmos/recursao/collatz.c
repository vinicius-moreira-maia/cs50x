#include <stdio.h>
#include <cs50.h>

int collatz(int n); // funciona perfeitamente
int collatz_r(int n);

int main(void)
{
    int n = get_int("Num: ");
    int res = collatz_r(n);
    printf("Passos para chegar a 1: %i\n", res);
}

int collatz(int n)
{
    int cont = 0;

    if (n <= 1)
    {
       return cont;
    }
    else
    {
       while (n > 1)
       {
            if (n % 2 == 0)
            {
                n = n / 2;
                cont++;
            }
            else
            {
                n = 3 * n + 1;
                cont++;
            }
       }
    }

   return cont;
}

int collatz_r(int n)
{
    // o caso base é o número 1, portanto, se for maior que 1, sempre vai ser o caso base, que é 1, mais alguma das duas possibilidades, por isso que a generalização dos casos recursivos é dessa forma
    if (n == 1)
    {
        return 0;
    }
    else if (n % 2 == 0)
    {
        return 1 + collatz(n / 2);
    }
    else
    {
        return 1 + collatz(3 * n + 1);
    }
}