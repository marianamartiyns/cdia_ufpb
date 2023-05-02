#include <stdlib.h>
#include <locale.h>

int* somar_arrays(int* a, int* b, int N) {

  int* resultado = (int*)malloc(N * sizeof(int));

  for (int i = 0; i < N; i++) {
    resultado[i] = a[i] + b[i];
  }

  return resultado;
}

int main() {

    setlocale(LC_ALL, "");
    int a[] = {1, 2, 3, 4, 5};
    int b[] = {10, 20, 30, 40, 50};
    int N = 5;

    int* resultado = somar_arrays(a, b, N);

    printf("\n");
    for (int i = 0; i < N; i++) {
     printf("%d ", resultado[i]);
    } printf("\n");

    free(resultado);

  return 0;
}
