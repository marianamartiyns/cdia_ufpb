#import <stdio.h>
#import <locale.h>

int main() {

    setlocale(LC_ALL, " ");

    int num1, num2, result;

    printf("Digite um inteiro para ser o 'multiplo': ");
    scanf("%d", &num1);

    printf("Digite outro inteiro: ");
    scanf("%d", &num2);

    result = (num2 / num1) * num1;

    printf("O maior m�ltiplo de %d que � menor ou igual a %d �: %d\n", num1, num2, result);

    return 0;
}
