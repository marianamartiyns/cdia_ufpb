#include <iostream>

#define QTD_VEICULOS 3

using std::cout;
using std::endl;
using std::cin;

class veiculo {
	int ano;
public:
	veiculo(int a) {
		ano = a;
	}
	virtual ~veiculo() { cout << "~veiculo()" << endl; }
	virtual void movimentar() = 0;
};

class carro : public veiculo {
	int* valvulas;
	int qtd_valvulas;
public:
	carro(int a, int q):veiculo(a) {
		qtd_valvulas = q;
		valvulas = new int[q];
	}
	~carro() {
		cout << "~carro()" << endl;
		delete valvulas;
	}
	int* get_valvulas() {
		return valvulas;
	}
	int get_valvula(int idx) {
		if (idx < qtd_valvulas) {
			return valvulas[idx];
		} else {
			return -1;
		}
	}
	void set_valvula(int idx, int v) {
		if (idx < qtd_valvulas) {
			valvulas[idx] = v;
		}
	}
	virtual void movimentar() {
		cout << "carro::movimentar()" << endl;
		for (int i = 0; i < qtd_valvulas; i++) {
			cout << "v[" << i << "] = " << valvulas[i] << endl;
		}
	}
};

class lancha : public veiculo {
	float tamanho;
public:
	lancha(int a, float t):veiculo(a), tamanho(t) { }
	~lancha() { cout << "~lancha()" << endl; };
	float get_tamanho() { return tamanho; }
	void set_tamanho(float t) { tamanho = t; }
	void movimentar() {
		cout << "lancha::movimentar()" << endl;
		cout << "t = " << tamanho << endl;
	}
};

int main(void) {
	veiculo* v[QTD_VEICULOS];

	for (int i = 0; i < QTD_VEICULOS; i++) {
		int num;
		cout << "Digite 1 para carro, 2 para lancha: ";
		cin >> num;
		if (num == 1) {
			int a, va;
			cout << "Digite o ano do carro: ";
			cin >> a;
			cout << "Digite a quantidade de valvulas: ";
			cin >> va;
			v[i] = new carro(a, va);
		} else if (num == 2) {
			int a;
			float t;
			cout << "Digite o ano da lancha: ";
			cin >> a;
			cout << "Digite o tamanho em pes: ";
			cin >> t;
			v[i] = new lancha(a, t);
		}
	}

	for (int i = 0; i < QTD_VEICULOS; i++) {
		v[i]->movimentar();
	}

	for (int i = 0; i < QTD_VEICULOS; i++) {
		delete v[i];
	}


	return 0;
}
