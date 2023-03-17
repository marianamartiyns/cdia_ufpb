#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

main() {

    setlocale(LC_ALL, "Portuguese");

    int num, i = 2, n, mult;
    num = 1;

    while (num != -1) {

        printf("\nDigite [-1] para encerrar o programa.");
        printf("\nDigite o  número: ");
        scanf("%d", &num);

        n = num;
        printf("\n  Decomposicão em fatores primos de %d:\n", num);
        while (n > 1) {

            mult = 0;
            while (n % i == 0) {
            n = n/i;
            mult = mult + 1;
            }

            if (mult > 0)
            printf("        %d x %d\n", i, mult);
            i = i + 1;
            }
    }
    return 0;
}
