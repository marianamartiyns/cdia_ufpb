/*Sistema de Gerenciamento de Estoque em C++

Desenvolva um programa em C++ que simule um sistema de gerenciamento de estoque para uma loja de eletrônicos. O programa deve ser orientado a objetos e deve incorporar os seguintes recursos:*/


#include <iostream>
#include <string>
#include <vector>

using namespace std;

/* 1. **Classe `produto`**:

    - Crie uma classe chamada `produto` que represente um produto eletrônico com as seguintes informações:
        - Nome do produto.
	- Descrição do produto (representada como um tipo de dado flexível usando templates).
        - Número de série (único para cada produto).
        - Preço unitário.
        - Quantidade em estoque.

    - Implemente um construtor que inicialize as informações do produto, incluindo a descrição como um tipo flexível
    - Implemente métodos para:
        - Atualizar o preço unitário do produto.
        - Adicionar unidades ao estoque.
        - Vender unidades do produto. */

template <typename T>
class produto{

    string nome;
    T descricao;
    int numero_serie;
    float preco;
    int quant_estoque;

public:

    produto(const string& n, const string& T d, int ns, float p, int qe) : nome(n), descricao(d), numero_serie(ns), preco(p), quant_estoque(qe);

    // Getters
    string get_nome() {return nome;}
    T get_descricao() {return descricao;}
    int get_numero_serie() {return numero_serie;}
    float get_preco() {return preco;}
    int get_quantidade_estoque() {return quantidade_estoque;}

    // Setters
    void set_nome(const string& n) {nome = n;}
    void set_descricao(const T& d) { descricao = d;}
    void set_numero_serie(int ns) {numero_serie = ns;}
    void set_preco(float p) {preco = p; }
    void set_quantidade_estoque(int qe) { quantidade_estoque = qe;}

    void print_info() {
        cout << "Produto: " << endl;
        cout << "Nome: " << endl;
        cout << "Descricao: " << endl;
        cout << "Numero de Serie: " << endl;
        cout << "Preco: " << endl;
        cout << "Quantidade em Estoque: " << endl;
    }

    void add_estoque(int q) { quantidade_estoque += q;}
	void vender(int q) { quantidade_estoque -= q; }
};

/* 2. **Classe `gerenciador_estoque`**:

    - Crie uma classe de controle chamada `gerenciador_estoque` com métodos e atributos de classe (estáticos) para rastrear informações globais sobre o estoque, incluindo:
        - O número total de produtos no estoque.
        - O valor total do estoque.
        - O produto mais caro em estoque.

    - Utilize o padrão de projeto Singleton para garantir que apenas uma instância da classe `gerenciador_estoque` exista.

    - Implemente métodos estáticos para:
        - Adicionar um produto ao estoque.
        - Listar todos os produtos em estoque.
        - Calcular o valor total do estoque.
        - Encontrar o produto mais caro em estoque. */

class gerenciador_estoque {

	int contador_produtos;
	float valor_total;
	produto <string>* mais_caro;
	vector <produto<string>*> estoque;
	static gerenciador_estoque* _instance;

	gerenciador_estoque() {
		contador_produtos = 0;
		valor_total = 0;
		mais_caro = NULL;
	}

public:

	static gerenciador_estoque* get_instance() {
		if (_instance == NULL) {
			_instance = new gerenciador_estoque(); }
		return _instance;
	}

	void add_produto(produto<string>* p) {

		estoque.push_back(p);
		contador_produtos += p->get_quantidade_estoque();
		valor_total += (p->get_quantidade_estoque()*p -> get_preco());

		if ( (mais_caro == NULL) ||
		     (mais_caro->get_preco() < p->get_preco()) ) {
			mais_caro = p;
		}
	}

	produto <string>* get_mais_caro() { return mais_caro; }

	float get_valor_total() { return valor_total; }

	int get_contador_produtos() { return contador_produtos; }

	void list_produtos() {
		for (produto<string>* p : estoque) {
			p->print_info();
		}
	}

};

/* 3. **Classe `cliente`**:

    - Crie uma classe chamada `cliente` que represente um cliente da loja com as seguintes informações:
        - Nome do cliente.
        - ID do cliente.
        - Histórico de compras (utilize um contêiner da STL, como `vector`).

    - Implemente métodos para:
        - Adicionar produtos ao carrinho de compras.
        - Finalizar uma compra, que envolve a transferência dos produtos do carrinho para o histórico de compras do cliente. */



/* 4. **Classe `loja`**:

    - Crie uma classe chamada `loja` que represente a loja de eletrônicos.
    - Implemente um método para atender um cliente, permitindo que o cliente adicione produtos ao carrinho e finalize a compra.

Implemente o sistema de gerenciamento de estoque conforme os requisitos acima,
incorporando tratamento de exceções para lidar com situações de erro, como preços inválidos, estoque insuficiente e operações inválidas. */



















