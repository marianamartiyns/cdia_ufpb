#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h>

main() {

    setlocale(LC_ALL, "Portuguese");

    int num = 1, x, y, r, i;

    while (num != -1) {

        printf("\nDigite [-1] para encerrar o programa.");
        printf("\nDigite um número: ");
        scanf("%d", &num);

        r = sqrt(num);
        x = 2;

        while ((num % x != 0) && (x <= r))

            x += 1;

            if (x > r)

                if (num == -1)
                printf("\nPrograma Encerrado.\n");

                else
                printf("\n  %d é primo\n", num);


            else {
                y = num/x;
                r = sqrt(y);
                i = 2;

                while ((y % i != 0) && (i <= r))
                    i = i + 1;
                if (i <= r)
                printf("\n  %d não é produto de dois primos.\n", num);

                else
                    printf("\n  %d é produto dos primos: %d x %d = %d\n", num, x, y, num);}
    }
}
