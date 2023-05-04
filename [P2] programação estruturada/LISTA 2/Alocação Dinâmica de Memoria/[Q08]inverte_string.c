#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {

    char str[100];

    printf("\nDigite uma string: ");
    scanf("%s", str);

    int tamanho = strlen(str);
    char* str_invertida = (char*) malloc((tamanho + 1) * sizeof(char));

    for (int i = 0; i < tamanho; i++) {
        str_invertida[i] = str[tamanho - i - 1];
    }
    str_invertida[tamanho] = '\0';

    printf("A string invertida eh: %s\n", str_invertida);

    free(str_invertida);

    return 0;
}
