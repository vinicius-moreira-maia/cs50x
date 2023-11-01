#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int letras(string t);
int palavras(string t);
int sentencas(string t);
int grade(int l, int p, int s);

int main(void)
{
   string texto = get_string("Text: ");

   int qtd_letras = letras(texto);
   int qtd_pal = palavras(texto);
   int qtd_sen = sentencas(texto);
   int nota = grade(qtd_letras, qtd_pal, qtd_sen);

   if (nota >= 16)
   {
        printf("Grade 16+\n");
   }
   else if(nota < 1)
   {
        printf("Before Grade 1\n");
   }
   else
   {
        printf("Grade %i\n", nota);
   }
}

int letras(string t)
{
  int tam = strlen(t);
  int l = 0;

  for (int i = 0; i < tam; i++)
  {
      if (isalpha(t[i]) != 0)
      {
          l ++;
      }
  }

  return l;
}

int palavras(string t)
{
  int tam = strlen(t);
  int p = 0;

  for (int i = 0; i < tam; i++)
  {
      if (isspace(t[i]) != 0)
      {
          p ++;
      }
  }

  // número de palavras é sempre igual o número de espaços + 1
  return p + 1;
}


//33 = !, 46 = ., 63 = ? (ASCII)
int sentencas(string t)
{
  int tam = strlen(t);
  int s = 0;

  for (int i = 0; i < tam; i++)
  {
      if ((int) t[i] == 33 || (int) t[i] == 46 || (int) t[i] == 63)
      {
          s ++;
      }
  }

  return s;
}

int grade(int l, int p, int s)
{
    double lpor100p = l / (double) p * 100.0;
    double spor100p = s / (double) p * 100.0;
    double res = 0.0588 * lpor100p - 0.296 * spor100p - 15.8;
    int grade = round(res);

    return grade;
}