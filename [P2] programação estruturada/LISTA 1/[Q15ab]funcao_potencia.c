/*(a) Escreva uma fun��o em C com dois par�metros:
(1) um par�metro do tipo double e (2) um par�metro do tipo int.
Essa fun��o dever� retornar o valor do primeiro par�metro elevado ao segundo */

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

    printf("\nDigite um n�mero: ");
    scanf("%d", &num);

    printf("\n%d^2 = %d.\n", num, pot(num, exp));
}
