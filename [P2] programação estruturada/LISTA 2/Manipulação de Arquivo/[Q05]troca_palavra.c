#include <stdio.h>
#include <string.h>

#define TAMANHO_MAX 100

int main() {

    FILE *arquivo;
    char linha[TAMANHO_MAX], linha_substituida[TAMANHO_MAX];
    const char *palavra_antiga = "gato";
    const char *palavra_nova = "cachorro";

    arquivo = fopen("exer05.txt", "r+");

    while (fgets(linha, TAMANHO_MAX, arquivo) != NULL) {

        char *posicao = linha;
        while ((posicao = strstr(posicao, palavra_antiga)) != NULL) {

            int pos = posicao - linha;

            strncpy(linha_substituida, linha, pos);
            linha_substituida[pos] = '\0';

            strcat(linha_substituida, palavra_nova);
            strcat(linha_substituida, posicao + strlen(palavra_antiga));

            strcpy(linha, linha_substituida);
            posicao += strlen(palavra_nova);
        }

        fseek(arquivo, -(long)strlen(linha), SEEK_CUR);
        fputs(linha, arquivo);
    }

    fclose(arquivo);

    return 0;
}
