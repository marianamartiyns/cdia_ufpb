#include <stdlib.h>
#include <locale.h>

int maior_elemento(int* array, int N) {
  int maior = 0;

  for (int i = 1; i < N; i++) {
    if (array[i] > array[maior]) {
      maior = i;
    }
  }

  return maior;
}

int main() {

    setlocale(LC_ALL, "");
    int array[] = {10, 20, 5, 30, 15}, N = 5;

    int indice_maior = maior_elemento(array, N);

    printf("O maior elemento do array está no índice %d.\n", indice_maior);

    return 0;
}


