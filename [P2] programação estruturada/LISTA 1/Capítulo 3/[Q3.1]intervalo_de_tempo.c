/*Programa que determina o intervalo de tempo decorrido entre dois instantes*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main(){

    setlocale(LC_ALL, "Portuguese");

    int h1, min1, seg1, h2, min2, seg2, h, min, seg;

    printf("\nDigite o instante inicial em horas, minutos e segundos(ex: 12:43:52 = 12 43 52): ");
    scanf("%d %d %d", &h1, &min1, &seg1);

    printf("\nDigite o instante final em horas, minutos e segundos(ex: 05:25:13 = 05 25 13): ");
    scanf("%d %d %d", &h2, &min2, &seg2);

    h = h2 - h1;
    min = min2 - min1;
    seg = seg1 - seg2;

    if ( (h < 0) || (h == 0) && (min < 0) || (min == 0) && (seg < 0) )
            printf("\nDados invalídos! O segundo instante é anterior ao primeiro.\n");

    else{

            if (min < 0){
                h = h - 1;
                min = min + 60;
            }

            if (seg < 0){
                min = min - 1;
                seg = seg + 60;
            }

        printf( "\nEntre os instantes %d:%d:%d e %d:%d:%d passaram-se %d hr(s), %d min(s) e %d seg(s).\n", h1, min1, seg1, h2, min2, seg2, h, min, seg);
    }
}

