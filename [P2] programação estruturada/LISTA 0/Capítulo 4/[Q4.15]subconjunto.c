#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

main() {

    setlocale(LC_ALL, "Portuguese");

    int n, i, j, k;

    printf("\nInforme um valor para descobrir todos os subconjuntos de 3 elementos {a,b,c}");
    printf("\nDigite um valor: ");
    scanf("%d", &n);

    if (n == 1 || n == 2 || n == 0 || n < 0)
        printf("\nValor Invalído, para o tipo de conjunto {a,b,c}.\n");
    else
        for (i = 1; i <= n - 2; i++)
            for (j = i + 1; j <= n - 1; j++)
                for (k = j + 1; k <= n; k++)
                    printf("{%d, %d, %d}\n", i, j, k);
    }

