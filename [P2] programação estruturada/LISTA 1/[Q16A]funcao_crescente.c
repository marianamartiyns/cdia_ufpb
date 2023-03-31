#include <stdio.h>
#include <locale.h>

void ordena_vetor(int vetor[], int tamanho) {

    int i, j, temp;
    for (i = 0; i < tamanho - 1; i++) {
        for (j = i + 1; j < tamanho; j++) {

            if (vetor[i] > vetor[j]) {
                temp = vetor[i];
                vetor[i] = vetor[j];
                vetor[j] = temp;
            }
        }
    }
}

int main(){

    setlocale(LC_ALL, "Portuguese");

    int tamanho, i;
    printf("\nDigite o tamanho do vetor: ");
    scanf("%d", &tamanho);

    int vetor[tamanho];
    printf("\nDigite os elementos do vetor: ");

    for (i = 0; i < tamanho; i++) {
        scanf("%d", &vetor[i]); }

    ordena_vetor(vetor, tamanho);

    printf("\nO vetor ordenado em ordem crescente é:\n");
    for (i = 0; i < tamanho; i++) {
        printf("%d ", vetor[i]);}
}
