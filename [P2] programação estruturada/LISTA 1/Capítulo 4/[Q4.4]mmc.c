/*Programa para determinar o mínimo múltiplo comum de dois números positivos*/

// refazer tomando o maior dos número dados como base do raciocio

#include <stdio.h>

main() {

    int x, y, i, Mmc;

    printf("Digite os dois numeros \n");
    scanf("%d %d", &x, &y);

    Mmc = x;

    while (Mmc % y != 0)

        Mmc = Mmc + x;
        printf("mmc(%d, %d) = %d \n", x, y, Mmc);

    return 0;
}
