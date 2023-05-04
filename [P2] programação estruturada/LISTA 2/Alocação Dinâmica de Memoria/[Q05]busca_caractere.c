#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int* posicoes_caractere(char* s, char c, int* tamanho) {

    int n = strlen(s), i ;
    int* resultado = NULL;

    *tamanho = 0;
    for ( i = 0; i < n; i++) {
        if (s[i] == c) {
            *tamanho += 1;
            resultado = (int*) realloc(resultado, (*tamanho) * sizeof(int));
            resultado[*tamanho - 1] = i;
        }
    }
    return resultado;
}

int main() {

    char s[100], c;
    int tamanho;

    printf("Informe uma frase: ");
    fgets(s, sizeof(s), stdin);

    printf("Informe a letra que deseja saber as posições que ela aparece: ");
    scanf("%c", &c);


    int* posicoes = posicoes_caractere(s, c, &tamanho);

    printf("Posições: ");
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", posicoes[i]);
    }
    printf("\n");
    free(posicoes);
    return 0;
}
