
#include <stdio.h>;
#include <stdlib.h>;
#include <locale.h>

int main() {

    int a, b;
    printf("\nEscreva 2 valores para o algoritimo troca-los de vari�veis.\n");

    printf("Digite um valor para a vari�vel \"a\": ");
    scanf("%d", &a);

    printf("Digite outro valor para a var�vel \"b\": ");
    scanf("%d", &b);

    printf("\nO valor inicial da vari�vel \"a\" foi: %.2ff\nO valor inicial da vari�vel \"b\" foi: %.2f", a, b);

    a = a + b;
    b = a - b;
    a = a - b;

    printf("\nCom os valores trocados a vari�vel \"a\" ficou: %.2f\nE o valor de \"b\" ficou: %.2f", a, b);

    return 0;
}
