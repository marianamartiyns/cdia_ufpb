// Iterativo � um termo que se refere a um processo ou algoritmo que utiliza repeti��es ou loops para executar uma sequ�ncia de a��es.

#include <stdio.h>

// Implementa��o da busca bin�ria recursiva
int buscaBinariaRecursiva(int arr[], int esq, int dir, int alvo) {
    if (esq <= dir) {
        int meio = esq + (dir - esq) / 2;

        if (arr[meio] == alvo)
            return meio;

        if (arr[meio] < alvo)
            return buscaBinariaRecursiva(arr, meio + 1, dir, alvo);

        return buscaBinariaRecursiva(arr, esq, meio - 1, alvo);
    }

    return -1; // Elemento n�o encontrado
}

// Implementa��o da busca bin�ria iterativa
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

    return -1; // Elemento n�o encontrado
}

int main() {
    int arr[] = {2, 4, 6, 8, 10, 12, 14, 16, 18, 20};
    int tamanho = sizeof(arr) / sizeof(arr[0]);
    int alvo = 12;

    // Busca bin�ria recursiva
    int indiceRecursivo = buscaBinariaRecursiva(arr, 0, tamanho - 1, alvo);
    if (indiceRecursivo != -1)
        printf("Encontrado (recursivo) no �ndice: %d\n", indiceRecursivo);
    else
        printf("N�o encontrado (recursivo)\n");

    // Busca bin�ria iterativa
    int indiceIterativo = buscaBinariaIterativa(arr, tamanho, alvo);
    if (indiceIterativo != -1)
        printf("Encontrado (iterativo) no �ndice: %d\n", indiceIterativo);
    else
        printf("N�o encontrado (iterativo)\n");

    return 0;
}
