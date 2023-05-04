#include <stdio.h>

float calcular_media(float soma, int n) {
    return soma / n;
}

int main() {

    float numero, soma = 0, media;
    static int n = 0;

    while (1) {
        printf("\nDigite a nota (ou -1 para sair): ");
        scanf("%f", &numero);

        if (numero == -1) {
            break;
        }

        soma += numero;
        n++;
    }

    media = calcular_media(soma, n);
    printf("\n\nMédia: %.2f\n", media);

    return 0;
}
