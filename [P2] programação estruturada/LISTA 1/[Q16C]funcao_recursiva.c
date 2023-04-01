#include <stdio.h>
#include <locale.h>

int busca_elemento(int vetor[], int tamanho, int elemento, int index) {

    if (index == tamanho) {
        return -1; }

    if (vetor[index] == elemento) {
        return index; }

    return busca_elemento(vetor, tamanho, elemento, index + 1);
}


int main() {

    setlocale(LC_ALL, "Portuguese");
    int busca_elemento(int vetor[], int tamanho, int elemento, int index);
    int tamanho, i, elemento, posicao, MAX = 100;

    printf("\nDigite o tamanho do vetor: ");
    scanf("%d", &tamanho);

    int vetor[MAX];
    for (i = 0; i < tamanho; i++) {
        printf("\nDigite o %dº elemento do vetor: ", i+1);
        scanf("%d", &vetor[i]);
    }

    printf("\nDigite o elemento que deseja buscar: ");
    scanf("%d", &elemento);

    posicao = busca_elemento(vetor, tamanho, elemento, 0);

    if (posicao == -1) {
        printf("\nElemento não encontrado no vetor.\n");
    } else {
        printf("\nElemento encontrado na %dª posição do vetor.\n", posicao);
    }
}
