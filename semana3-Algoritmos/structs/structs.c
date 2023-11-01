#include <stdio.h>
#include <cs50.h>
#include <string.h>

typedef struct // struct = registro
{
   string nome;
   string time;
   int camisa;
}
jogador;

int main(void)
{
    jogador atacante[2];

    atacante[0].nome = "Ronaldo";
    atacante[1].nome = "Ronaldinho";

    atacante[0].time = "Real Madrid";
    atacante[1].time = "Barcelona";

    atacante[0].camisa = 9;
    atacante[1].camisa = 10;

    for (int i = 0; i < 2; i++)
    {
        if (strcmp(atacante[i].time, "Barcelona") == 0)
        {
            printf("Jogador: %s, Time: %s, Camisa: %i\n", atacante[i].nome, atacante[i].time, atacante[i].camisa);
            return 0;
        }
    }

    printf("Não existem jogadores desse time!\n");
    return 1;
}