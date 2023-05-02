#include <stdio.h>
#include <locale.h>

typedef union{
    int inteiro;
    float pont_flut;
    char string[30];
}TipoDado;

int main(){

    setlocale(LC_ALL, "Portuguese");
    TipoDado dados;

    printf("\nDigite um número inteiro: ");
    scanf("%d", &dados.inteiro);

    printf("Digite um número flutuante: ");
    scanf("%f", &dados.pont_flut);

    printf("Digite uma string: ");
    scanf("%s", dados.string);
    //fgets(dados.string, 30, stdin);

    printf("\n\nInteiro: %d\nP. flutuante: %.2f\nString: %s\n", dados.inteiro, dados.pont_flut, dados.string);
}
