#include <stdio.h>
#include <locale.h>

int main() {

    setlocale(LC_ALL, "Portuguese");

    int num1, num2, result;

    printf("\nDigite um inteiro para ser o 'multiplo': ");
    scanf("%d", &num1);

    printf("\nDigite outro inteiro: ");
    scanf("%d", &num2);

    result = (num2 / num1) * num1;

    printf("\nO maior múltiplo de %d que é menor ou igual a %d é: %d\n", num1, num2, result);

    return 0;
}
