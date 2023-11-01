#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    string s = get_string("Antes: ");
    int n = strlen(s); // string.h
    printf("Depois: ");

    for (int i = 0; i < n; i++)
    {
        printf("%c", toupper(s[i])); // string.h
    }

    printf("\n");
}