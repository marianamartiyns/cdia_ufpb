#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

main() {

    setlocale(LC_ALL, "Portuguese");

    int n, i, soma = 0;

    printf("\nDigite um valor: ");
    scanf("%d", &n);

    for (i = 1; i <= n; i++)
        soma += i*i;

    printf("\nA soma dos quadrados dos %d primeiros números naturais é %d.\n", n, soma);

    return 0;
    }

