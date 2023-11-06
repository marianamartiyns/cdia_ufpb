/* Exercício 2: Banco de Dados de Estudantes**

Crie uma classe `Estudante` que armazena informações como nome, idade e matrícula de um estudante.
Implemente um banco de dados de estudantes que permita adicionar, remover, listar e buscar estudantes pelo nome.
Utilize um `std::map` com o nome do estudante como chave. */

#include <iostream>
#include <string>
#include <map>

using std::string;
using std::cout;
using std::cin;
using std::endl;
using std::map;

class estudante {

	string nome;
	int idade;
	string matricula;

public:
	estudante(const string& n, int i, const string& m):
		  nome(n), idade(i), matricula(m) { }
	string& get_nome() { return nome; }
	int get_idade() { return idade; }
	string& get_matricula() { return matricula; }

	void print_info() {
		cout << "Nome: " << get_nome();
		cout << " | Matricula: " << get_matricula();
		cout << " | Idade: " << get_idade();
		cout << endl;
	}
};

class banco_de_dados {
	map<string, estudante*> estudantes;
public:
	void adicionar_estudante(const string& index, estudante* e) {
		estudantes[index] = e;
	}

	void listar_estudantes() {
		for (auto& par : estudantes) {
			cout << "Nome: " << par.second->get_nome();
			cout << " | Index: " << par.first;
			cout << " | Matricula: " << par.second->get_matricula();
			cout << " | Idade: " << par.second->get_idade();
			cout << endl;
		}

	}

	void remover_estudante(const string& index) {
		estudantes.erase(index);

	}

	estudante* buscar_estudante(const string& index) {
		auto it = estudantes.find(index);
		if (it != estudantes.end()) {
			return it->second;
		}
		return nullptr;
	}
};

int main(void) {

	banco_de_dados bd;
	string rm_est, sr_est;
	estudante ana("Ana Silva", 25, "1234");
	estudante bob("Bob Ferreira", 33, "3245");
	estudante joe("Joe Antunes", 32, "3455");

	bd.adicionar_estudante("ana", &ana);
	bd.adicionar_estudante("bob", &bob);
	bd.adicionar_estudante("joe", &joe);

	bd.listar_estudantes();

	cout << "Digite o indice de um estudante para remover: ";
	cin >> rm_est;

	bd.remover_estudante(rm_est);

	bd.listar_estudantes();

	cout << "Digite o indice de um estudante para localizar: ";
	cin >> sr_est;

	estudante* my_est = bd.buscar_estudante(sr_est);

	if (my_est) {
		cout << "Estudante encontrado!" << endl;
		my_est->print_info();
	} else {
		cout << "Estudante nao encontrado!" << endl;
	}

	return 0;

}
