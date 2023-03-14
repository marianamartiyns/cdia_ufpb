#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main(){

    setlocale(LC_ALL, "Portuguese");

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

    printf("\nDentre %1.f , %1.f , %1.f , o maior valor é %.1f.\n", valor1, valor2, valor3, maior);

    return 0;
}
