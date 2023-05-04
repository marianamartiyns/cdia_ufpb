#include <stdio.h>

int main() {

    FILE *arquivo;
    char linha[100];

    arquivo = fopen("exer04.txt", "r");

    printf("\nFrases que começam com A: \n\n");
    while (fgets(linha, 100, arquivo) != NULL) {
        if (linha[0] == 'a' || linha[0] == 'A') {
            printf("%s", linha);
        }
    }

    fclose(arquivo);

    return 0;
}
