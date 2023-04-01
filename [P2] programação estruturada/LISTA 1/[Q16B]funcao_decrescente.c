#include <stdio.h>
#include <locale.h>

void decrescente(int vetor[], int tamanho) {

    int i, j, temp;
    for (i = 0; i < tamanho; i++) {
        for (j = i + 1; j < tamanho; j++) {
            if (vetor[i] < vetor[j]) {
                temp = vetor[i];
                vetor[i] = vetor[j];
                vetor[j] = temp;
            }
        }
    }
}

int main() {

    setlocale(LC_ALL, "Portuguese");
    int vetor[100];
    int tamanho, i;

    printf("\nDigite o tamanho do vetor: ");
    scanf("%d", &tamanho);

    for (i = 0; i < tamanho; i++) {
        printf("\nDigite o %dº elemento do vetor: ", i+1);
        scanf("%d", &vetor[i]);}

    decrescente(vetor, tamanho);

    printf("\nVetor ordenado em ordem decrescente:\n");
    for (i = 0; i < tamanho; i++) {
        printf("%d ", vetor[i]);
    }
    printf("\n");
}
