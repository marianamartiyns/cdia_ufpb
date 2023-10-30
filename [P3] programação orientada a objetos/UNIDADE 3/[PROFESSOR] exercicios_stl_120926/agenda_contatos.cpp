#include <iostream>
#include <vector>
#include <string>

using std::string;
using std::vector;
using std::cout;
using std::endl;
using std::cin;

class contato {
	string nome;
	string telefone;
	string email;
public:
	contato(const string& n, const string& t, const string& e):
		nome(n), telefone(t), email(e) { }

	string get_nome() { return nome; }
	string get_telefone() { return telefone; }
	string get_email() { return email; }
	/* sets */
};

class agenda {
	vector<contato> contatos;
public:
	void adicionar_contato(const contato& c) {
		contatos.push_back(c);
	}

	void listar_contatos() {
		for (contato& c: contatos) {
			cout << "Nome: " << c.get_nome();
			cout << " | Telefone: " << c.get_telefone();
			cout << " | E-mail: " << c.get_email() << endl;
		}
	}

	void remover_contato(const string n) {
		for (auto it = contatos.begin(); it != contatos.end(); ) {
			if ((*it).get_nome() == n) {
				it = contatos.erase(it); //remove elemento
							// e avanca iterador
			} else {
				++it;
			}
		}
	}
};

int main(void) {
	agenda minha_agenda;

	minha_agenda.adicionar_contato(contato("Ana", "2345678", "ana@domain.com"));
	minha_agenda.adicionar_contato(contato("Bob", "9999999", "bob@example.com"));
	minha_agenda.adicionar_contato(contato("Oscar", "98898898", "oscar@aa.com"));

	minha_agenda.listar_contatos();

	cout << "Removendo Bob..." << endl;

	minha_agenda.remover_contato("Bob");

	cout << endl;

	minha_agenda.listar_contatos();

	return 0;

}




