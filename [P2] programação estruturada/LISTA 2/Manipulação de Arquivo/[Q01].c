#include <stdio.h>

int main() {

    FILE *arquivo;
    arquivo = fopen("exemplo_exer01.txt", "w");

    fprintf(arquivo, "� muito bom aprender linguagem de programa��o C!");

    if (arquivo != NULL)
        printf("\nArquivo Criado com sucesso");
    else
        printf("\bO arquivo n�o foi criado");

    fclose(arquivo);
    return 0;
}

