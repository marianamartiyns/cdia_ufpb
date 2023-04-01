#include <stdio.h>
#include <locale.h>

void crescente(int vetor[], int tamanho) {

    int i, j, temp;
    for (i = 0; i < tamanho - 1; i++) {
        for (j = 0; j < tamanho - i - 1; j++) {
            if (vetor[j] > vetor[j+1]) {
                temp = vetor[j];
                vetor[j] = vetor[j+1];
                vetor[j+1] = temp;
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
        printf("znDigite o %dº elemento do vetor: ", i+1);
        scanf("%d", &vetor[i]);}

    crescente(vetor, tamanho);

    printf("\nVetor ordenado em ordem crescente:\n");
    for (i = 0; i < tamanho; i++) {
        printf("%d ", vetor[i]);
    }
    printf("\n");
}
