#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main () {

    setlocale(LC_ALL, " ");

    int saque, nota50, nota20, nota10, nota5, nota1, resto;

    printf("\n== Notas Disponiveís: R$50, R$20, R$10, R$5, R$1 ==");
    printf("\nDigite o valor inteiro do saque: ");
    scanf("%d", &saque);

    nota1 = resto / 1;
    resto = saque % 1;

    nota5 = resto / 5;
    resto = saque % 5;

    nota10 = resto / 10;
    resto = saque % 10;

    nota20 = resto / 20;
    resto = saque % 20;

    nota50 = saque / 50;
    resto = saque % 50;

    printf("\nNotas de 50 a receber: %d, \nNotas de 20 a receber: %d, \nNotas de 10 a receber: %d, \nNotas de 5 a receber: %d, \nNotas de 1 a receber: %d.\n");
    return 0;
}
