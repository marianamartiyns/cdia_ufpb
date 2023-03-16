#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

main() {

    setlocale(LC_ALL, "Portuguese");

    float soma = 0.5, num = 1, den = 2;
    int n, i;

    printf("\nDigite um valor: ");
    scanf("%d", &n);

    for (i = 1; i < n; i++){
        num = num + 2;
        den = den + 3;
        soma = soma + num / den;
    }

    printf("\nA soma dos %d primeiros números da sequência dada é %.3f.\n", n, soma);

    return 0;
}
