#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

main() {

    setlocale(LC_ALL, "Portuguese");

    int mil, cen, i;

    printf("\nO número 3.025 possui a seguinte característica: 30 + 25 = 55 e 552 = 3 025.");
    printf("\nEste programa lista todos os números com quatro algarismos que possuem a mesma característica.\n");

    for (i = 1000; i < 10000; i++){

        cen = i % 100;
        mil = i / 100;
        if ((cen + mil)*(cen + mil) == i)
        printf("\n %d ", i);
        }
    printf("\n");

    return 0;
}

