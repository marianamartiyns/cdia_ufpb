// Supondo que queremos organizar alunos em uma estrutura e, posteriomente, fazer buscas pelo registro academico(ra)

#include <stdio.h>
#include <stdlib.h>
#include <string>

using namespace std;

class Aluno{

    int ra; //resgistro academico;
    string nome;

public:
    Aluno(); // construtor sem parametros para a alocacao dinamica de memoria
    Aluno(int ra, string nome);
    string get_nome() const;
    int get_ra() const;
};

Aluno::Aluno (){
    this -> ra = -1; // a posicao no vetor esta vazia
    this -> nome = "";
};

Aluno::Aluno(int ra, string nome){
    this -> ra = ra;
    this -> nome = nome;
};

string Aluno:: get_nome() const { return nome; }
int Aluno::get_ra() const { return ra; }


class Hash{

private:
    int get_hash(Aluno aluno);
    int max_items;
    int length;
    Aluno* structure; // um vetor de objetos aluno

public:
    Hash(int max_items = 100);
    ~Hash();
    bool is_full() const;
    int get_length() const;

    void retrieve_item(Aluno& aluno, bool& found);
    void insert_item(Aluno aluno);
    void delete_item(Aluno aluno);
    void print();
};
