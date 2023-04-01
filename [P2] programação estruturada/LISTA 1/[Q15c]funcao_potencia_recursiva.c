/* (c) Escreva uma função recursiva que substitua a função iterativa implementada no item (a). */

#include <stdio.h>
#include <locale.h>

double pot(double x, int n) {
    if (n == 0) {
        return 1.0;
    }
    else if (n < 0) {
        return 1.0 / pot(x, -n);
    }
    else {
        return x * pot(x, n - 1);
    }
}

int main() {

    double base;
    int exp;

    printf("\nDigite a base: ");
    scanf("%lf", &base);

    printf("\nDigite o expoente: ");
    scanf("%d", &exp);

    printf("\n%1.lf elevado a %d = %1.lf\n", base, exp, pot(base, exp));
}
