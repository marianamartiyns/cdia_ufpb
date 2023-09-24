#include <iostream>

#define QTD_PRINT 3

using std::cout;
using std::endl;

class printable {
public:
	virtual void print() = 0;
};

void call_print(printable& p) { //uso de referencia para classe abstrata
	p.print();
}

class produto : public printable { //funciona como uma interface
	float preco;
public:
	produto(float p):preco(p) { }
	float get_preco() { return preco; }
	void set_preco(float p) { preco = p; }
	virtual void print() {
		cout << "produto: " << preco << endl;
	}
};

class cliente : public printable {
	int idade;
public:
	cliente(int i):idade(i) { }
	int get_idade() { return idade; }
	void set_idade(int i) { idade = i; }
	virtual void print() {
		cout << "cliente: " << idade << endl;
	}
};

int main(void) {
	cliente c1(33);
	produto p1(10.5);

	call_print(c1);
	call_print(p1);


	return 0;
}
