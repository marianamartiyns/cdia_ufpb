/*Programa para determinar o m�nimo m�ltiplo comum de dois n�meros positivos*/

// refazer tomando o maior dos n�mero dados como base do raciocio

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
