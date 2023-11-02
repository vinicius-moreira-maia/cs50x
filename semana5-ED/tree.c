#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
   int num;
   struct node *left;
   struct node *right;
}
node;

void print_tree(node *root);
void search_tree(node *tree, int num);
void free_tree(node *root);

int main(void)
{
    // criando o ponteiro da raiz da árvore
    node *tree = NULL;

    // adiciona número
    node *n = malloc(sizeof(node));
    if (n == NULL)
    {
        return 1;
    }
    n -> left = NULL;
    n -> right = NULL;
    n -> num = 2;
    tree = n;

    // adiciona número
    n = malloc(sizeof(node));
    if (n == NULL)
    {
        free_tree(tree);
        return 1;
    }
    n -> num = 1;
    n -> left = NULL;
    n -> right = NULL;
    tree -> left = n;

    // adiciona número
    n = malloc(sizeof(node));
    if (n == NULL)
    {
        free_tree(tree);
        return 1;
    }
    n -> left = NULL;
    n -> right = NULL;
    n -> num = 3;
    tree -> right = n;

    print_tree(tree);
    free_tree(tree);
    return 0;
}

// liberar, recursivamente, primeiro os filhos depois os pais
void free_tree(node *root)
{
  if (root == NULL)
  {
    return;
  }
  free_tree(root -> left);
  free_tree(root -> right);
  free(root);
}

// exibir, recursivamente, primeiro os elementos à esquerda, depois o elemento pai e depois os da direita
void print_tree(node *root)
{
  if (root == NULL)
  {
     return;
  }
  print_tree(root -> left); // esquerda
  printf("%i\n", root -> num); // centro (o próprio elemento)
  print_tree(root -> right); // direita
}

// busca binária
void search_tree(node *tree, int number)
{
    if (tree == NULL)
    {
        return 0; // 0 é false em C
    }
    else if (number < tree -> num)
    {
        return search_tree(tree -> left, number);
    }
    else if (number > tree -> num)
    {
        return search_tree(tree -> right, number);
    }
    else if (number == tree -> num)
    {
        return 1; // o que não é 0 em C é true
    }
}