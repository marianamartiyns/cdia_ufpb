/*Faça um programa que tenha o seguinte menu:
    1 – Incluir pessoa;     2 – Listar pessoas;     3 – Remover pessoa */

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

int main(){

    setlocale(LC_ALL, "Portuguese");

    int opcao, pessoas[100], tam, num_pessoas = 0;
    char nome[50];

    do{
    printf("\n== Menu de Opções ==\n\nDigite [1] para Incluir\nDigite [2] para Listar pessoas\nDigite [3] para Remover Pessoa\nDigite [0] para encerrar o programa\n\n   Sua Opção: ");
    scanf("%d", &opcao);

    switch (opcao){

    case 1:

        char nome[50];
        printf("\nDigite o nome da pessoa: ");
        scanf("%s", &nome);

        strcpy(pessoas[num_pessoas], nome);
        num_pessoas++;
        printf("\nPessoa adicionada com sucesso!\n");
        break;

    case 2:

        if (num_pessoas == 0) {
        printf("Nao ha pessoas cadastradas.\n");
        }

        printf("Pessoas cadastradas:\n");
        for (int i = 0; i < num_pessoas; i++)
            printf("- %s\n", pessoas[i].nome);

        break;

    case 3:

        char nome[50];
          printf("Digite o nome da pessoa que deseja remover: ");
          scanf("%s", nome);

          int pos = -1;
          for (int i = 0; i < num_pessoas; i++) {
            if (strcmp(pessoas[i].nome, nome) == 0) {
              pos = i;
              break;
            }
          }

          if (pos == -1) {
            printf("Pessoa nao encontrada.\n");
            return;
          }

          for (int i = pos; i < num_pessoas - 1; i++) {
            pessoas[i] = pessoas[i + 1];
          }

          num_pessoas--;
          printf("Pessoa removida com sucesso!\n");
        }

            break;

        default:
            printf("Opção Invalída! Tente Novamente.");
            break;

        }} while (opcao != 0);
}
