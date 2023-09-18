#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

class dispositivo_eletronico {
	int serial;
public:
	dispositivo_eletronico(int s):serial(s) { }
	virtual void liga() {
		cout << "dev: " << serial << " liga()" << endl;

	}
	int get_serial() { return serial; }
	virtual void desliga() {
		cout << "dev: " << serial << " desliga()" << endl;
	}
	virtual ~dispositivo_eletronico() {
		cout << "~dispositivo_eletronico()" << endl;
	}
};

class televisao : public dispositivo_eletronico {
	int tamanho;
public:
	televisao(int s, int t):dispositivo_eletronico(s), tamanho(t) { }
	~televisao() { cout << "~televisao()" << endl; }
	void liga() {
		cout << "televisao::liga()" << endl;
		cout << "serial: " << get_serial() << ", ";
		cout << "tamanho: " << tamanho << endl;
	}
	void desliga() {
		cout << "televisao::desliga()" << endl;
		cout << "serial: " << get_serial() << endl;
	}

};

class smartphone : public dispositivo_eletronico {
	int sistema_operacional;
public:
	smartphone(int se, int so):dispositivo_eletronico(se), sistema_operacional(so) { } 
        ~smartphone() { cout << "~smartphone()" << endl; }
        void liga() {
                cout << "smartphone::liga()" << endl;
                cout << "serial: " << get_serial() << ", ";
                cout << "SO: " << sistema_operacional << endl;
        }
        void desliga() {
                cout << "smartphone::desliga()" << endl;
                cout << "serial: " << get_serial() << endl;
        }
};

int main(void) {
	vector<dispositivo_eletronico*> dispositivos;

	televisao* tv = new televisao(234234, 55);
	smartphone* sp = new smartphone(243456, 1);

	dispositivos.push_back(tv);
	dispositivos.push_back(sp);

	for (const auto& dispositivo: dispositivos) {
		dispositivo->liga();
		dispositivo->desliga();
		delete dispositivo;
	}

}

