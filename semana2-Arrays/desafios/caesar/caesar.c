#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void caesar(string texto, int chave);
bool checar_chave(string n);

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("quantidade inválida de entradas!\n");
        return 1;
    }

    if (!checar_chave(argv[1]))
    {
        printf("entrada inválida!\n");
        return 1;
    }

    int chave = atoi(argv[1]);
    string texto = get_string("plaintext:  ");
    caesar(texto, chave);
    return 0;
}

bool checar_chave(string n)
{
    int t = strlen(n);
    int cont = 0;

    for (int i = 0; i < t; i++)
    {
         if (isdigit(n[i]) != 0)
         {
            cont ++;
         }
    }

    if (cont == t)
    {
       return true;
    }
    else
    {
       return false;
    }
}

void caesar(string texto, int chave)
{
    int tam_texto = strlen(texto);
    int indices[tam_texto];
    string alfabeto = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    int tam_alfabeto = strlen(alfabeto);

    // preencher o array 'indices' com as posições da string de entrada de acordo com as posições dos caracteres de 'alfabeto'
    for (int i = 0; i < tam_texto; i++)
    {
       for (int j = 0; j < tam_alfabeto; j++)
       {
           if (isalpha(texto[i]) != 0)
           {
                if ((int) toupper(texto[i]) == (int) alfabeto[j])
                {
                    indices[i] = j;
                }
           }
           else
           {
             indices[i] = -1;
           }
       }
    }

    // acrescentando o valor das chaves nos valores do array 'indices', se não forem -1
    for (int i = 0; i < tam_texto; i++)
    {
        if (indices[i] != -1)
        {
            if (indices[i] + chave < tam_alfabeto)
            {
                indices[i] = indices[i] + chave;
            }
            else if (indices[i] + chave >= tam_alfabeto)
            {
                indices[i] = (indices[i] + chave) - tam_alfabeto;
                while (indices[i] >= tam_alfabeto)
                {
                    indices[i] -= tam_alfabeto;
                }
            }
        }
    }

    // preenchendo o array 'resultado' com os caracteres apropriados
    char resultado[tam_texto];
    for (int i = 0; i < tam_texto; i++)
    {
        for (int j = 0; j < tam_alfabeto; j++)
        {
             if (indices[i] != -1)
             {
                 if (indices[i] == j)
                 {
                    if (islower(texto[i]) != 0)
                    {
                         resultado[i] = tolower(alfabeto[j]);
                    }
                    else
                    {
                         resultado[i] = alfabeto[j];
                    }
                 }
             }
             else
             {
                resultado[i] = texto[i];
             }
        }
    }

    // imprimindo o array
    printf("ciphertext: ");
    for (int i = 0; i < tam_texto; i++)
    {
        printf("%c", resultado[i]);
    }
    printf("\n");
}
