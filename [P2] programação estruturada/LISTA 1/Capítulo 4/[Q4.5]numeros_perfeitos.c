#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

main() {

    setlocale(LC_ALL, "Portuguese");

    int num, i, c = 0;

    printf("\nDigite um n�mero para verificar se ele � considerado 'perfeito': ");
    scanf("%d", &num);

    for (i=1; i <= num; i++) {
      if (num % i == 0)
        c += i;
    }

    if (c == (num * 2))
        printf("\n  %d � um n�mero perfeito.\n", num);

    else
        printf("\n  %d n�o � um n�mero perfeito.\n", num);

    return 0;
}

