#include <cs50.h>
#include <stdio.h>
#include <string.h>

#define MAX 9

typedef struct
{
    string name;
    int votes;
}
candidate;

candidate candidates[MAX]; // vetor de registros

int candidate_count;

bool vote(string name);
void print_winner(void);

int main(int argc, string argv[])
{
    // Checando a quantidade de entradas via terminal, se menor que 2 é pra encerrar
    if (argc < 2)
    {
        printf("Usage: plurality [candidate ...]\n");
        return 1;
    }

    // se a quantidade de candidatos for maior que 9 (constante MAX), encerrar
    candidate_count = argc - 1;
    if (candidate_count > MAX)
    {
        printf("Maximum number of candidates is %i\n", MAX);
        return 2;
    }

    // adicionar os candidatos no array
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i].name = argv[i + 1];
        candidates[i].votes = 0;
    }

    // usuário entra com o número de eleitores
    int voter_count = get_int("Number of voters: ");

    // contabilizando os votos
    for (int i = 0; i < voter_count; i++)
    {
        string name = get_string("Vote: ");

        if (!vote(name))
        {
            printf("Invalid vote.\n");
            return 3;
        }
    }

    print_winner();
    return 0;
}


// checando se o voto é válido e adicionando o voto ao candidato
bool vote(string name)
{
    for (int i = 0; i < candidate_count; i++)
    {
        if (strcmp(candidates[i].name, name) == 0)
        {
            candidates[i].votes++;
            return true;
        }
    }
    return false;
}

// Contabilizando e mostrando o vencedor
void print_winner(void)
{
    // Aplicando Selection Sort no vetor de candidatos
    for (int i = 0; i < candidate_count; i++)
    {
        int indice_menor = i;
        for (int j = i + 1; j < candidate_count; j++)
        {
             if (candidates[j].votes < candidates[indice_menor].votes)
             {
                indice_menor = j;

                candidate temp = candidates[indice_menor];
                candidates[indice_menor] = candidates[i];
                candidates[i] = temp;
             }
        }
    }

    int qtd_votos_venc = candidates[candidate_count - 1].votes;

    // Aplicando Busca Linear para printar o(s) Vencedor(es)
    for (int i = candidate_count - 1; i >= 0; i--)
    {
        if (candidates[i].votes == qtd_votos_venc)
        {
             printf("%s\n",candidates[i].name);
        }
    }
}