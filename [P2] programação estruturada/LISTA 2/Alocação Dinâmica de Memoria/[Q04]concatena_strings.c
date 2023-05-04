#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* concatena_strings(char** strings, int n){

    int tamanho_total = 0, posicao, i, tamanho_atual;
    for (int i = 0; i < n; i++) {
        tamanho_total += strlen(strings[i]);
    }

    char* resultado = (char*) malloc((tamanho_total + 1) * sizeof(char));

    posicao = 0;
    for (i = 0; i < n; i++) {

        tamanho_atual = strlen(strings[i]);
        strncpy(resultado + posicao, strings[i], tamanho_atual);
        posicao += tamanho_atual;
    }
    resultado[tamanho_total] = '\0';

    return resultado;
}

int main() {

    char* array[] = {"Olá, ", "mundo!", " Como ", "vai?"};

    int n = sizeof(array) / sizeof(char*);

    char* resultado = concatena_strings(array, n);

    printf("%s\n", resultado);
    free(resultado);
    return 0;
}
