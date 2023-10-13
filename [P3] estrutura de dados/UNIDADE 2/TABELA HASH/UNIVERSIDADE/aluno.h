// Supondo que queremos organizar alunos em uma estrutura e, posteriomente, fazer buscas pelo registro academico(ra)

#include <stdio.h>
#include <stdlib.h>
#include <string>

using namespace std;

class Aluno{

    int ra; //resgistro academico;
    string nome;

public:
    Aluno(); // construtor sem parametros para a alocação dinamica de memoria
    Aluno(int ra, string nome);
    string get_nome() const;
    int get_ra() const;
};

Aluno::Aluno (){
    this -> ra = -1; // a posição no vetor está vazia
    this -> nome = "";
};

Aluno::Aluno(int ra, string nome){
    this -> ra = ra;
    this -> nome = nome;
};

string Aluno:: get_nome() const { return nome; }
int Aluno::get_ra() const { return ra; }

