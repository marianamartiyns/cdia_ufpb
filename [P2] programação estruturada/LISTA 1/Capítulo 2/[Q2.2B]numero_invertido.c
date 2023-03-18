#include <stdio.h>
#include <locale.h>

int main() {

    setlocale(LC_ALL, "Portuguese");
    int valor, resto;

    printf("\nDigite um número de 3 algarismos: ");
    scanf("%d", &valor);
    printf("\n");

    if (valor >= 0) {
        do {
            resto = valor % 10;
            printf(" %d", resto);
            valor /= 10;
        }
        while (valor != 0);
        printf("\n");
    }
    else
    if (valor <1){
        valor = valor * -1;
        printf("-");

        do{
            resto = valor % 10;
            printf("%d", resto);
            valor /= 10;
        }
        while (valor != 0);
        printf("\n");
    } }
