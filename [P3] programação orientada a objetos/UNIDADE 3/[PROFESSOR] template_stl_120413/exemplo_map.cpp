#include <iostream>
#include <map>
#include <string>

using std::cout;
using std::endl;
using std::map;
using std::string;

int main() {
	map<string, int> idades;

	idades["Maria"] = 22;
	idades["Jose"] = 33;
	idades["Ana"] = 44;
	idades["Joao"] = 55;

	cout << "Idade de Maria: " << idades["Maria"] << endl;

	for (const auto& par : idades) {
		const string& nome = par.first;
		int valor = par.second;
		cout << "Chave: " << nome << " Valor: " << valor << endl; 
	}

}
