/* O que são ponteiros em C ? Mostre um exemplo prático da utilização de ponteiros.

Ponteiros são variáveis que armazenam endereços de memória como valor. Eles permitem o acesso direto e manipulação de dados na memória.
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
    printf("Valor de p: %p == Endereço da variavel letra (%p).\n\n", p, &letra);
    printf("Endereço de p: %p != Endereço da variavel letra (%p).\n", &p, &letra);
}
