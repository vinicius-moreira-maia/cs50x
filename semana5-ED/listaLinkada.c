#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int num;
    struct node *next;
}
node;

int main(void)
{
   // lista de tamanho 0
   node *list = NULL;

   // primeiro nó
   node *n = malloc(sizeof(node));
   if (n == NULL)
   {
      return 1;
   }
   n -> num = 1;
   n -> next = NULL;
   list = n;

   // segundo nó
   n = malloc(sizeof(node));
   if (n == NULL)
   {
      // é necessário liberar a memória antes de encerrar
      free(list); // somente list, pois list é o ponteiro para o único nó até agora
      return 1;
   }
   n -> num = 2;
   n -> next = NULL;
   list -> next = n;

   // terceiro nó
   n = malloc(sizeof(node));
   if (n == NULL)
   {
      // é necessário liberar a memória antes de encerrar
      free(list -> next); // agora é necessário liberar o endereço contido no primeiro nó antes de liberar o endereço da lista
      free(list);
      return 1;
   }
   n -> num = 3;
   n -> next = NULL;
   list -> next -> next = n;

   // exibir a lista linkada
   for (node *temp = list; temp != NULL; temp = temp -> next)
   {
       printf("%i\n", temp -> num);
   }

   // liberar o endereço de todos os nós, um após o outro
   while (list != NULL)
   {
      node *temp = list -> next;
      free(list);
      list = temp;
   }

   return 0;
}