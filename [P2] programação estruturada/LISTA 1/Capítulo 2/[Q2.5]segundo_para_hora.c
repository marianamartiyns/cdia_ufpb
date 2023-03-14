#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main () {

    setlocale(LC_ALL, "Portuguese");

    int segundos, h, m, s, resto;

    printf("\nDigite a quantidade de segundos: ");
    scanf("%d", &segundos);

    h = segundos / 3600;
    resto = segundos % 3600;
    m = resto / 60;
    s = resto % 60;

    printf("\n%d segundos equivale a %d hora(s), %d minutos e %d segundos.\n", segundos, h, m, s);

    return 0;
}
