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
    int quantidade_estoque;

public:

    produto(const string& n, const T& d, int ns, float p, int qe) : nome(n), descricao(d), numero_serie(ns), preco(p), quantidade_estoque(qe) {}

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
        cout << "Produto: " << nome << endl;
        cout << "Descrição: " << descricao << endl;
        cout << "Número de Série: " << numero_serie << endl;
        cout << "Preço: " << preco << endl;
        cout << "Quantidade em Estoque: " << quantidade_estoque << endl;
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

class cliente {

    string nome;
    int id;
    vector<produto*> carrinho;
    svector<produto*> historico_compras;

public:
    cliente(const string& n, int id) : nome(n), id(id) {}

    // Método para adicionar produtos ao carrinho de compras
    void adicionar_ao_carrinho(produto* p) {
        carrinho.push_back(p);
        cout << "Produto adicionado ao carrinho: " << p->get_nome() << endl;
    }

    // Método para finalizar uma compra
    void finalizar_compra() {

        if (carrinho.empty()) {
            cout << "Carrinho vazio. Nenhuma compra realizada." << endl;
            return;
        }

        cout << "Compra finalizada para o cliente " << nome << " (ID: " << id << "). Itens comprados:" << endl;
        for (produto* p : carrinho) {

            historico_compras.push_back(p);
            cout << " - " << p->get_nome() << endl;
        }
        carrinho.clear(); // Limpar o carrinho após a compra
    }

    // Getter para o histórico de compras
    const std::vector<produto*>& get_historico_compras() const {
        return historico_compras;
    }
};


/* 4. **Classe `loja`**:

    - Crie uma classe chamada `loja` que represente a loja de eletrônicos.
    - Implemente um método para atender um cliente, permitindo que o cliente adicione produtos ao carrinho e finalize a compra.

Implemente o sistema de gerenciamento de estoque conforme os requisitos acima,
incorporando tratamento de exceções para lidar com situações de erro, como preços inválidos, estoque insuficiente e operações inválidas. */

class loja {

     gerenciador_estoque* estoque;

public:
    loja(gerenciador_estoque* ge) : estoque(ge) {}

    // Método para atender um cliente
    void atender_cliente(cliente* c) {
        cout << "Bem-vindo à nossa loja, " << c->get_nome() << " (ID: " << c->get_id() << ")!" << endl;
        cout << "Produtos disponíveis para compra:" << endl;

        estoque->list_produtos(); // Listar os produtos disponíveis no estoque

        // O cliente pode adicionar produtos ao carrinho
        string escolha;
        do {
            cout << "Digite o nome do produto que deseja adicionar ao carrinho (ou 'sair' para finalizar): ";
            cin >> escolha;
            if (escolha == "sair") {
                break;
            }

            produto* p = estoque->encontrar_produto_por_nome(escolha);
            if (p) {
                c->adicionar_ao_carrinho(p);
            } else {
                cout << "Produto não encontrado no estoque. Por favor, escolha um produto válido." << endl;
            }
        } while (true);

        // O cliente pode finalizar a compra
        c->finalizar_compra();

        cout << "Obrigado por sua compra, " << c->get_nome() << " (ID: " << c->get_id() << ")!" << endl;
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

	delete p1;
    delete p2;
    delete p3;

	return 0;
}
















