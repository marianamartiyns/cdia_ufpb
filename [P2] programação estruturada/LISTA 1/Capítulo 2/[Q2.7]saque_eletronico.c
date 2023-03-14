#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main () {

    setlocale(LC_ALL, "Portuguese");

    int saque, nota50, nota20, nota10, nota5, nota1, resto;

    printf("\n== Notas Disponiveís: R$50, R$20, R$10, R$5, R$1 ==");
    printf("\nDigite o valor inteiro do saque: ");
    scanf("%d", &saque);

    nota50 = saque / 50;
    resto = saque % 50;

    nota20 = resto / 20;
    resto = resto % 20;

    nota10 = resto / 10;
    resto = resto % 10;

    nota5 = resto / 5;
    resto = resto % 5;

    nota1 = resto / 1;
    resto = resto % 1;

    printf("\nValor do Saque: %d\n", saque);
    printf("\nNotas de R$50 a receber: %d\nNotas de R$20 a receber: %d\nNotas de R$10 a receber: %d\nNotas de R$5 a receber: %d\nNotas de R$1 a receber: %d\n", nota50, nota20, nota10, nota5, nota1);
    return 0;
}

