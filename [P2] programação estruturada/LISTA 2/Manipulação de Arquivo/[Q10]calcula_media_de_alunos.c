//

#include <stdio.h>
#include <string.h>

#define MAX_NOME 100

typedef struct {

    char nome[MAX_NOME];
    float nota1, nota2, media;
    int situacao; // 0 - Reprovado, 1 - Aprovado, 2 - Na final

} Aluno;

int main() {

    FILE* entrada;
    FILE* saida;

    Aluno aluno;
    int total_alunos = 0, aprovados = 0, na_final = 0;
    float media_turma = 0, porcentagem_aprovados;

    entrada = fopen("exer10.txt", "r");
    saida = fopen("relatorio.txt", "w");

    if (entrada == NULL || saida == NULL) {
        printf("\nErro ao abrir um dos arquivos.\n");
        return 1;
    }
    else
        printf("\nArquivos abertos com sucesso.\n");

    fprintf(saida, "Nome\tMédia\tSituação\n");

    while (fscanf(entrada, "[^, ]", aluno.nome, &aluno.nota1, &aluno.nota2) == 3) {

        // Calcula a média do aluno
        aluno.media = (aluno.nota1 + aluno.nota2) / 2;

        // Verifica a situação do aluno
        if (aluno.media >= 7) {
            aluno.situacao = 1; // Aprovado
            aprovados++;
        } else if (aluno.media >= 4) {
            aluno.situacao = 2; // Na final
            na_final++;
        } else {
            aluno.situacao = 0; // Reprovado
        }

        // Escreve os dados do aluno no arquivo de saída
        fprintf(saida, "%s\t%.1f\t", aluno.nome, aluno.media);
        switch (aluno.situacao) {
            case 0:
                fprintf(saida, "Reprovado\n");
                break;
            case 1:
                fprintf(saida, "Aprovado\n");
                break;
            case 2:
                fprintf(saida, "Na final\n");
                break;
        }

        // Atualiza as variáveis de controle
        total_alunos++;
        media_turma += aluno.media;
    }

    porcentagem_aprovados = (float) aprovados / total_alunos * 100;

    media_turma = media_turma / total_alunos;

    saida = fopen("relatorio.txt", "w");
    fprintf(saida, "Media da Turma: %f", media_turma);
    fprintf(saida, "Porcentagem de Aprovados da Turma: %f", porcentagem_aprovados);

    fclose(entrada);
    fclose(saida);
}
