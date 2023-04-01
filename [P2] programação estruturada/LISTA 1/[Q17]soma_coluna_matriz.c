/*  Faça um programa que leia uma matriz 3x4 de inteiros e calcule a soma dos elementos de
cada coluna, armazenando o resultado da soma em um vetor de 4 elementos. Por fim, o
programa deverá exibir o conteúdo de tal vetor. */

#include <stdio.h>

int main() {

    int i, j, matriz[3][4], vetor_soma[4] = {0, 0, 0, 0};

    printf("\nDigite os elementos da matriz: ");
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 4; j++) {
            scanf("%d", &matriz[i][j]);
            vetor_soma[j] += matriz[i][j]; } };

    printf("\nMatriz:\n");
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 4; j++) {
            printf("%d ", matriz[i][j]); }
        printf("\n"); }

    printf("\n\nVetor de soma das colunas: \n");
    for (j = 0; j < 4; j++) {
        printf("%d ", vetor_soma[j]);
    }
    printf("\n");
}
