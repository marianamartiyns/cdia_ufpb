#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int hora, minuto, segundo;
}tempo;

int converte_segundos(tempo t) {
    int total_segundos = t.hora * 3600 + t.minuto * 60 + t.segundo;
    return total_segundos;
}

int main() {
    tempo t = {10, 30, 45};
    int total_segundos = converte_segundos(t);
    printf("Total de segundos: %d\n", total_segundos);
    return 0;
}
