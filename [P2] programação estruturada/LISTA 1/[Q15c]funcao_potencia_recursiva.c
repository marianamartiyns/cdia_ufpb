/* (c) Escreva uma função recursiva que substitua a função iterativa implementada no item (a). */

#include <stdio.h>
#include <locale.h>

int pot(double x, int y){

    int i, parcial, result = 1;

    result * x;
    parcial = result * pot(result, x);

    return parcial;
}

int main() {

    setlocale(LC_ALL, "Portuguese");

    int num, pot(double x, int y);
    double exp;

    printf("\nDigite um expoente: ");
    scanf("%lf", &exp);

    printf("\nDigite um número: ");
    scanf("%d", &num);

    printf("\n%d^2 = %d.\n", num, pot(num, exp));
}



