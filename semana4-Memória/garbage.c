#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int pontos[3];

    for (int i = 0; i < 3; i++)
    {
        printf("%i\n", pontos[i]); // garbage values irão surgir, já que os valores do array não foram explicitados
    }
}
