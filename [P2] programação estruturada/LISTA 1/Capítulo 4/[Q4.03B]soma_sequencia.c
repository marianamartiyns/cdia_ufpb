#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

main() {

    setlocale(LC_ALL, "Portuguese");

    float soma = 0;
    int n, i;

    printf("\nDigite um valor: ");
    scanf("%d", &n);

    for (i = 1; i <= n; i++)

        if (i % 2 == 1)
            soma = soma + 1.0 / i;
        else
            soma = soma - 1.0 / i;

    printf("\nA soma dos %d primeiros números da sequência dada é %.3f.\n", n, soma);

    return 0;
}

