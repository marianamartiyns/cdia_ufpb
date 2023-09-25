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

    //sobrecarga
    friend ostream& operator<<(ostream& os, const usuario& u){
        os << "Nome: " << u.nome << endl;
        os << "Idade: " << u.idade << endl;
        return os;
    }

    virtual string tipo_usuario() const = 0;
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
        cout << "Tipo de usuario: Estudante." << endl;
        cout << "Matricula: " << matricula << "\nCurso: " << curso << endl; }

    string tipo_usuario() const override {return "Estudante"; }

    friend ostream& operator<<(ostream& os, const estudante& est) {
        os << static_cast<const usuario&>(est); // Chama a sobrecarga da classe base
        est.exibir_detalhes();
        return os;
};

class professor : public usuario{

    int departamento;

public:
    professor(string n, int i, int dep) : usuario(n, i), departamento(dep){}

    int get_departamento(){ return departamento;}
    void set_departamento(int dep){ departamento = dep;}

    void exibir_detalhes() const override{
        cout << "Tipo de usuario: Professor." << endl;
        cout << "Departamento: " << departamento << endl; }

    string tipo_usuario() const override {return "Professor"; }

    friend ostream& operator<< (ostream& os, const professor& prof){
        os << static_cast < const usuario& > (prof);
        prof.exibir_detalhes();
        return os;
    }
};

class material{

    string titulo;

public:
    material(string t) : titulo(t) {}

    string get_titulo() {return titulo; }
    void set_titulo(const string& t){ titulo = t; }

    virtual exibir_detalhes() const = 0;

    friend ostream& operator << (ostream& os, const material& mat){
        os << "Material: " << mat << endl;
        return os;
    }
};

class livro : public material {

    string autor;
    int ano_publicacao;

public:
    livro(string t, string a, int ap) : material(t), autor(a), ano_publicacao(ap){}

    string get_autor(){ return autor; }
    int get_ano(){return ano; }

    void set_autor(const string& a){ autor = a; }
    voit set_ano_publicacao(int a){ ano = a; }

    void exibir_detalhes() const override {
        cout << "Autor: " << autor << endl;
        cout << "Ano de publicacao: " << ano_publicacao << endl;
    }

    friend ostream& operator ( ostream& os, const livro& l){
        os << static_cast < const material& (l);
        l.exibir_detalhes();
        return os;
    }
};

class revista


