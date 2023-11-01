#include <iostream>
#include <string>
#include <vector>

using std::cout;
using std::endl;
using std::string;
using std::vector;

/* Sistema de controle de estoque de produtos eletronicos */

template <typename T>
class produto {
	string nome;
	T descricao;
	int numero_serie;
	float preco;
	int quantidade_estoque;
public:
	produto(const string& n, const T d, int ns, float p, int qe):
		nome(n), descricao(d),numero_serie(ns),
		preco(p), quantidade_estoque(qe) { }

	void print_info() {
		cout << "produto" << endl;
		cout << " nome: " << nome << " | ";
		cout << "descricao: " << descricao << endl;
		cout << " N/S: " << numero_serie << " | ";
		cout << "preco: " << preco << " | ";
		cout << "quantidade estoque: " << quantidade_estoque << endl;
	}

	void set_preco(float p) {
		preco = p;
	}

	float get_preco() {
		return preco;
	}

	int get_quantidade_estoque() {
		return quantidade_estoque;
	}

	void add_estoque(int q) {
		quantidade_estoque += q;
	}

	void vender(int q) {
		quantidade_estoque -= q;
	}

};

class gerenciador_estoque {
	int contador_produtos;
	float valor_total;
	produto<string>* mais_caro;
	vector<produto<string>*> estoque;
	static gerenciador_estoque* _instance;

	gerenciador_estoque() {
		contador_produtos = 0;
		valor_total = 0;
		mais_caro = NULL;
	}
public:
	static gerenciador_estoque* get_instance() {
		if (_instance == NULL) {
			_instance = new gerenciador_estoque();
		}
		return _instance;
	}

	void add_produto(produto<string>* p) {
		estoque.push_back(p);
		contador_produtos += p->get_quantidade_estoque();
		valor_total += (p->get_quantidade_estoque()*p->get_preco());
		if ( (mais_caro == NULL) ||
		     (mais_caro->get_preco() < p->get_preco()) ) {
			mais_caro = p;
		}
	}

	produto<string>* get_mais_caro() {
		return mais_caro;
	}

	float get_valor_total() {
		return valor_total;
	}

	int get_contador_produtos() {
		return contador_produtos;
	}

	void list_produtos() {
		for (produto<string>* p : estoque) {
			p->print_info();
		}
	}

};

gerenciador_estoque* gerenciador_estoque::_instance = NULL;

int main(void) {
	gerenciador_estoque* ge = gerenciador_estoque::get_instance();

	produto<string>* p1 =
		new produto(string("celular"), string("celular bom"),
			    1234, 1000, 100);

	produto<string>* p2 =
		new produto(string("tablet"), string("tablet bom"),
			    4321, 2000, 50);

	produto<string>* p3 =
		new produto(string("notebook"), string("notebook show"),
			    5432, 5000, 10);

	ge->add_produto(p1);
	ge->add_produto(p2);
	ge->add_produto(p3);

	ge->list_produtos();

	cout << "Quantidade de produtos: " << ge->get_contador_produtos() << endl;
	cout << "Valor total do estoque: " << ge->get_valor_total() << endl;

	cout << "Info produto mais caro: ";
	ge->get_mais_caro()->print_info();

	return 0;
}
