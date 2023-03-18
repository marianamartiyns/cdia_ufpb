#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h>

int main(){

    setlocale(LC_ALL, "Portuguese");

    float a, b, c, imag, real, delta, x1, x2;

    printf("\nDigite o 1° coeficiente: ");
    scanf("%f", &a);

    printf("\nDigite o 2° coeficiente: ");
    scanf("%f", &b);

    printf("\nDigite o 3° coeficiente: ");
    scanf("%f", &c);

    if (a != 0){
        real = -b /(2 * a);
        delta = b * b - 4 * a * c;

    if (delta >= 0) {
        imag = sqrt(delta)/(2 * a);
        x1 = real + imag;
        x2 = real - imag;
        printf("As raizes da equacao de coeficientes %.2f, %.2f e %.2f são %.2f e %.2f ", a, b, c, x1, x2);
    }

    else {
        imag = sqrt(-delta)/(2*a);
        printf("\nAs raizes da equacão de coeficientes %.2f , %.2f e %.2f são %.2f + %.2fi e %.2f - %.2fi ", a, b, c, real, imag, real, imag);
        }

    }
    else
        printf("A equacao não e do segundo grau");
    }
