//Basta fazer a soma entre os dois lados menores. Se a soma entre eles for maior que o terceiro lado, ent�o,
//a soma entre qualquer um deles e o terceiro lado (que � o maior) ter� o mesmo resultado.

#include <locale.h>
#include <stdio.h>
#include <stdlib.h>

int main(){

    setlocale(LC_ALL, "");

    int lado1, lado2, lado3;

    printf("Digite o 1� lado do tri�ngulo: ");
    scanf("%d", &lado1);

    printf("Digite o 2� lado do tri�ngulo: ");
    scanf("%d", &lado2);

    printf("Digite o 3� lado do tri�ngulo: ");
    scanf("%d", &lado3);

    // analise, tem que exibir hipotenusa e catetos

    return 0;

}
