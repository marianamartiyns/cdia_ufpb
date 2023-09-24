#include <iostream>

#define QTD_POLIGONOS 3
#define PI 3.1415

using std::cout;
using std::cin;
using std::endl;

class poligono {
public:
	virtual float area() = 0;
	virtual void desenha() = 0;
};

class circulo : public poligono {
	float raio;
public:
	circulo(float r):raio(r) { }
	float get_raio() { return raio; }
	void set_raio(float r) { raio = r; }
	float area() {
		return (PI * (raio*raio));
	}
	void desenha() {
		cout << "circulo: " << raio << endl;
	}
};

class retangulo : public poligono {
	float base, altura;
public:
	retangulo(float b, float a):base(b), altura(a) {}
	float get_base() { return base; }
	void set_base(float b) { base = b; }
	float get_altura() { return altura; }
	void set_altura(float a) { altura = a; }
	float area() {
		return base*altura;
	}
	void desenha() {
		cout << "retangulo: " << base << ", ";
		cout << altura << endl;
	}
};

class triangulo : public poligono {
	float base, altura;
public:
	triangulo(float b, float a):base(b), altura(a) { }
        float get_base() { return base; }
        void set_base(float b) { base = b; }
        float get_altura() { return altura; }
        void set_altura(float a) { altura = a; }
        float area() {
                return (base*altura)/2;
        }
        void desenha() {
                cout << "triangulo: " << base << ", ";
                cout << altura << endl;
        }
};

poligono* cria_poligono() {
	int num;
	cout << "Digite 1 para circulo, 2 para retangulo e 3 para triangulo: ";
	cin >> num;
	switch(num) {
		case 1: {
			float r;
			cout << "Digite o raio: ";
			cin >> r;
			return new circulo(r);
			break;
		}
		case 2: {
			float b, a;
			cout << "Digite a base: ";
			cin >> b;
			cout << "Digite a altura: ";
			cin >> a;
			return new retangulo(b,a);
			break;

		}
		case 3: {
                        float b, a;
                        cout << "Digite a base: ";
                        cin >> b;
                        cout << "Digite a altura: ";
                        cin >> a;
			return new triangulo(b,a);
			break;
		}
		default: return NULL;
	}
	return NULL;
}

int main(void) {
	poligono* poli[QTD_POLIGONOS];
	//solicitem informacoes para que o usuario crie os objetos de acordo

	//exibir informacoes de todos os poligonos (area e desenho)

	for (int i = 0; i < QTD_POLIGONOS; i++) {
		poli[i] = cria_poligono();
	}

	for(int i = 0; i < QTD_POLIGONOS; i++) {
		poli[i]->desenha();
		cout << "area: " << poli[i]->area() << endl;
	}

	return 0;
}
