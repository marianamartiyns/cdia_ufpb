#include <stdio.h>
#include <string.h>

int main() {
    FILE *arquivo, *saida;
    char linha[100], idade[3], *token;

    arquivo = fopen("exer7.txt", "r");
    saida = fopen("ex7_idades.txt", "w");

    if (arquivo != NULL & saida != NULL)
        printf("Operação realizada com sucesso");
    else
        printf("ERRO!");

    while (fgets(linha, 100, arquivo) != NULL) {
        token = strtok(linha, ",");
        while (token != NULL) {
            strcpy(idade, "");
            token = strtok(NULL, ",");
            if (token != NULL) {
                sscanf(token, "%s", idade);
                fprintf(saida, "%s\n", idade);
            }
        }
    }

    fclose(arquivo);
    fclose(saida);

    return 0;
}
