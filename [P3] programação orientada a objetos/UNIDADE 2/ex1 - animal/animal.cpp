#include <iostream>
#include <string>

using namespace std;

class animal{

    string nome;
    int idade;

    public:

    animal(string n, int id){
        nome = n;
        idade = id;
    };

    string get_nome(){ return nome; };
    int get_idade(){ return idade; };

    void set_nome(const string& n){
        nome = n;
    };

    void set_idade(int i){
        i = idade;
    };

    void print_info(){
        cout << "Nome: " << nome << endl;
        cout << "Idade: " << idade << endl;
    };
};

class papagaio : public animal {

    float envergadura;
    bool falante;

    public:

    papagaio(const string& n, int i, float e, bool f) : animal(n, i){
        envergadura = e;
        falante = f;
    };

    float get_envergadura(){ return envergadura; };
    bool get_falante(){ return falante; };

    void set_envergadura(float e){
        envergadura = e;
    };

    void set_falante(bool f){
        falante = f;
    };

    void print_info(){
        cout << "Nome: " << get_nome() << endl;
        cout << "Idade: " << get_idade() << endl;
        cout << "Envergadura: " << envergadura << endl;
        cout << "Falante: " << falante << endl;
    };

};

class gato : public animal {

    string pelagem;
    float tam_garras;

    public:

    gato(const string& n, int i, string p, float g) : animal(n, i){
        pelagem = p;
        tam_garras = g;
    };

    string get_pelagem(){ return pelagem; };
    float get_tam_garras(){ return tam_garras; };

    void set_pelagem(const string& p){
        pelagem = p;
    };

    void set_tam_garras(float g){
        tam_garras = g;
    };

    void print_info(){
        cout << "Nome: " << get_nome() << endl;
        cout << "Idade: " << get_idade() << endl;
        cout << "Pelagem: " << pelagem << endl;
        cout << "Tamanho das garras: " << tam_garras << endl;
    };
};

// ************************
class arara: public animal{

    float envergadura;
    int tam_bico;

public:

    arara(string n, int i, int t, float e): animal(n, i){
        tam_bico = t;
        envergadura = e;
    };

    int get_tam_bico() { return tam_bico; };
    float get_envergadura() {return envergadura;};

    void set_tam_bico(int t){
        tam_bico = t;
    };

    void set_envergadura(float e){
        envergadura = e;
    };

    void print_info(){
        cout << "Nome: " << get_nome() << endl;
        cout << "Idade: " << get_idade() << endl;
        cout << "Envergadura: " << envergadura << endl;
        cout << "Tamanho do Bico: " << tam_bico << endl;
    }
};

class cachorro : public animal{

    string pelagem;
    bool adestrado;

public:

    cachorro(string n, int i, string p, bool a): animal( n, i){
        pelagem = p;
        adestrado = a;
    };

    string get_pelagem(){return pelagem;};
    bool get_adestrado(){ return adestrado;};

    void set_pelagem(const string& p){
        pelagem = p;
    };

    void set_adestrado(bool a){
        adestrado = a;
    };

    void print_info(){
        cout << "Nome: " << get_nome() << endl;
        cout << "Idade: " << get_idade() << endl;
        cout << "Cor da Pelagem: " << pelagem << endl;
        cout << "Eh adestrado: " << adestrado << endl;
    };

};

int main(void) {

    animal a1("pedrinha", 13);
    papagaio p1("sabido", 3, 13, true);
    gato g1("mingal", 5, "amarelo", 3);

    a1.print_info();
    cout << endl;
    p1.print_info();
    cout << endl;

    arara a("blue", 1, 23.4, 5);
    cachorro c("pedro", 4, "marrom", true);

    a.print_info();
    cout << endl;
    c.print_info();
    cout << endl;
};
