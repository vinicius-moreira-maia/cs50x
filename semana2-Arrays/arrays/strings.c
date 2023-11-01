#include <stdio.h>
#include <cs50.h>
#include <string.h>

int string_length(string s);

int main(void)
{
    string s = get_string("Nome: ");

    int tam_string = string_length(s);
    int tam_string2 = strlen(s);

    // printf("%i %i %i %i\n", s[0], s[1], s[2], s[3]);

    printf("Minha função: %i\n", tam_string);
    printf("String.c: %i\n", tam_string2);
}

int string_length(string s)
{
    int i = 0;

    while (s[i] != '\0')
    {
       i++;
    }
    return i;
}