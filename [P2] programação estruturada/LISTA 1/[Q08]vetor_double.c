// Crie um programa que armazene 10 números em um vetor A e gere um vetor B cujos elementos consistem no quadrado dos elementos de A.

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main(){

    setlocale(LC_ALL, "Portuguese");

    int vetor_a[10], vetor_b[10], i, n;

    for (i =0; i < 10; i++){
        printf("Digite o %d° valor: ", i+1);
        scanf("%d", &vetor_a[i]); }

    printf("\nVetor A: ");
    for (i = 0; i < 10; i++)
        printf("%d ", vetor_a[i]);
    printf("\n");

    for (i=0; i<10; i++){
        vetor_b[i] = vetor_a[i] * 2;}

    printf("\nVetor B: ");
    for (i = 0; i < 10; i++)
        printf("%d ", vetor_b[i]);
    printf("\n");
}
