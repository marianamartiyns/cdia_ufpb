#include <iostream>

#define QTD_ANIMAIS 3

using std::cout;
using std::endl;
using std::cin;

class animal {
	int idade;
public:
	animal(int i) {
		idade = i;
	}
	int get_idade() {
		return idade;
	}
	void set_idade(int i) {
		idade = i;
	}
	virtual void fazer_barulho() = 0;
};

class cachorro : public animal {
	int latido;
public:
	cachorro(int i, int l):animal(i), latido(l) { }
	int get_latido() {
		return latido;
	}
	void set_latido(int l) {
		latido = l;
	}
	virtual void fazer_barulho() {
		cout << "cachorro latindo: " << latido << endl;
	}
};

class gato : public animal {
	int miado;
public:
	gato(int i, int m):animal(i), miado(m) { }
	int get_miado() {
		return miado;
	}
	void set_miado(int m) {
		miado = m;
	}
	virtual void fazer_barulho() {
		cout << "gato miando: " << miado << endl;
	}
};

int main(void) {
	animal* zoo[QTD_ANIMAIS];

	for (int i = 0; i < QTD_ANIMAIS; i++) {
		int read;
		cout << "Digite 1 para cachorro, 2 para gato: ";
		cin >> read;
		if (read == 1) {
			int id, la;
			cout << "Digite a idade do cachorro: ";
			cin >> id;
			cout << "Digite o indice do latido do cachorro: ";
			cin >> la;
			zoo[i] = new cachorro(id, la);
		} else if (read == 2) {
			int id, mi;
			cout << "Digite a idade do gato: ";
			cin >> id;
			cout << "Digite o indice do miado do gato: ";
			cin >> mi;
			zoo[i] = new gato(id, mi);
		}
	}

	for (int i = 0; i < QTD_ANIMAIS; i++) {
		zoo[i]->fazer_barulho();
	}

	return 0;
}
