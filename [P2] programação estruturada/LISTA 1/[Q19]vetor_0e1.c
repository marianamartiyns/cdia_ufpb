#include <stdio.h>
#include <locale.h>

void substituiParImpar(int vetor[], int tamanho) {

    int i;
    for (i = 0; i < tamanho; i++) {
        if (vetor[i] % 2 == 0)
            vetor[i] = 1;
        else
            vetor[i] = 0;
    }
}

int main() {

    setlocale(LC_ALL, "Portuguese");

    int vetor_original[10], vetor_copia[10], i;

    for (i = 0; i < 10; i++) {
        printf("\nDigite o %dº elemento do vetor: ", i+1);
        scanf("%d", &vetor_original[i]); }

    for (i = 0; i < 10; i++) {
        vetor_copia[i] = vetor_original[i];
    }

    printf("\nVetor original: ");
    for (i = 0; i < 10; i++)
        printf("%d ", vetor_original[i]);
    printf("\n");

    substituiParImpar(vetor_copia, 10);
    printf("Vetor modificado: ");
    for (i = 0; i < 10; i++) {
        printf("%d ", vetor_copia[i]);
    }
    printf("\n");
}
