#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h>

main() {

    setlocale(LC_ALL, "Portuguese");

    int n, num_alg = 0, n_org;

    printf("\nDigite um número inteiro positivo: ");
    scanf("%d", &n);

    n_org = n;

    while (n != 0) {
        num_alg++;
        n /= 10;
    }

    printf("\n  O número %d tem %d algarismos.\n", n_org, num_alg);

    return 0;
}
