#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

main() {

    setlocale(LC_ALL, "Portuguese");

    int n1, n2, i, mmc;

    printf("\nDigite o 1º valor: ");
    scanf("%d", &n1);

    printf("\nDigite o 2º valor: ");
    scanf("%d", &n2);

    mmc = n1;

    while (mmc % n2 != 0)

        mmc = mmc + n1;
        printf("\n  mmc(%d, %d) = %d.\n", n1, n2, mmc);

    return 0;
}
