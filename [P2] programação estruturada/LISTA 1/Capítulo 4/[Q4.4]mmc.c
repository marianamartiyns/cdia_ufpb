/*Programa para determinar o mínimo múltiplo comum de dois números positivos*/

// refazer tomando o maior dos número dados como base do raciocio

#include <stdio.h>

main() {

    int x, y, i, mmc;

    printf("Digite os dois numeros \n");
    scanf("%d %d", &x, &y);

    mmc = x;

    while (mmc % y != 0)

        mmc = mmc + x;
        printf("mmc(%d, %d) = %d \n", x, y, mmc);

    return 0;
}
