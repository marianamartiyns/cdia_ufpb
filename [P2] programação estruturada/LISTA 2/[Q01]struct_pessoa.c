#include <stdio.h>

typedef struct{

    char nome[50];
    int idade;
    float h;

}Pessoa;

int main(){

    Pessoa p1;

    printf("\nDigite o seu nome: ");
    fgets(p1.nome, 20, stdin);

    printf("Digite sua idade: ");
    scanf("%d", &p1.idade);

    printf("Digite sua altura: ");
    scanf("%f", &p1.h);

    printf("Nome: %s\nIdade: %d\nAltura: %.2f\n", p1.nome, p1.idade, p1.h);
}
