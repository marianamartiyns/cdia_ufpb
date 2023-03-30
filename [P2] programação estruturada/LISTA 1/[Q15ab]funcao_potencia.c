/*(a) Escreva uma função em C com dois parâmetros:
(1) um parâmetro do tipo double e (2) um parâmetro do tipo int.
Essa função deverá retornar o valor do primeiro parâmetro elevado ao segundo */

#include <stdio.h>
#include <locale.h>

int pot(double x, int y){

    int i, result = 1;

    for (i = 0; i < y; i++){
        result *= x;
    }
    return result;
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
