#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main(){

    setlocale(LC_ALL, "Portuguese");

    int tam, vetor[tam], i, n;

    printf("Digite [0] para encerar o programa.");

    do{
        printf("Digite um valor: ");
        scanf("%d", &vetor[i]);
    } while (vetor[i] != 0);


}
