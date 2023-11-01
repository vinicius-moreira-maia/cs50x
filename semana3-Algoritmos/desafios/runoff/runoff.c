// COMENTADO E REVISADO

#include <cs50.h>
#include <stdio.h>
#include <string.h>

#define MAX_VOTERS 100
#define MAX_CANDIDATES 9

// ranking 'j' de candidatos (CANDIDATES) para cada eleitor 'i' (VOTERS)
int preferences[MAX_VOTERS][MAX_CANDIDATES];

typedef struct
{
    string name;
    int votes;
    bool eliminated;
}
candidate;

candidate candidates[MAX_CANDIDATES];

int voter_count;
int candidate_count;

bool vote(int voter, int rank, string name);
void tabulate(void);
bool print_winner(void);
int find_min(void);
bool is_tie(int min);
void eliminate(int min);

int main(int argc, string argv[])
{
    // a entrada via terminal deve ter 2 ou mais argumentos
    if (argc < 2)
    {
        printf("Usage: runoff [candidate ...]\n");
        return 1;
    }

    // preenchendo o vetor de candidatos (no máximo 9)
    candidate_count = argc - 1;
    if (candidate_count > MAX_CANDIDATES)
    {
        printf("Maximum number of candidates is %i\n", MAX_CANDIDATES);
        return 2;
    }
    
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i].name = argv[i + 1];
        candidates[i].votes = 0;
        candidates[i].eliminated = false;
    }

    // número de eleitores
    voter_count = get_int("Number of voters: ");
    if (voter_count > MAX_VOTERS)
    {
        printf("Maximum number of voters is %i\n", MAX_VOTERS);
        return 3;
    }

    // cada eleitor faz sua lista de preferências de acordo com o nome e número de candidatos cadastrados
    for (int i = 0; i < voter_count; i++)
    {
        for (int j = 0; j < candidate_count; j++)
        {
            string name = get_string("Rank %i: ", j + 1);

            if (!vote(i, j, name))
            {
                printf("Invalid vote.\n");
                return 4;
            }
        }
        printf("\n");
    }

    // continuar até que existam vencedores
    while (true)
    {
        // computar votos para candidatos não eliminados
        tabulate();


        bool won = print_winner();
        if (won)
        {
            break; // caso haja vencedor
        }

        // eliminar quem menos pontuou
        int min = find_min();
        bool tie = is_tie(min);

        // empate, todos vencem
        if (tie)
        {
            for (int i = 0; i < candidate_count; i++)
            {
                if (!candidates[i].eliminated)
                {
                    printf("%s\n", candidates[i].name);
                }
            }
            break;
        }

        // elimina quem tem a menor quantidade de votos
        eliminate(min);

        // resetar a quantidade de votos para fazer recontagem, se necessário
        for (int i = 0; i < candidate_count; i++)
        {
            candidates[i].votes = 0;
        }
    }
    return 0;
}

// checar se o voto é válido (se o candidado existe, assumindo que não há candidatos com nome repetido)
// salvar a ordem de preferência (canditado é referenciado pela posição que ocupa no vetor de candidatos)
bool vote(int voter, int rank, string name)
{
    for (int i = 0; i < candidate_count; i++)
    {
         if (strcmp(candidates[i].name, name) == 0)
         {
            preferences[voter][rank] = i;
            return true;
         }
    }
    return false;
}

// computa votos para candidatos não eliminados
// somente o primeiro na ordem de prerência que não esteja eliminado pontua
void tabulate(void)
{
    for (int i = 0; i < voter_count; i++)
    {
         for (int j = 0; j < candidate_count; j++)
         {
            if (!candidates[preferences[i][j]].eliminated)
            {
                    candidates[preferences[i][j]].votes++;
                    break;
            }
         }
    }
}

// checar se há vencedores
// vence quem tiver mais que a metade do total de votos
bool print_winner(void)
{
    // aplicando selection sort no vetor de candidatos
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

    // verificando se o último candidato tem a maioria dos votos
    int max_votos = candidates[candidate_count - 1].votes;

    if (max_votos > voter_count / 2.0)
    {
        printf("%s\n", candidates[candidate_count - 1].name);
        return true;
    }
    else
    {
        return false;
    }
}

// retornar o número de votos do(s) candidato(s) que menos pontuou
int find_min(void)
{
    // selection sort
    for (int i = 0; i < candidate_count; i++)
    {
        int indice_menor = i;
        for (int j = i + 1; j < candidate_count; j++)
        {
             if (candidates[indice_menor].votes < candidates[j].votes)
             {
                 indice_menor = j;

                 candidate temp = candidates[indice_menor];
                 candidates[indice_menor] = candidates[i];
                 candidates[i] = temp;
             }
        }
    }

    // o primeiro elemento é o que menos pontuou (mesmo que haja pontuação igual nos elementos seguintes)
    int i_min = 0;
    for (int i = 0; i < candidate_count; i++)
    {
        if (!candidates[i].eliminated)
        {
            i_min = i;
            break;
        }
    }
    return candidates[i_min].votes;
}

// checar se há um empate
bool is_tie(int min)
{
    for (int i = 0; i < candidate_count; i++)
    {
          // se o candidato não tiver sido eliminado e se sua quantidade de voto for diferente do voto mínimo, não há empate
          if(!candidates[i].eliminated && candidates[i].votes != min)
          {
              return false;
          }
    }
    return true;
}

// eliminar = setar a variável 'eliminated' para verdadeiro
void eliminate(int min)
{
    for (int i = 0; i < candidate_count; i++)
    {
        if(!candidates[i].eliminated && candidates[i].votes == min)
        {
            candidates[i].eliminated = true;
        }
    }
}