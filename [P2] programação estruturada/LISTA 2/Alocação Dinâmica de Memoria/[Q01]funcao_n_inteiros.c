#include <stdlib.h>
#include <locale.h>

int* gerar_array(int n) {

  int* array = (int*)malloc(n * sizeof(int));

  for (int i = 0; i < n; i++) {
    array[i] = i + 1;
  }

  return array;
}

int main() {

    setlocale(LC_ALL, "");
    int num;
    printf("\nDigite um número inteiro: ");
    scanf("%d", &num);

    int* array = gerar_array(num);

    printf("\n");
    for (int i = 0; i < num; i++) {
    printf(" %d ", array[i]);
    } printf("\n");

    free(array);
    return 0;
}
