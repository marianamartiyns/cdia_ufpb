#include <stdio.h>
#include <stdlib.h>

typedef enum{CIRCULO, QUADRADO, RETANGULO}tipo_figura;

typedef struct{
    tipo_figura tipo;
    void *dados;
}figura;

int main(){

    figura f;

    //nao entendi
    struct circulo c = {3};
    f.tipo = CIRCULO;
    f.dados = &c;

    return 0;
}
