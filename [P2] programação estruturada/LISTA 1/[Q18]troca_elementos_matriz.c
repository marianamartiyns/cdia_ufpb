#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main(){

    setlocale(LC_ALL, "Portuguese");

    int i, j, x, y, matriz[3][3];

    printf("\n == Programa que troca os elementos da 2� linha de uma matriz por sua 2� coluna ==\n");

    printf("\nDigite os elementos da matriz: ");
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            scanf("%d", &matriz[i][j]); }}


    //matriz original
    printf("\nMatriz sem altera��o:\n\n");
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            printf("%d ", matriz[i][j]); }
        printf("\n"); }

    printf("\n\nDestacando as Variav�is: \n");
    printf("\nSegunda linha: %d, %d, %d", matriz[1][0], matriz[1][1], matriz[1][2]);
    printf("\nSegunda Coluna: %d, %d, %d", matriz[0][1], matriz[1][1], matriz[2][1]);

    //Salvando as variaveis da linha anterior para mudar as colunas.
    x = matriz[1][0];
    y = matriz[1][2];

    //Trocando a Linha pela Coluna
    matriz[1][0] = matriz[0][1];
    //matriz[1][1] = matriz[1][1];
    matriz[1][2] = matriz[2][1];


    //Trocando a Coluna pela Linha.
    matriz[0][1] = x;
    //matriz[1][1] = matriz[1][1];
    matriz[2][1] = y;

    printf("\n\nMatriz com os elementos da 2� linha e 2� coluna trocados: \n\n");
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            printf("%d ", matriz[i][j]); }
        printf("\n"); }
}
