#include <iostream>
#include <string>

using std::string;
using std::cin;
using std::cout;
using std::endl;

class animal {
	string nome;
	int idade;
protected:
	int codigo;
public:
	animal(const string& n, int i) {
		nome = n;
		idade = i;
		codigo = 0;
	}
	string get_nome() { return nome; }
	void set_nome(const string& n) {
		nome = n;
	}
	int get_idade() { return idade; }
	void set_idade(int i) {
		idade = i;
	}
	int get_codigo() {
		return codigo;
	}
	void print_info() {
		cout << "animal" << endl;
		cout << "nome: " << nome << endl;
		cout << "idade: " << idade << endl;
	}
};

class ave : public animal {
	float envergadura;
public:
	ave(const string& n, int i, float e) : animal(n, i) {
		envergadura = e;
		codigo = 1;
	}
	float get_envergadura() { return envergadura; }
	void set_envergadura(float e) { 
		envergadura = e;
	}
};

class mamifero : public animal {
	int pelagem;
public:
	mamifero(const string &n, int i, int p) : animal(n, i) {
		pelagem = p;
		codigo = 2;
	}
	int get_pelagem() { return pelagem; }
	void set_pelagem(int p) {
		pelagem = p;
	}
	void print_info() {
		cout << "mamifero" << endl;
		animal::print_info();
		cout << "pelagem: " << pelagem << endl;
	}
};

class papagaio : public ave {
	bool falante;
public:
        papagaio(const string& n, int i, float e, bool f) : ave(n, i, e) {
                falante = f;
		codigo = 3;
        }
	bool get_falante() { return falante; }
	void set_falante(bool f) {
		falante = f;
	}
	void print_info() {
		cout << "papagaio" << endl;
		cout << "nome: " << get_nome() << endl;
		cout << "idade: " << get_idade() << endl;
		cout << "engergadura: " << get_envergadura() << endl;
		cout << "falante: " << falante << endl;
	}
};

class gato : public mamifero {
	float tam_garra;
public:
        gato(const string& n, int i, int p, float t) : mamifero(n, i, p) {
                tam_garra = t;
		codigo = 4;
        }
	float get_tam_garra() { return tam_garra; }
	void set_tam_garra(float t) {
		tam_garra = t;
	}
	void print_info() {
		cout << "gato" << endl;
		mamifero::print_info();
		cout << "tam_garra: " << tam_garra << endl;
	}
};

class arara : public ave {
	float tam_bico;
public:
	arara(const string& n, int i, float e, float t) : ave(n, i, e) {
		tam_bico = t;
	}
	float get_tam_bico() { return tam_bico; }
	void set_tam_bico(float t) {
		tam_bico = t;
	}
	void print_info() {
		cout << "arara" << endl;
		cout << "nome: " << get_nome() << endl;
		cout << "idade: " << get_idade() << endl;
		cout << "envergadura: " << get_envergadura() << endl;
		cout << "tam_bico: " << get_tam_bico() << endl;
	}
};

class cachorro : public mamifero {
	bool adestrado;
public:
	cachorro(const string& n, int i, int p, bool a) : mamifero(n, i, p) {
		adestrado = a;
	}
	bool get_adestrado() { return adestrado; }
	void set_adestrado(bool a) {
		adestrado = a;
	}
	void print_info() {
		cout << "cachorro" << endl;
		mamifero::print_info();
		cout << "adestrado: " << adestrado << endl;
	}
};

int main(void) {
	animal a1("toto", 5);
	gato g1("mimi", 3, 1, 0.8);
	papagaio p1("loro", 8, 10.8, true);
	cachorro c1("lulu", 12, 6, false);
	arara ar1("lili", 7, 12.5, 3.5);

	animal* pa1;

/*
	int x;

	cin >> x;

	if (x % 2 == 0) {
		pa1 = &g1;
	} else {
		pa1 = &p1;
	}

	pa1->print_info();
	pa1->set_idade(10);
	pa1->print_info();
*/


	a1.print_info();
	g1.print_info();
	cout << "codigo gato: " << g1.get_codigo() << endl;
	p1.print_info();
	cout << "codigo papagaio: " << p1.get_codigo() << endl;
	c1.print_info();
	cout << "codigo cachorro: " << c1.get_codigo() << endl;
	ar1.print_info();
	cout << "codigo arara: " << ar1.get_codigo() << endl;

	return 0;
}

