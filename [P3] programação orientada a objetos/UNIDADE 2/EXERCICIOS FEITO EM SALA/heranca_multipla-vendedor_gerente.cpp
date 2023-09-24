#include <iostream>

using std::cout;
using std::endl;

class vendedor {
	double meta;
public:
	vendedor(double m):meta(m) {}
	double get_meta() { return meta; }
	void set_meta(double m) { meta = m; }
	void print_info() {
		cout << "vendedor" << endl;
		cout << "meta: " << meta << endl;
	}
};

class gerente {
	int departamento;
public:
	gerente(int d):departamento(d) {}
	int get_departamento() { return departamento; }
	void set_departamento(int d) { departamento = d; }
	void print_info() {
		cout << "gerente" << endl;
		cout << "dep: " << departamento << endl;
	}
};

class vendedor_gerente : public vendedor, public gerente {
	int codigo;
public:
	vendedor_gerente(int c, double m, int d):
				codigo(c), vendedor(d), gerente(m) {}
	int get_codigo() { return codigo; }
	void set_codigo(int c) { codigo = c; }
	void print_info() {
		cout << "gerente/vendedor" << endl;
		gerente::print_info();
		vendedor::print_info();

	}
};

int main(void) {
	vendedor_gerente vg(10, 15500.50, 90);

	vg.vendedor::print_info();
	vg.gerente::print_info();
	cout << endl;
	vg.print_info();

	return 0;
}
