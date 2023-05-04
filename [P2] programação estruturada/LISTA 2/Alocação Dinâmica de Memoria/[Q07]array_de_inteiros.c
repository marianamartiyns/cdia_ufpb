#include <stdio.h>
#include <stdlib.h>

int main() {

    int n, soma, i;
    printf("Digite o tamanho do array: ");
    scanf("%d", &n);

    int* array = (int*) malloc(n * sizeof(int));

    printf("Digite os %d valores do array:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &array[i]);
    }

    soma = 0;
    for (i = 0; i < n; i++) {
        soma += array[i];
    }

    float media = (float) soma / n;

    printf("A media dos valores do array eh %.2f\n", media);

    free(array);

    return 0;
}
