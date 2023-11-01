#include <cs50.h>
#include <stdio.h>

int main(int argc, string argv[])
{
    // ou seja, se eu não fornecer um segundo argumento, o fato de existir um valor que não é 0 sendo retornado vai fazer com que meu programa encerre prematuramente
    if (argc != 2)
    {
        printf("missing command-line argument\n");
        return 1;
    }
    
    printf("hello, %s\n", argv[1]);
    return 0;
}