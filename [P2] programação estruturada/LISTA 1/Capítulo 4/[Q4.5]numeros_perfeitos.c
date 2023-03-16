#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

main() {

    setlocale(LC_ALL, "Portuguese");

    int num, i, c = 0;

    printf("\nDigite um número para verificar se ele é considerado 'perfeito': ");
    scanf("%d", &num);

    for (i=1; i <= num; i++) {
      if (num % i == 0)
        c += i;
    }

    if (c == (num * 2))
        printf("\n  %d é um número perfeito.\n", num);

    else
        printf("\n  %d não é um número perfeito.\n", num);

    return 0;
}

