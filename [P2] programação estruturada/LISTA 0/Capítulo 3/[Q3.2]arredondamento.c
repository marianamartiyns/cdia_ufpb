#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main(){

    setlocale(LC_ALL, "Portuguese");

    float num, frac;
    int arredondamento;

    printf("\nDigite um número decimal (ex: 245,53): ");
    scanf("%f", &num);

    arredondamento = num;
    frac = num - arredondamento;

    if (frac >= 0.5)
        arredondamento = arredondamento + 1;

    printf("%f arrendondado fica: %d ", num, arredondamento);

    return 0;
}
