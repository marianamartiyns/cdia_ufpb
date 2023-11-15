#include <iostream>
#include <vector>
#include <map>
#include <stdexcept>

using namespace std;

class Fornecedor {

private: // dados privados da classe fornecedor
    string nome;
    string cnpj;

public:
    //construtorr
    Fornecedor(string nome, string cnpj) : nome(nome), cnpj(cnpj) {}

    //geterrs
    string get_nome() const { return nome; }
    string get_cnpj() const { return cnpj; }

    // setters
    void set_nome(string novoNome) { nome = novoNome; }
    void set_cnpj(string novoCnpj) { cnpj = novoCnpj; }

    // ~Fornecedor() {} (está como comentario pois na questão apenas sugere um destrutor em 'fabrica' e 'estoque'
};

class Calcado {

protected: // dados protegidos ao inves de privado para as outras subclasses poderem acessarem
    string marca;
    string modelo;
    string cor;
    int tamanho;
    double preco;
    Fornecedor* fornecedor;

public:
    //construtor
    Calcado(const string& marca, const string& modelo, const string& cor, int tamanho, double preco, Fornecedor* fornecedor)
        : marca(marca), modelo(modelo), cor(cor), tamanho(tamanho), preco(preco), fornecedor(fornecedor) {}

    virtual void exibirInfo() const = 0; // método virtual puro

    // getters
    string get_marca() const { return marca; }
    string get_modelo() const { return modelo; }
    string get_cor() const { return cor; }
    int get_tamanho() const { return tamanho; }
    double get_preco() const { return preco; }

    // setters
    void set_marca(string novaMarca) { marca = novaMarca; }
    void set_modelo(string novoModelo) { modelo = novoModelo; }
    void set_cor(string novaCor) { cor = novaCor; }
    void set_tamanho(int novoTamanho) { tamanho = novoTamanho; }
    void set_preco(double novoPreco) {
        if (novoPreco > 0) {
            preco = novoPreco; }
    }

    // virtual ~Calcado() {} (está como comentario pois na questão apenas sugere um destrutor em 'fabrica' e 'estoque'

};

class Tenis : public Calcado { // class sapato social herda publicamnete de calcado

private: // dados privados da classe tenis
    string tipoEsporte;

public:
    //construtor da classe tenis
    Tenis(string marca, string modelo, string cor, int tamanho, double preco, Fornecedor* fornecedor, string tipoEsporte)
        : Calcado(marca, modelo, cor, tamanho, preco, fornecedor), tipoEsporte(tipoEsporte) {}

    // classe para exibir dados - está sobrescrevendo o metodo virtual criado em calcado
    void exibirInfo() const override {
        cout << "Marca: " << marca << endl;
        cout << "Modelo: " << modelo << endl;
        cout << "Cor: " << cor << endl;
        cout << "Tamanho: " << tamanho << endl;
        cout << "Preço: " << preco << " R$" << endl;
        cout << "Tipo de Esporte: " << tipoEsporte << endl;
    }

    string get_tipoEsporte() const { return tipoEsporte; } //getter
    void set_tipoEsporte(string novoTipoEsporte) { tipoEsporte = novoTipoEsporte; } // setter

    // destrutor ~Tenis() {} (está como comentario pois na questão apenas sugere um destrutor em 'fabrica' e 'estoque'
};

class SapatoSocial : public Calcado { // class sapato social herda publicamnete de calcado

private: // dados privados da classe sapato social
    string material;

public:
    // construtor
    SapatoSocial(string marca, string modelo, string cor, int tamanho, double preco, Fornecedor* fornecedor, string material)
        : Calcado(marca, modelo, cor, tamanho, preco, fornecedor), material(material) {}

    string get_material() const { return material; } //getter
    void set_material(string novoMaterial) { material = novoMaterial; } // setter

