#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

main() {

    setlocale(LC_ALL, "Portuguese");

    int i, a, q, termo;

    for (i = 5; i > 0; i = i - 1){

        a = i;
        q = 3;
        termo = a;

        while (termo <= 9 * a){
            printf("%d \n", termo);
            termo = termo * q;
        }
    }
}

/*

Após a execução do codígo acima essa é a configuração de tela:


5
15
45
4
12
36
3
9
27
2
6
18
1
3
9

*/
