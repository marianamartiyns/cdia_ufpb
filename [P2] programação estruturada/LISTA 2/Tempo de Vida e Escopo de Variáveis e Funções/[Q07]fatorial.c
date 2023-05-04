#include <stdio.h>
#include <locale.h>

int fatorial(int n) {
    static int fat = 1;

    if (n == 1) {
        return fat;
    } else {
        fat = fat * n;
        return fatorial(n-1);
    }
}

int main() {

    setlocale(LC_ALL, "");
    int num;

    printf("\nDigite um número inteiro positivo: ");
    scanf("%d", &num);

    int result = fatorial(num);

    printf("\nO fatorial de %d é %d.\n", num, result);

    return 0;
}
