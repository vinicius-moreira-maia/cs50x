#include <stdio.h>
#include <cs50.h>
#include <string.h>

int main(void)
{
    // FILE é como se fosse um tipo, e fopen é uma função que cria/abre um arquivo, um csv no caso
    FILE *file = fopen("listatel.csv", "a");
    // 'a' significa 'append', ou adicionar valores
    // FILE * -> ponteiro para um arquivo 

    // exceção
    if (!file)
    {
        return 1;
    }

    string nome = get_string("Nome: ");
    string tel = get_string("Telefone: ");

    // escrevendo no arquivo csv
    fprintf(file, "%s%s\n", nome, tel);

    // salvar/fechar o arquivo
    fclose(file);
}
