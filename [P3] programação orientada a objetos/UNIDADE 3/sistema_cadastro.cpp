/*Sistema de cadastro de produtos

Crie uma classe produto que represente um produto gen�rico.
- campos: valor, codigo_barras, nome_fabricante

Crie uma classe produto_alimenticio que herde da classe produto.
- campos: data_validade, data_fabricacao

Crie uma classe produto_eletronico que herde da classe produto.
- campos: voltagem, potencia

Crie uma classe template estoque que represente uma estoque com multiplos
produtos (alimenticios ou eletronicos).
- A classe deve ter um campo int limite_armazenamento que representa o limite
de produtos no estoque.
- A classe deve ter um campo vector de produtos.
- A classe deve ter um m�todo adicionar_produto() que recebe como par�metro
um produto e o adiciona ao vector de produtos.
- A classe deve ter um m�todo calcular_valor_total() que calcula o valor total
do estoque com base nos produtos adicionados.

Sobrecarregue o operador << para imprimir as informa��es de um objeto da classe estoque.
Sobrecarregue o operador + para adicionar um produto ao estoque.
Sobrecarregue o operador - para remover um produto do estoque.

Crie uma fun��o friend template chamada transferir_produtos() que receba como par�metros
dois objetos da classe estoque (com o mesmo tipo template) e transfira todos os produtos
do primeiro estoque para o segundo estoque.

Adicione tratamento de exce��es ao c�digo para lidar com situa��es em que o usu�rio tente
adicionar produtos acima do limite do estoque (campo limite_armazenamento).

Crie uma funcao main que crie tr�s objetos da classe estoque, com pelo menos tr�s produtos
cada. Imprima as informa��es de cada estoque e transfira os produtos do primeiro estoque
para o segundo estoque. Imprima novamente as informa��es de cada estoque.*/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class produto {
public:
    double valor;
    string codigo_barras;
    string nome_fabricante;

    produto(double _valor, const string& _codigo_barras, const string& _nome_fabricante)
        : valor(_valor), codigo_barras(_codigo_barras), nome_fabricante(_nome_fabricante) {}
};

class produto_alimenticio : public produto {
public:
    string data_validade;
    string data_fabricacao;

    produto_alimenticio(double _valor, const string& _codigo_barras, const string& _nome_fabricante,
                       const string& _data_validade, const string& _data_fabricacao)
        : produto(_valor, _codigo_barras, _nome_fabricante), data_validade(_data_validade), data_fabricacao(_data_fabricacao) {}
};

class produto_eletronico : public produto {
public:
    string voltagem;
    double potencia;

    produto_eletronico(double _valor, const string& _codigo_barras, const string& _nome_fabricante,
                      const string& _voltagem, double _potencia)
        : produto(_valor, _codigo_barras, _nome_fabricante), voltagem(_voltagem), potencia(_potencia) {}
};

template <class T>
class estoque {
public:
    int limite_armazenamento;
    vector<T> produtos;

    estoque(int _limite_armazenamento) : limite_armazenamento(_limite_armazenamento) {}

    void adicionar_produto(const T& produto) {
        if (produtos.size() < limite_armazenamento) {
            produtos.push_back(produto);
        } else {
            throw out_of_range("Estoque cheio. N�o � poss�vel adicionar mais produtos.");
        }
    }

    double calcular_valor_total() const {
        double total = 0;
        for (const T& produto : produtos) {
            total += produto.valor;
        }
        return total;
    }

    friend ostream& operator<<(ostream& os, const estoque<T>& estoque) {
        os << "Limite de armazenamento: " << estoque.limite_armazenamento << endl;
        os << "Produtos no estoque:" << endl;
        for (const T& produto : estoque.produtos) {
            os << "C�digo de barras: " << produto.codigo_barras << ", Nome do fabricante: " << produto.nome_fabricante << endl;
        }
        return os;
    }

    estoque<T>& operator+(const T& produto) {
        adicionar_produto(produto);
        return *this;
    }

    estoque<T>& operator-(const T& produto) {
        produtos.erase(remove(produtos.begin(), produtos.end(), produto), produtos.end());
        return *this;
    }
};

template <class T>
void transferir_produtos(estoque<T>& estoque_origem, estoque<T>& estoque_destino) {
    for (const T& produto : estoque_origem.produtos) {
        estoque_destino.adicionar_produto(produto);
    }
    estoque_origem.produtos.clear();
}

int main() {
    estoque<produto_alimenticio> estoque_alimenticio(5);
    estoque<produto_eletronico> estoque_eletronico(5);
    estoque<produto_alimenticio> estoque_destino_alimenticio(10);

    produto_alimenticio p1(10.0, "12345", "Fabricante A", "2023-12-31", "2023-01-01");
    produto_alimenticio p2(15.0, "67890", "Fabricante B", "2023-11-30", "2023-01-15");
    produto_alimenticio p3(50.0, "54321", "Fabricante C", "220V", 1000.0);
    produto_alimenticio p4(70.0, "09876", "Fabricante D", "110V", 800.0);

    estoque_alimenticio + p1 + p2;
    estoque_eletronico + p3 + p4;

    cout << "Estoque Aliment�cio:" << endl << estoque_alimenticio << endl;
    cout << "Estoque Eletr�nico:" << endl << estoque_eletronico << endl;

    transferir_produtos(estoque_alimenticio, estoque_destino_alimenticio);
    cout << "Transfer�ncia de produtos realizada." << endl;

    cout << "Estoque Aliment�cio ap�s a transfer�ncia:" << endl << estoque_alimenticio << endl;
    cout << "Estoque de Destino Aliment�cio ap�s a transfer�ncia:" << endl << estoque_destino_alimenticio << endl;

    return 0;
}

