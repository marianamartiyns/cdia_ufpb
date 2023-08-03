// Iterativo é um termo que se refere a um processo ou algoritmo que utiliza repetições ou loops para executar uma sequência de ações.

#include <stdio.h>

// Implementação da busca binária recursiva
int buscaBinariaRecursiva(int arr[], int esq, int dir, int alvo) {
    if (esq <= dir) {
        int meio = esq + (dir - esq) / 2;

        if (arr[meio] == alvo)
            return meio;

        if (arr[meio] < alvo)
            return buscaBinariaRecursiva(arr, meio + 1, dir, alvo);

        return buscaBinariaRecursiva(arr, esq, meio - 1, alvo);
    }

    return -1; // Elemento não encontrado
}

// Implementação da busca binária iterativa
int buscaBinariaIterativa(int arr[], int tamanho, int alvo) {
    int esq = 0;
    int dir = tamanho - 1;

    while (esq <= dir) {
        int meio = esq + (dir - esq) / 2;

        if (arr[meio] == alvo)
            return meio;

        if (arr[meio] < alvo)
            esq = meio + 1;
        else
            dir = meio - 1;
    }

    return -1; // Elemento não encontrado
}

int main() {
    int arr[] = {2, 4, 6, 8, 10, 12, 14, 16, 18, 20};
    int tamanho = sizeof(arr) / sizeof(arr[0]);
    int alvo = 12;

    // Busca binária recursiva
    int indiceRecursivo = buscaBinariaRecursiva(arr, 0, tamanho - 1, alvo);
    if (indiceRecursivo != -1)
        printf("Encontrado (recursivo) no índice: %d\n", indiceRecursivo);
    else
        printf("Não encontrado (recursivo)\n");

    // Busca binária iterativa
    int indiceIterativo = buscaBinariaIterativa(arr, tamanho, alvo);
    if (indiceIterativo != -1)
        printf("Encontrado (iterativo) no índice: %d\n", indiceIterativo);
    else
        printf("Não encontrado (iterativo)\n");

    return 0;
}
