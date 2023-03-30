//  Defina o que é recursividade e implemente uma função recursiva que calcule o fatorial de um número inteiro.

/*Recursividade é quando uma função chama a si propria dentro dela mesma, nisso ocorre uma repetição até a condição de parada;

Exemplo com uma função que calcula o fatorial de um número inteiro:
 */

#include <stdio.h>
#include <locale.h>

int fat(int num) {

     if(num==0)
        return 1;
     else
        return num * fat(num-1);
}

int main(){

    setlocale(LC_ALL, "Portuguese");

    int fat(int num), n;

    printf("\nDigite um número inteiro para obter a sua fatorial: ");
    scanf("%d", &n);

    printf("\nFatorial de %d: %d\n", n, fat(n));
}
