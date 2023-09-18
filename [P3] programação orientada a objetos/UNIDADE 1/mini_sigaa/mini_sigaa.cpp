#include <iostream>
#include <stdio.h>
#include <string.h>

#define TAM_NOME 40

class aluno {
        char nome[TAM_NOME];
        int matricula;
        float cra;
public:
	aluno(char* n, int m, float c) {
		strcpy(nome, n);
		matricula = m;
		cra = c;
	}
	void print_info() {
		printf("Aluno\n");
		printf("Nome: %s\n", nome);
		printf("Matricula: %d\n", matricula);
		printf("CRA: %.2f\n", cra);
	}
	float get_cra() {
		return cra;
	}
	void set_cra(float f) {
		cra = f;
	}
};

class professor {

        char nome[TAM_NOME];
        int cod_departamento;
        int ano_titulacao;

public: // as variaveis podem ser acessadas fora da classe.

	professor(char* n, int c, int a) {
		strcpy(nome, n);
		cod_departamento = c;
		ano_titulacao = a;
	}
	void print_info() { // metodo: uma ação/função que será executada
		printf("Professor\n");
                printf("Nome: %s\n", nome);
                printf("Cod. departamento: %d\n", cod_departamento);
                printf("Ano titulacao: %d\n", ano_titulacao);
	}
};

class turma {
        aluno* alunos;
        professor* prof;
        int tam_turma;
        int sala;
public:
	turma(aluno* a, professor* p, int t, int s) {
		alunos = a;
		prof = p;
		tam_turma = t;
		sala = s;
	}
	void print_info() {
		printf("Turma\n");
		printf("Sala: %d\n", sala);
		printf("Tamanho: %d\n", tam_turma);
		prof->print_info();
		for (int i = 0; i < tam_turma; i++) {
			alunos[i].print_info();
		}
	}
	void associa_professor(professor* p) {
		prof = p;
	}
	float media() {
		float soma = 0;
		for (int i = 0; i < tam_turma; i++) {
			soma += alunos[i].get_cra();
		}

		return ((float)soma/tam_turma);
	}
};

int main(void) {

	char nome_a1[TAM_NOME] = "Aluno 1";
	char nome_a2[TAM_NOME] = "Aluno 2";
	aluno a1(nome_a1, 111111, 9.5);
	aluno a2(nome_a2, 222222, 8.5);

	char nome_p1[TAM_NOME] = "Professor 1";
	professor p1(nome_p1, 1, 2021);

	aluno* alunos = (aluno*)malloc(sizeof(aluno) * 2);
	alunos[0] = a1;
	alunos[1] = a2;

	turma t1(alunos, &p1, 2, 7);

	t1.print_info();

	printf("Media turma: %.2f\n", t1.media());

	return 0;
}
