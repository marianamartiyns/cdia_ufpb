#include <stdio.h>

int main() {

    FILE *arquivo;
    arquivo = fopen("exemplo_exer01.txt", "w");

    fprintf(arquivo, "É muito bom aprender linguagem de programação C!");

    if (arquivo != NULL)
        printf("\nArquivo Criado com sucesso");
    else
        printf("\bO arquivo não foi criado");

    fclose(arquivo);
    return 0;
}

