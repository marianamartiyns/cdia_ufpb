#include <stdio.h>;
#include <stdlib.h>;

int main() {

    float valor1, valor2, valor3, maior;

    printf("\nDigite o 1º valor: ");
    scanf("%f", &valor1);

    printf("\nDigite o 2º valor: ");
    scanf("%f", &valor2);

    printf("\nDigite o 3º valor: ");
    scanf("%f", &valor3);

    if (valor1 > valor2){

        if (valor1 > valor3)
            maior = valor1;

        else
            maior = valor3;
    }

    else {
        if(valor2 > valor3)
            maior = valor2;

        else
            maior = valor3;
    }

    printf("Dentre %1.f, %1.f, %1.f, o maior valor é %.1f", valor1, valor2, valor3, maior);
    return 0;
}
