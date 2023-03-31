/* O que s�o ponteiros em C ? Mostre um exemplo pr�tico da utiliza��o de ponteiros.

Ponteiros s�o vari�veis que armazenam endere�os de mem�ria como valor. Eles permitem o acesso direto e manipula��o de dados na mem�ria.
Exemplo pratico:  */

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main(){

    setlocale(LC_ALL, "Portuguese");

    char letra = 'f';
    char *p;

    p = &letra;

    printf("\nConsidere 'letra' uma variavel com valor f,\ne *p um ponteiro que recebe letra, com isso concluimos:\n");
    printf("\nValor da variavel letra: %c\n", letra);
    printf("Valor apontado por p: %c\n\n", *p);
    printf("Valor de p: %p == Endere�o da variavel letra (%p).\n\n", p, &letra);
    printf("Endere�o de p: %p != Endere�o da variavel letra (%p).\n", &p, &letra);
}
