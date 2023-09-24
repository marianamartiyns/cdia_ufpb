#include <iostream>

using std::cout;
using std::endl;

class animal {
	int idade;
public:
	animal(int i):idade(i) {}
	int get_idade() { return idade; }
	void set_idade(int i) { idade = i; }
	void print_info() {
		cout << "animal" << endl;
		cout << "idade: " << idade << endl;
	}
};

class ave : public animal {
	double envergadura;
public:
	ave(double e, int i):envergadura(e),animal(i) {}
	double get_envergadura() { return envergadura; }
	void set_envergadura(double e) { envergadura = e; }
/*
	void print_info() {
		cout << "ave" << endl;
		cout << "env: " << envergadura << endl;
	}
*/
};

class mamifero : public animal {
	int pelagem;
public:
	mamifero(int p, int i):pelagem(p),animal(i) {}
	int get_pelagem() { return pelagem; }
	void set_pelagem(int p) { pelagem = p; }
/*
	void print_info() {
		cout << "mamifero" << endl;
		cout << "pel: " << pelagem << endl;
	}
*/
};

class ornitorrinco : public ave, public mamifero {
	int tipo_bico;
public:
	ornitorrinco(int t, int p, double e, int i)
			:tipo_bico(t), mamifero(p, i), ave(e, i) {}
	int get_tipo_bico() { return tipo_bico; }
	void set_tipo_bico(int t) { tipo_bico = t; }

};

int main(void) {
	ornitorrinco o1(10, 11, 20.5, 5);

	o1.ave::print_info();
	o1.mamifero::print_info();
	//o1.print_info();


};
