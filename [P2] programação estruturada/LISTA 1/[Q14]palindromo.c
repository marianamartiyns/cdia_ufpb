#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

int main(){

    setlocale(LC_ALL, "Portuguese");

    char palavra[30], copia[30];
    int i, tam, iguais = 0;

    printf("\nDigite uma palavra: ");
    scanf("%s", palavra);

    tam = strlen(palavra);
    for(i = 0; i < strlen(palavra); i++){
        copia[i] = palavra[tam - 1];
        tam--;}

    copia[i] = '\0';
    tam = strlen(palavra);

    printf("\nOriginal: %s\nInversa: %s\n", palavra, copia);

    for(i = 0; i < tam; i++){
        if(palavra[i] == copia[i])
            iguais++;
    }

    if(tam == iguais)
        printf("\nEssa palavra é palindroma.\n");
    else
        printf("\nEssa palavra não é palindroma.\n");

    return 0;
}
