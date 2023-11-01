/* Exercício 1: Sistema de Gerenciamento de Contatos

Crie uma classe `Contato` que armazena informações de nome, telefone e email de uma pessoa.
Implemente um sistema de gerenciamento de contatos que permita adicionar, remover e listar contatos.
Utilize um `std::vector` para armazenar os objetos `Contato`. */

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class contato {

    string nome;
    string telefone;
    string email;

public:

    contato(const string& n, const string& t, const string& e) : nome(n), telefone(t), email(e) {}

    string get_nome(){ return nome; }
    string get_telefone() { return telefone; }
    string get_email() { return email; }

    void set_nome(string n) { nome = n ;}
    void set_telefone(string t){ telefone = t; }
    void set_email(string e) { email = e; }

};

class agenda {

    vector <contato> contatos;
public:

    void adicionar_contato(const contato& c) {
        contatos.push_back(c);
    }

    void listar_contatos(){
        for (contato& c: contatos){
            cout << "Nome: " << c.get_nome();
            cout << " | Telefone: " << c.get_telefone();
            cout << " | E-mail: " << c.get_email() << endl;
        }
    }

    void remover_contato(const string n) {

        for (auto it = contatos.begin(); it != contatos.end(); ) {

                if ((*it).get_nome() == n) {
                        it = contatos.erase(it); //remove elemento
                } else { ++ it; }
        }
    }
};

int main(void) {

    agenda minha_agenda;

    minha_agenda.adicionar_contato(contato("Mariana", "45678965", "mariana@gmail.com"));
    minha_agenda.adicionar_contato(contato("Jeova", "839362456", "jeova123@gmail.com"));
    minha_agenda.adicionar_contato(contato("Felipe", "3456781", "felly@gmail.com"));
    minha_agenda.adicionar_contato(contato("Cleydson", "2678123", "juninhoclay@gmail.com"));

    minha_agenda.listar_contatos();

    cout << endl;
    cout << "Removendo Contato..." << endl;
    minha_agenda.remover_contato("Cleydson");
    cout << endl;

    minha_agenda.listar_contatos();

return 0; }
