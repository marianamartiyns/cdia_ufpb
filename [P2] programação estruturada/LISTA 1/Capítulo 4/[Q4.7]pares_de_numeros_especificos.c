#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

main() {

    setlocale(LC_ALL, "Portuguese");

    int invert_i, invert_j, i, j;

    printf("\nEsse progarma lista todos os números com dois algarismos cujo produto não se altera os algarismos são invertidos.\n\n");

    for (i = 10; i < 100; i++) {
        invert_i = (i % 10)*10 + (i/10);

        for (j = 10; j < 100; j++) {
            invert_j = (j % 10)*10 + (j/10);

            if (i*j == invert_i * invert_j)
                printf("%d * %d  ==  %d * %d  ==  %d\n", i, j, invert_i, invert_j, i*j);
        }
    }
}


