#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

void codifica(string t, string c);
bool checa_chave(string s);
bool checa_tam(string s);
bool checa_alf(string s);
bool checa_repeticao(string s);

int main(int argc, string argv[])
{
  string chave = argv[1];

  if (argc != 2)
  {
      printf("quantidade inválida de caracteres\n");
      return 1;
  }

  if (checa_chave(chave) == false)
  {
      printf("chave inválida\n");
      return 1;
  }

  string texto = get_string("plaintext: ");
  codifica(texto, chave);
  return 0;
}

bool checa_chave(string s)
{
   if (checa_tam(s) && checa_alf(s) && checa_repeticao(s))
   {
        return true;
   }
   else
   {
        return false;
   }
}

bool checa_tam(string s)
{
   int n = strlen(s);
   if (n == 26)
   {
      return true;
   }
   else
   {
      return false;
   }
}

bool checa_alf(string s)
{
    int n = strlen(s);

    for (int i = 0; i < n; i++)
    {
        if (isalpha(s[i]) == 0)
        {
            return false;
        }
    }

    return true;
}

bool checa_repeticao(string s)
{
    int n = strlen(s);

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++) // se eu comparar um valor com ele mesmo sempre dará false, por isso o 'j = i+1'
        {
            if ((int) toupper(s[i]) == (int) toupper(s[j]))
            {
                 return false;
            }
        }
    }
    
    return true;
}

void codifica(string t, string c)
{
    // tamanho da string que desejo converter
    int tam_t = strlen(t);

    // string com as 26 letras do alfabeto
    string a = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

    // tamanho da string do alfabeto
    int tam_a = strlen(a);

    // array com o mesmo tamanho da string recebida como parâmetro para guardar os índices dos valores a serem convertidos
    int indices[tam_t];

    // preenchendo o array 'indices' com os indices dos caracteres do texto 't' recebido, de acordo com a posição na string de alfabeto 'a'
    for (int i = 0; i < tam_t; i++)
    {
        for (int j = 0; j < tam_a; j++)
        {
            if ((int) toupper(t[i]) == (int) a[j])
            {
                indices[i] = j;
                break;
            }
            else
            {
                indices[i] = -1;
            }
        }
    }

    // de acordo com os valores do array 'indices' aqui eu armazeno em um novo vetor 'num_to_code' os valores correspondentes na string que contém o código (chave)
    char num_to_code[tam_t];
    for (int i = 0; i < tam_t; i++)
    {
       if (indices[i] != -1)
       {
           if (islower(t[i]) != 0)
           {
              num_to_code[i] = tolower(c[indices[i]]);
           }
           else
           {
              num_to_code[i] = toupper(c[indices[i]]);
           }
       }
       else
       {
           num_to_code[i] = t[i];
       }
    }

    // imprimindo o resultado como efeito colateral ('side effect'), e não como retorno (até agora não sei retornar um array em C)
    printf("ciphertext: ");
    for (int i = 0; i < tam_t; i++)
    {
       printf("%c", num_to_code[i]);
    }
    printf("\n");
}