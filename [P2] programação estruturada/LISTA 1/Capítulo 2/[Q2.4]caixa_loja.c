#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main() {

    setlocale(LC_ALL, "Portuguese");

    float compra, entrada, parcelas;

    printf("\nDigite o valor da compra: ");
    scanf("%f", &compra);

    parcelas = compra / 3;
    entrada = compra - 2 * parcelas;

    printf("\nCom a entrada no valor de R$%2.f as parcelas ficaram R$ %2.f\n", entrada, parcelas);

    return 0;
}
