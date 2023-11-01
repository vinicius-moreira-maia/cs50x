#include <stdio.h>
#include <cs50.h>
#include <string.h>

int main(void)
{
    string s = get_string("Nome: ");

    int n = strlen(s);

    printf("Saída: ");

    for (int i = 0; i < n; i++)
    {
         printf("%c", s[i]);
    }

    printf("\n");
}