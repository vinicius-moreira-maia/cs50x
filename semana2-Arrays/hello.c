#include <stdio.h>
#include <cs50.h>

int main(void)
{
    string nome = get_string("Nome: ");
    printf("Oi, %s!\n", nome);
}