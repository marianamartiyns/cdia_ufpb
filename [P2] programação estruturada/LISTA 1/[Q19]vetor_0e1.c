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

    // copia vetor_original para vetor_copia
    for (i = 0; i < 10; i++) {
        vetor_copia[i] = vetor_original[i];
    }

    // exibe vetor_original antes da modificacao
    printf("\nVetor original: ");
    for (i = 0; i < 10; i++)
        printf("%d ", vetor_original[i]);

    printf("\n");

    // chama funcao para substituir valores par/impares
    substituiParImpar(vetor_copia, 10);

    // exibe vetor_copia depois da modificacao
    printf("\nVetor modificado: ");
    for (i = 0; i < 10; i++) {
        printf("%d ", vetor_copia[i]);
    }
    printf("\n");

    return 0;
}


