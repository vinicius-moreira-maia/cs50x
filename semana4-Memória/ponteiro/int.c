#include <stdio.h>

int main(void)
{
    int x = 7;
    int *px = &x;

    int z = x;
    int *pz = &z;

    z = z + 3;

    printf("%i\n", x);
    printf("%i\n", z);

    printf("%p\n", px);
    printf("%p\n", pz);
}