    // classe para exibir dados - está 'override' o método virtual criado em calcado
    void exibirInfo() const override {
        cout << "Marca: " << marca << endl;
        cout << "Modelo: " << modelo << endl;
        cout << "Cor: " << cor << endl;
        cout << "Tamanho: " << tamanho << endl;
        cout << "Preço: " << preco << " R$" << endl;
        cout << "Material: " << material << endl;
    }

    // destrutor ~SapatoSocial() { } (está como comentario pois na questão apenas sugere um destrutor em 'fabrica' e 'estoque'

};

class Estoque {

private:
    vector<Calcado*> produtos; //vetor da classe calcados chamado "produtos"

public:

    // destrutor da classe ou seja do vetor criado nele
    ~Estoque() {
        for (Calcado* calcado : produtos) {
            delete calcado; }
    }

    //Tratamento de exceções -  o valor do produto só pode ser maior ou igual a zero.
    void adicionarProduto(Calcado* produto) {
        if (produto->get_preco() <= 0) {
            throw invalid_argument("Preço do produto deve ser positivo"); }
        produtos.push_back(produto);
    }

    void exibirProdutos() {
        for (Calcado* produto : produtos) {
            produto->exibirInfo();
            cout << endl;}
    }

    // remove um produto do estoque
    void removerProduto(const string& marca, const string& modelo){
    for( auto it = produtos.begin; it != produtos.end(), ++it){
            if ((*it) -> getMarca() == marca && (*it) -> getModelo() == modelo) {
                delete *it;
                produtos.erase(it);
                break;
            }
    }

};

class Fabrica { // (singleton)

private: // dados privados da class fabrica

    Fabrica() {} //construtor

    map<string, Fornecedor*> fornecedores;
    Estoque estoque;

public:

    // instância 'unica' da classe Fabrica
    static Fabrica& getInstance() {
        static Fabrica instance;
        return instance;
    }

    Fabrica(Fabrica const&) = delete;
    void operator=(Fabrica const&) = delete;

    //adicionar fornecedor
    void adicionarFornecedor(const string& cnpj, Fornecedor* fornecedor) {
        fornecedores[cnpj] = fornecedor; }

    // remover fornecedor
    void removerFornecedor(const string& cnpj) {
        vector<Calcado*>& produtos = estoque.getProdutos();
        auto it = find(cnpj);
        if (it != fornecedores.end()) {
            delete *it;
            fornecedores.erase(it);
        }
    }

    //adicionar produto ao estoque
    void adicionarProduto(Calcado* produto) {
        estoque.adicionarProduto(produto);}

    // Remover um produto do estoque
    void removerProduto(Calcado* produto) {
        vector<Calcado*>& produtos = estoque.getProdutos();
        auto it = find(produtos.begin(), produtos.end(), produto);
        if (it != produtos.end()) {
            delete *it;
            produtos.erase(it);
        }
    }

    //get
    Fornecedor* getFornecedor(const string& cnpj) {
        if (fornecedores.find(cnpj) != fornecedores.end()) {
            return fornecedores[cnpj];
        }
        return nullptr;
    }

    //destrutor
    ~Fabrica() {
        // Limpar os fornecedores
        for (auto& par : fornecedores) {
            delete par.second;
        }
};

int main() {

    Fornecedor fornecedor1("Fornecedor Clay", "CNPJ_C");
    Fornecedor fornecedor2("Fornecedor Felly", "CNPJ_F");

    Fabrica::getInstance().adicionarFornecedor("CNPJ_C", &fornecedor1);
    Fabrica::getInstance().adicionarFornecedor("CNPJ_F", &fornecedor2);

    Tenis tenis1("Nike", "Air Max", "Azul", 42, 199.99, Fabrica::getInstance().getFornecedor("CNPJ_C"), "Running");
    SapatoSocial sapato1("CalvinKlein", "formal", "preto", 40, 149.99, Fabrica::getInstance().getFornecedor("CNPJ_F"), "couro");

    Estoque estoque;
    estoque.adicionarProduto(&tenis1);
    estoque.adicionarProduto(&sapato1);

    cout << "Produtos Disponiveis:" << endl;
    estoque.exibirProdutos();

    return 0;
}
