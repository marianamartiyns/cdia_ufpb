#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main(){

    setlocale(LC_ALL, "Portuguese");

    float lado1, lado2, lado3, hip, cat1, cat2;

    printf("\nDigite o 1� lado do tri�ngulo: ");
    scanf("%f", &lado1);

    printf("\nDigite o 2� lado do tri�ngulo: ");
    scanf("%f", &lado2);

    printf("\nDigite o 3� lado do tri�ngulo: ");
    scanf("%f", &lado3);

    cat1 = lado2;
    cat2 = lado3;

    if ((lado1 < lado2 + lado3) && (lado2 < lado1 + lado3) && (lado3 < lado1 + lado2)){

        if ((lado1 > lado2) && (lado1 > lado3))
            hip = lado1;

        else{
            if (lado2 > lado3){
                hip = lado2;
                cat1 = lado1;
            }

            else{
                hip = lado3;
                cat2 = lado1;
            }
        }

        if (hip * hip == cat1 * cat1 + cat2 * cat2)
            printf("Tri�ngulo ret�ngulo de hipotenusa %0.2f e catetos %0.2f e %0.2f.", hip, cat1, cat2);

        else
            printf("O Tri�ngulo de lados %0.2f, %0.2f e %0.2f n�o � ret�ngulo.", lado1, lado2, lado3);
        }

    else
        printf("Os n�meros dados n�o formam um tri�ngulo!\n");

    return 0;

}
