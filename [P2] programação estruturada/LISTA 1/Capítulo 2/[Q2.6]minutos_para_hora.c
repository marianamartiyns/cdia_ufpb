#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main () {

    setlocale(LC_ALL, " ");

    int minutos, h, m, s, resto;

    printf("\nDigite a quantidade de minutos: ");
    scanf("%d", &minutos);

    h = minutos / 60;
    resto = minutos % 60;
    m = resto / 60;
    s = resto % 60;

    printf("\n%d minutos equivale a %d horas, %d minutos e %d segundos.\n", minutos, h, m, s);

    return 0;
}
