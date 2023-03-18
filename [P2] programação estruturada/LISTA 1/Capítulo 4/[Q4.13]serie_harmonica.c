#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

main() {

    setlocale(LC_ALL, "Portuguese");

    int i = 0;
    float soma = 0, k = 1;

    while (k != -1) {

    printf("\nDigite [-1] para encerrar o programa.");
    printf("\nDigite o  valor da constante(k): ");
    scanf("%f", &k);

    while (soma <= k) {
        i = i + 1;
        soma += 1.0/ i;
    }
    printf("\nO menor inteiro n tal que a soma dos n primeiros termos da serie harmônica é maior que %.1f é %d.\n", k, i);
}
}
