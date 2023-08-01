#include <stdio.h>
#include <stdlib.h>

#define TAM_NOME 40
#define ARG_COUNT 3

typedef struct {
	char nome[TAM_NOME];
	int matricula;
	float cra;
} t_aluno;

typedef struct {
	char nome[TAM_NOME];
	int cod_departamento;
	int ano_titulacao;
} t_professor;

typedef struct {
	t_aluno* alunos;
	t_professor* prof;
	int tam_turma;
	int sala;
} t_turma;

void cadastra_aluno(t_aluno *a) {
	printf("Digite o nome do aluno: ");
	scanf("%*c%[^\n]", a->nome);
	printf("Digite a matricula do aluno: ");
	scanf("%d", &a->matricula);
	printf("Digite o CRA do aluno: ");
	scanf("%f", &a->cra);
}

void exibe_aluno(t_aluno *a) {
	printf("Nome: %s\n", a->nome);
	printf("Matricula: %d\n", a->matricula);
	printf("CRA: %f\n", a->cra);
}

void cadastra_professor(t_professor* p) {
        printf("Digite o nome do professor: ");
        scanf("%*c%[^\n]", p->nome);
        printf("Digite o codigo do departamento: ");
        scanf("%d", &p->cod_departamento);
        printf("Digite o ano da titulacao: ");
        scanf("%d", &p->ano_titulacao);
}

void exibe_professor(t_professor* p) {
	printf("Professor\n");
        printf("Nome: %s\n", p->nome);
        printf("Cod. Departamento: %d\n", p->cod_departamento);
        printf("Ano titulacao: %d\n", p->ano_titulacao);
}

void associa_professor_turma(t_turma* t, t_professor* p) {
        t->prof = p;
}

void cadastra_turma(t_turma* t, int tam) {
	printf("Cadastrando turma com %d alunos...\n", tam);
	t->prof = (t_professor*) malloc(sizeof(t_professor));
	cadastra_professor(t->prof);
	t->alunos = (t_aluno*) malloc(sizeof(t_aluno) * tam);
	t->tam_turma = tam;
	for (int i = 0; i < tam; i++) {
		cadastra_aluno(&t->alunos[i]);
	}

	printf("Digite o numero da sala: ");
	scanf("%d", &t->sala);
}

void exibe_turma(t_turma* t) {
	printf("Sala: %d\n", t->sala);
	exibe_professor(t->prof);
	printf("Alunos\n");
	for (int i = 0; i < t->tam_turma; i++) {
		exibe_aluno(&t->alunos[i]);
	}
}

void exibe_media_turma(t_turma* t) {
	float soma = 0;
	for (int i = 0; i < t->tam_turma; i++) {
		soma += t->alunos[i].cra;
	}
	printf("Media da turma: %.2f\n", ((float)soma/t->tam_turma));


}

int main(int argc, char** argv) {
	t_turma* turmas;
	int tam_turma = 0;
	int qtd_turmas = 0;

	t_turma turma1;

	exibe_media_turma(&turma1);
	
	if (argc != ARG_COUNT) {
		printf("Use: %s <QUANTIDADE_TURMAS> <NUMERO_DE_ALUNOS>\n", argv[0]);
		exit(0);
	} else {
		qtd_turmas = atoi(argv[1]);
		tam_turma = atoi(argv[2]);
		turmas = (t_turma*) malloc(sizeof(t_turma) * qtd_turmas);
		for (int i = 0; i < qtd_turmas; i++) {
			cadastra_turma(&turmas[i], tam_turma);
			exibe_turma(&turmas[i]);
			exibe_media_turma(&turmas[i]);
		}
	}

	for (int i = 0; i < qtd_turmas; i++) {
		free(turmas[i].alunos);
		free(turmas[i].prof);
	}
	

	return 0;
}
