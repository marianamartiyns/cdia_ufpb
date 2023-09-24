// sobrecarga

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

    virtual void exibir_detalhes

};
