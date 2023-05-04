#include <stdio.h>

int main() {

    int i, j;
    static int cont = 0;

    printf("Tabuada de multiplicação de 1 a 10:\n");
    for (i = 1; i <= 10; i++) {
        for (j = 1; j <= 10; j++) {
            printf("%d x %d = %d\n", i, j, i*j);
        }
        printf("\n");
    }

    cont++;
    printf("A tabuada foi impressa %d vezes.\n", cont);

    return 0;
}
