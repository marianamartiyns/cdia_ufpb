/*Programa que determina o intervalo de tempo decorrido entre dois instantes*/

#include <stdio.h>

// RESCREVER PARA RECEBR HORA MINUTOS E SEGUNDOS

int main(){

    int h1, min1, h2, min2, h, min;

    printf("Digite o instante inicial (horas e minutos)");
    scanf("%d %d", &h1, &min1);

    printf("Digite o instante final");
    scanf("%d %d", &h2, &min2);

    h = h2 - h1;
    min = min2 - min1;

    if ((h < 0) || ((h == 0) && (min < 0)))
    printf("\aDados invalidos! O segundo instante é anterior ao primeiro");

    else{

        if (min < 0){
            h = h - 1;
            min = min + 60;
            }

        printf( "Entre os instantes %dh %dmin e %dh %dmin passaram-se %dh %dmin", h1, min1, h2, min2, h, min);
    }
}

