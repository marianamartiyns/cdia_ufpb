#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main(){

    setlocale(LC_ALL, "Portuguese");

    float lado1, lado2, lado3, hip, cat1, cat2;

    printf("\nDigite o 1º lado do triângulo: ");
    scanf("%f", &lado1);

    printf("\nDigite o 2º lado do triângulo: ");
    scanf("%f", &lado2);

    printf("\nDigite o 3º lado do triângulo: ");
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
            printf("Triângulo retângulo de hipotenusa %0.2f e catetos %0.2f e %0.2f.", hip, cat1, cat2);

        else
            printf("O Triângulo de lados %0.2f, %0.2f e %0.2f não é retângulo.", lado1, lado2, lado3);
        }

    else
        printf("Os números dados não formam um triângulo!\n");

    return 0;

}
