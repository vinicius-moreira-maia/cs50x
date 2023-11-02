// Modifica o volume de um arquivo de áudio

#include <stdint.h> // para inteiros de capacidades que não são exatamente 32 bits (4 bytes)
#include <stdio.h>
#include <stdlib.h>

/*
    Um arquivo WAV é constituído por um cabeçalho de 44 bytes mais amostras de 16
    bits cada (2 bytes). Cada amostra representa o sinal de áudio ao longo do tempo.
    Multiplicar as amostras significa alterar o volume do áudio, por exemplo:
    multiplicar por 2 dobra o volume e por 0.5 diminui pela metade.
*/

// Constante (n° de bytes) para o cabeçalho
const int HEADER_SIZE = 44;

int main(int argc, char *argv[]) // char * = string
{
    // Validando os argumentos da linha de comando
    if (argc != 4)
    {
        printf("Usage: ./volume input.wav output.wav factor\n");
        return 1;
    }

    // Abrindo os arquivos e determinando o fator que alterará o volume das amostras
    FILE *input = fopen(argv[1], "r"); // "r" para read
    if (input == NULL) // NULL é um valor de ponteiro que não aponta para endereço algum
    {
        printf("Could not open file.\n");
        return 1;
    }

    FILE *output = fopen(argv[2], "w"); // "w" para write
    if (output == NULL)
    {
        printf("Could not open file.\n");
        return 1;
    }

    float factor = atof(argv[3]); // pegando o fator do quarto argumento (o 4° é o da posição 3)

    // -> buffer significa armazenamento temporário de dados na memória <-

    // Copiando o cabeçalho de input para output
    uint8_t header[HEADER_SIZE]; // buffer (vetor de 44 posições com 1 byte para cada posição)
    fread(&header, HEADER_SIZE, 1, input); // ler 44 bytes do endereço armazenado em input (ponteiro), uma única vez, para o endereço de header
    fwrite(&header, HEADER_SIZE, 1, output); // escrever 44 bytes do endereço de header, uma única vez, para o endereço contido em output (ponteiro)

    // Lendo as amostras de 16 bits de input e escrevendo em output
    int16_t buffer; // buffer (inteiro de 2 bytes)

    // lembrando que 0 em C é false e 1 é true (no momento em que fread() retornar 0, o loop termina)
    // na condição abaixo eu tento ler somente uma amostra do arquivo 'input' por vez, e a armazeno no mesmo endereço de 'buffer'
    while (fread(&buffer, sizeof(int16_t), 1, input))
    {
         buffer = buffer * factor; // aumentando o volume multiplicando o buffer pelo fator
         fwrite(&buffer, sizeof(int16_t), 1, output); // escrevendo o que há no endereço de buffer no endereço contido em output (uma amostra de 16 bits por vez)
    }

    fclose(input);
    fclose(output);
}
