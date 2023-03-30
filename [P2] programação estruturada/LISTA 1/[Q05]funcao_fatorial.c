//  Defina o que � recursividade e implemente uma fun��o recursiva que calcule o fatorial de um n�mero inteiro.

/*Recursividade � quando uma fun��o chama a si propria dentro dela mesma, nisso ocorre uma repeti��o at� a condi��o de parada;

Exemplo com uma fun��o que calcula o fatorial de um n�mero inteiro:
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

    printf("\nDigite um n�mero inteiro para obter a sua fatorial: ");
    scanf("%d", &n);

    printf("\nFatorial de %d: %d\n", n, fat(n));
}
