#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main() {

    setlocale(LC_ALL, "Portuguese");

    int a, b;
    printf("\nEscreva 2 valores para o algoritimo troca-los de vari�veis.\n");

    printf("Digite um valor para a vari�vel \"a\": ");
    scanf("%d", &a);

    printf("Digite outro valor para a var�vel \"b\": ");
    scanf("%d", &b);

    printf("\n\nO valor inicial da vari�vel \"a\" foi: %d\nO valor inicial da vari�vel \"b\" foi: %d", a, b);

    a = a + b;
    b = a - b;
    a = a - b;

    printf("\n\nCom os valores trocados a vari�vel \"a\" ficou: %d\nE o valor de \"b\" ficou: %d\n", a, b);

    return 0;
}
