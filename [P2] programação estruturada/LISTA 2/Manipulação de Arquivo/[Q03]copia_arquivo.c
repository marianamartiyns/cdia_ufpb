#include <stdio.h>

int main() {

    FILE *arquivo_original, *arquivo_copia;
    char caractere;

    arquivo_original = fopen("exer03.txt", "r");
    arquivo_copia = fopen("exer03_copia.txt", "w");

    if (arquivo_original != NULL & arquivo_copia != NULL)
        printf("\nArquivos abertos e copiado com sucesso!\n");

    else
        printf("\nArquivos abertos e copiado sem sucesso!\n");

    while ((caractere = fgetc(arquivo_original)) != EOF) {
        fputc(caractere, arquivo_copia);
    }

    fclose(arquivo_original);
    fclose(arquivo_copia);

    return 0;
}
