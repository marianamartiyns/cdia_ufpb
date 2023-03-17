#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

main() {

    setlocale(LC_ALL, "Portuguese");

    int n, x = 1, termo = 1, i = 1 , y = 0;

    printf("\nDigite um valor: ");
    scanf("%d", &n);

    while (i < n) {
        termo = x + y;
        y = x;
        x = termo;
        i += 1;
    }

    printf("\nO termo de ordem %d da sequência de Fibbonaci é %d.\n", n, termo);

    return 0;
}
