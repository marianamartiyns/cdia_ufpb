#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main() {

    setlocale(LC_ALL, "Portuguese");

    int minutos, horas, segundos, resto;

    printf("\nDigite um intervalo de tempo em minutos: ");
    scanf("%d", &minutos);

    horas = minutos / 60;
    resto = minutos % 60;
    segundos = resto * 60;

    printf("\n%d minutos equivalem a %d horas, %d minutos e %d segundos.\n", minutos, horas, resto, segundos);

    return 0;
}

