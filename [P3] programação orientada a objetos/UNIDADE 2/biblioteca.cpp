#include <iostream>
#include <string>
using namespace std;

class usuario {

    string nome;
    int idade;

public:

    usuario(string n, int i) : nome(n), idade(i) {};

    string get_nome(){ return nome;};
    int get_idade() { return idade; };

    void set_nome(const string& n){ nome = n;};
    void set_idade(int i){idade = i;};

    virtual void exibir_detalhes()const = 0;
    virtual string tipo_usuario() const = 0;

    //sobrecarga

    friend ostream& operator<<(ostream& os, const usuario& u){
        os << "Nome: " << u.nome << endl;
        os << "Idade: " << u.idade << endl;
        os << "Tipo de Usuário: " << u.tipo_usuario() << endl;
        return os;
    }
};

class estudante : public usuario{

    int matricula;
    string curso;

public:
    estudante(string n, int i, int m, string c): usuario(n, i), matricula(m), curso(c){}

    int get_matricula(){ return matricula; }
    string get_curso(){ return string; }

    void set_matricula(int m){ matricula = m;}
    void set_curso(const string& c) {curso = c;}

    void exibir_detalhes() const override {
        cout << "Matricula: " << matricula << "\nCurso: " << curso << endl; }

    string tipo_usuario() const override {return "Estudante"; }
};

class professor : public usuario{

    int departamento;

public:
    professor(string n, int i, int dep) : usuario(n, i), departamento(dep){}

    int get_departamento(){ return departamento;}
    void set_departamento(int dep){ departamento = dep;}

    void exibir_detalhes() const override{
        usuario:: print_info();
        cout << "Departamento: " << departamento << endl; }



};


