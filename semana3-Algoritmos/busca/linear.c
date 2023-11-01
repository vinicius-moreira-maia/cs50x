#include <stdio.h>
#include <cs50.h>
#include <string.h>

int main(void)
{
    string nomes[] = {"Vini","Dudu","Neném","Zé","Xuxu","Gatim","Lili"};

    for (int i = 0; i < 7; i++)
    {
        if (strcmp(nomes[i], "Zézim") == 0)
        {
            printf("Achei!\n");
            return 0;
        }
    }
    
    printf("Não achei!\n");
    return 1;
}