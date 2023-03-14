// confere raizes reais ou complexas dados os coeficiente

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
        delta = b * b ­ 4 * a * c;

    if (Delta >= 0) {
        imag = sqrt(delta)/(2 * a);
        x1 = real + imag;
        x2 = real - imag;
        printf("As raizes da equacao de coeficientes %.2f, %.2f e %.2f sao %.2f e %.2f ", a, b, c, x1, x2);
    }

    else {
        imag = sqrt(-delta)/(2*a);
        printf("As raizes da equacao de coeficientes %.2f , %.2f e %.2f sao %.2f + %.2fi e %.2f - %.2fi ", a, b, c, Real, Imag, Real, Imag);
        }

    }
    else
        printf("A equacao nao e do segundo grau");
    }

    return 0;
}
