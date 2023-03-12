#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main() {

    setlocale(LC_ALL, " ");

    int minutos, horas, segundos;

    printf("Digite um intervalo de tempo em minutos: ");
    scanf("%d", &minutos);

    horas = minutos / 60;
    minutos = minutos % 60;
    segundos = minutos * 60;

    printf("\n%d minutos equivalem a %d horas, %d minutos e %d segundos.\n", minutos + horas * 60, horas, minutos, segundos);

    return 0;
}
