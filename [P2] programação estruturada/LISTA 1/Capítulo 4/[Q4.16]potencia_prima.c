#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int pot_prima(int num) // função para verificar se um número é uma potência prima
{
    int i, count = 0;
    if (num < 2)
        return 0;

    for (i = 2; i <= num / 2; i++){
        if (num % i == 0){
            count++;
            while (num % i == 0)
                num /= i;
        }
    }

    if (num > 1)
        count++;

    return count == 1;
}

int main() {

     setlocale(LC_ALL, "Portuguese");
     int num, i, resultado = 0;

     printf("\nDigite um número: ");
     scanf("%d", &num);

     for (i = 2; i <= num / 2; i++) {
        if (num % i == 0) {
           resultado++;
           printf("\nEsse número não é primo.\n");
           break;
        }
     }

     if (resultado == 0)

        if (pot_prima(num))
            printf("\nEsse número é uma potência prima.\n");
     else
        printf("\n%d não é uma potência prima\n", num);

}
