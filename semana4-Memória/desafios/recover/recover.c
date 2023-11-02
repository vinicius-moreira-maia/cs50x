#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <cs50.h>

// definindo o tipo BYTE
typedef uint8_t  BYTE;

// definindo a constante dos blocos de bytes
const int  BLOCK_SIZE = 512;

// função para validar se é jpeg ou não
bool isJpeg(BYTE buffer[]);

int main(int argc, char *argv[])
{
    // checando os argumentos de entrada
    if (argc != 2)
    {
        printf("Usage: ./recover card.raw\n");
        return 1;
    }

    // abrindo o arquivo .raw
    FILE *raw_file = fopen(argv[1], "r");

    // exceção para a entrada do arquivo .raw
    if (raw_file == NULL)
    {
        printf("Could not open file.\n");
        return 1;
    }

    BYTE buffer[BLOCK_SIZE];
    int i = 0;
    FILE *imagem = NULL;
    bool jpeg = false;

    while (fread(&buffer, sizeof(BYTE), BLOCK_SIZE, raw_file) == BLOCK_SIZE)
    {
       if (isJpeg(buffer))
       {
             jpeg = true;

             // condição para o primeiro jpeg (executa somente uma vez)
             if (i == 0)
             {
                 char bufferstr[8];

                 // a função sprintf() escreve uma string formatada em um endereço de memória
                 sprintf(bufferstr, "%03i.jpg", i++);
                 imagem = fopen(bufferstr, "w");

                 if (imagem == NULL)
                 {
                    printf("Could not open file.\n");
                    return 1;
                 }

                 // o primeiro parâmetro é o endereço do primeiro elemento do vetor, por isso o '&'
                 fwrite(&buffer, sizeof(BYTE), BLOCK_SIZE, imagem);
             }
             else
             {
                // sempre fechar o que está aberto para "montar" um novo
                fclose(imagem);

                char bufferstr[8];
                sprintf(bufferstr, "%03i.jpg", i++);
                imagem = fopen(bufferstr, "w");

                if (imagem == NULL)
                {
                    printf("Could not open file.\n");
                    return 1;
                }

                fwrite(&buffer, sizeof(BYTE), BLOCK_SIZE, imagem);
             }
       }
       else
       {
            // os primeiros blocos lidos não contém assinaturas de jpegs, se não tiver essa condição dará erro
            if (i >= 0 && jpeg)
            {
                fwrite(&buffer, sizeof(BYTE), BLOCK_SIZE, imagem);
            }
       }
    }
}

bool isJpeg(BYTE buffer[])
{
    if ((((buffer[0] == 0xff) && (buffer[1] == 0xd8)) && (buffer[2] == 0xff)) && ((buffer[3] & 0xf0) == 0xe0))
    {
         return true;
    }
    else
    {
         return false;
    }
}

