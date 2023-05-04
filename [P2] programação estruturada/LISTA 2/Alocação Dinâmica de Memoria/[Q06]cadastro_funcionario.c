#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {

    char nome[50], sobrenome[50];
    int idade;
    float salario;

} funcionario;

int main() {

    int num_funcionarios;

    printf("Quantos funcionarios deseja cadastrar? ");
    scanf("%d", &num_funcionarios);

    funcionario* funcionarios = (funcionario*) malloc(num_funcionarios * sizeof(funcionario));

    for (int i = 0; i < num_funcionarios; i++) {

        printf("Funcionario %d:\n", i + 1);
        printf("Nome: ");
        scanf("%s", funcionarios[i].nome);
        printf("Sobrenome: ");
        scanf("%s", funcionarios[i].sobrenome);
        printf("Idade: ");
        scanf("%d", &funcionarios[i].idade);
        printf("Salario: ");
        scanf("%f", &funcionarios[i].salario);
        printf("\n");
    }

    printf("Funcionarios cadastrados:\n");

    for (int i = 0; i < num_funcionarios; i++) {
        printf("%d. %s %s, %d anos, salario R$ %.2f\n", i + 1, funcionarios[i].nome, funcionarios[i].sobrenome, funcionarios[i].idade, funcionarios[i].salario);
    }

    free(funcionarios);

    return 0;
}
