#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h>

int main(){

    setlocale(LC_ALL, "Portuguese");

    float num, raiz_inteira, raiz_real, partefrac;

    printf("\nDigite um valor para saber se ele � um quadrado perfeito: ");
    scanf("%f", &num);

    raiz_real = sqrt(num);
    raiz_inteira = raiz_real;
    partefrac = raiz_real - raiz_inteira;

    if (partefrac == 0)
        printf("\n %.0f � quadrado perfeito de raiz %.2f\n", num, raiz_inteira);
    else
        printf("\n %.0f n�o � quadrado perfeito\n ", num);

    return 0;
}
