#include <stdio.h>
#include <locale.h>

typedef struct{

    char nome;
    int idade;
    float notas[3];
}Aluno;

float calcula_media(struct Aluno a) {
    float soma = 0;
    int i;

    for (i = 0; i < 4; i++) {
        soma += a.notas[i];}

    return soma / 3;
}

int main() {
    struct Aluno a = {"Joao", 20, {7.5, 8.0, 9.5}};
    float media = calcula_media(a);

    printf("A media do aluno %s eh: %.2f", a.nome, media);

    return 0;
}
