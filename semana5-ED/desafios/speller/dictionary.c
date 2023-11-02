// Implements a dictionary's functionality

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>

#include "dictionary.h"

// variáveis declaradas
unsigned int indice;
unsigned int cont_word;

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// TODO: Choose number of buckets in hash table
const unsigned int N = 26;

// Hash table
node *table[N];

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
     indice = hash(word);
     // busca em lista linkada
     for (node *temp = table[indice]; temp != NULL; temp = temp -> next)
     {
       if (strcasecmp(word, temp -> word) == 0)
       {
           return true;
       }
     }
     return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // somatório dos valores ASCII de cada caractere da string
    unsigned long total = 0;
    for (int i = 0; i < strlen(word); i++)
    {
        total += tolower(word[i]);
    }

    // resto da divisão do total por 26 (total de letras)
    return total % N;
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    FILE *file = fopen(dictionary, "r");
    if (file == NULL)
    {
        return false;
    }

    char word[LENGTH + 1];
    while (fscanf(file, "%s", word) != EOF)
    {
       node *new_node = malloc(sizeof(node));

       if (new_node == NULL)
       {
           return false;
       }

       strcpy(new_node -> word, word);

       indice = hash(word);

       // ponteiro do novo nó deve apontar primeiro para a "cabeça" da lista
       new_node -> next = table[indice];

       // o novo nó agora vai para a "cabeça" da lista
       table[indice] = new_node;

       // número de palavras no dicionário
       cont_word ++;
    }
    fclose(file);
    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    if (cont_word > 0 )
    {
        return cont_word;
    }
    return 0;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
     for (int i = 0; i < N; i++)
     {
        // cuidado para não perder a referência da lista!
        node *cursor = table[i];
        while (cursor != NULL)
        {
            node *temp = cursor;
            cursor = cursor -> next;
            free(temp);
        }

        if (cursor == NULL)
        {
            return true;
        }
     }
     return false;
}
