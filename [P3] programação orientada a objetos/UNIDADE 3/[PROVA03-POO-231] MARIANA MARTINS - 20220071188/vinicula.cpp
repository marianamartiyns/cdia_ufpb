#include <iostream>
#include <vector>
#include <string>
#include <memory>
#include <stdexcept>

using namespace std;

class Uva {

private:
      string nome;
      int safra;
      double preco_por_quilo;

public:

      Uva(string nome, int safra, double preco_por_quilo)
          : nome(nome), safra(safra), preco_por_quilo(preco_por_quilo) {}

      string getNome() const { return nome;}

      int getSafra() const { return safra; }

      double getPrecoPorQuilo() const { return preco_por_quilo; }
};


class Vinho {

protected:
        string nome;
        int safra;
        double volume;
        shared_ptr<Uva> uva;
        static int quantidade;

  public:
      Vinho(string nome, int safra, double volume, shared_ptr<Uva> uva)
          : nome(nome), safra(safra), volume(volume), uva(uva) {}

      // método virtual
      virtual void exibirInfo() {
          cout << "\nNome: " << nome << "\nSafra: " << safra << "\nVolume: " << volume << "\nUva: " << uva->getNome() << endl;
      }

      static int getQuantidade() {
          return quantidade;}

      virtual ~Vinho() {} ; // destrutor
  };



int Vinho::quantidade = 0;


class VinhoTinto : public Vinho {   // classe vinho tinto que herda publicamente de vinho

private:
      float nivel_tanino;
      float quantidade_polifenois;

public:
      VinhoTinto(string nome, int safra, double volume, shared_ptr<Uva> uva, float nivel_tanino, float quantidade_polifenois)
          : Vinho(nome, safra, volume, uva), nivel_tanino(nivel_tanino), quantidade_polifenois(quantidade_polifenois) {}

      // informações específicas do vinho tinto
      void exibirInfo() override { // sobrecarga
          Vinho::exibirInfo();
          cout << "Tanino: " << nivel_tanino << "\nQ. POLIFENÓIS: " << quantidade_polifenois << endl;
      }
      int getSafra() const {
          return safra;
      }
  };

class VinhoBranco : public Vinho { // classe vinho branco que herda publicamente de vinho

 private:
      string subtipo;

  public:
      //construtor
      VinhoBranco(string nome, int safra, double volume, shared_ptr<Uva> uva, string subtipo)
          : Vinho(nome, safra, volume, uva), subtipo(subtipo) {}

      // informações do vinho branco
      void exibirInfo() override {
          Vinho::exibirInfo();
          cout << "SUBTipo: " << subtipo << endl;
      }
      int getSafra() const {
          return safra;
      }

  };

  class Cliente {

  private:
      string nome;
      string sobrenome;
      string email;
      string telefone;

  public:
      Cliente(string nome, string sobrenome, string email, string telefone)
          : nome(nome), sobrenome(sobrenome), email(email), telefone(telefone) {}

    // geterrs
    string getNome() const {return nome;}
    string getSobrenome() const {return sobrenome;}
    string getEmail() const {return email;}
    string getTelefone() const {return telefone;}
  };


class Venda {

private:
    shared_ptr<Cliente> cliente;
    shared_ptr<Vinho> vinho;
    int quantidade;

public:
    Venda(shared_ptr<Cliente> cliente, shared_ptr<Vinho> vinho, int quantidade)
        : cliente(cliente), vinho(vinho), quantidade(quantidade) {}

    double calcularTotal() {
        double preco_unitario = vinho->getQuantidade();
        return preco_unitario * quantidade;
      }
  };


class Vinicola {

private:

  vector<shared_ptr<Uva>> uvas;
  vector<shared_ptr<Vinho>> vinhos;
  vector<shared_ptr<Cliente>> clientes;
  vector<shared_ptr<Venda>> vendas;

public:

    static Vinicola& getInstance() {
        static Vinicola instance;
        return instance;}

    void adicionarUva(shared_ptr<Uva> uva) {
        uvas.push_back(uva);}

    void adicionarVinho(shared_ptr<Vinho> vinho) {
        vinhos.push_back(vinho);}

    void adicionarCliente(shared_ptr<Cliente> cliente) {
          clientes.push_back(cliente);
      }

    void registrarVenda(shared_ptr<Cliente> cliente, shared_ptr<Vinho> vinho, int quantidade) {
        vendas.push_back(make_shared<Venda>(cliente, vinho, quantidade));
      }

    double calcularSomaVendas() {
        double soma = 0.0;
        for (const auto& venda : vendas) {
            soma += venda->calcularTotal();
        }
        return soma;
      }
  };

  template <typename T> // classe vinoteca - template
  class Vinoteca {

 private:
      vector<shared_ptr<T>> vinhos;

  public:
      void adicionarVinho(shared_ptr<T> vinho) {
          vinhos.push_back(vinho);
      }

      void listarVinhos() {
          for (const auto& vinho : vinhos) {
              vinho->exibirInformacoes();
          }
      }

      vector<shared_ptr<T>> encontrarVinhoPorSafra(int safra) {
          vector<shared_ptr<T>> vinhosPorSafra;
          for (const auto& vinho : vinhos) {
              if (vinho->getSafra() == safra) {
                  vinhosPorSafra.push_back(vinho);
              }
          }
          return vinhosPorSafra;
      }

      //soma o valor do estoque
      double calcularValorTotalEstoque() {
        double valorTotal = 0.0;
          for (const auto& vinho : vinhos) {
            valorTotal += vinho->getQuantidade();
            }
            return valorTotal;
            }
  };

  int main() {

    shared_ptr<Uva> uva1 = make_shared<Uva>("Branca", 2020, 5.0);
    shared_ptr<Uva> uva2 = make_shared<Uva>("Branca", 2021, 4.0);
    shared_ptr<Uva> uva3 = make_shared<Uva>("Tinta importada", 2019, 7.0);

    shared_ptr<VinhoTinto> vinhoTinto1 = make_shared<VinhoTinto>("Carreteiro", 2020, 0.75, uva1, 3.5, 100.0);
    shared_ptr<VinhoBranco> vinhoBranco1 = make_shared<VinhoBranco>("Corsel", 2021, 0.75, uva2, "Seco");
    shared_ptr<VinhoTinto> vinhoTinto2 = make_shared<VinhoTinto>("Vinho Alemão", 2019, 0.75, uva3, 4.0, 120.0);


    shared_ptr<Cliente> cliente1 = make_shared<Cliente>("Felipe", "Felly", "felly@academico.ufpb.br", "(81)994223504");
    shared_ptr<Cliente> cliente2 = make_shared<Cliente>("Jeova", "Herminio", "jeova@gmail.com", "(81)933411313");

    Vinicola& vinicola = Vinicola::getInstance();
    vinicola.adicionarUva(uva1);
    vinicola.adicionarUva(uva2);
    vinicola.adicionarUva(uva3);
    vinicola.adicionarVinho(vinhoTinto1);
    vinicola.adicionarVinho(vinhoBranco1);
    vinicola.adicionarVinho(vinhoTinto2);
    vinicola.adicionarCliente(cliente1);
    vinicola.adicionarCliente(cliente2);
    vinicola.registrarVenda(cliente1, vinhoTinto1, 2);
    vinicola.registrarVenda(cliente2, vinhoBranco1, 3);

    Vinoteca<VinhoTinto> vinotecaTintos;
    vinotecaTintos.adicionarVinho(vinhoTinto1);
    vinotecaTintos.adicionarVinho(vinhoTinto2);

    Vinoteca<VinhoBranco> vinotecaBrancos;
    vinotecaBrancos.adicionarVinho(vinhoBranco1);

    // buscas e cálculos
    int safraBuscada = 2020;
    vector<shared_ptr<VinhoTinto>> vinhosEncontrados = vinotecaTintos.encontrarVinhoPorSafra(safraBuscada);
    cout << "\nVinhos tintos da safra " << safraBuscada << " Registrados:" << endl;
    for (const auto& vinho : vinhosEncontrados) {
        vinho->exibirInformacoes();
    }

    safraBuscada = 2021;
    vector<shared_ptr<VinhoBranco>> vinhosBrancosEncontrados = vinotecaBrancos.encontrarVinhoPorSafra(safraBuscada);
    cout << "\nVinhos da Safra " << safraBuscada << " Registrados:" << endl;
    for (const auto& vinho : vinhosBrancosEncontrados) {
        vinho->exibirInformacoes();
    }

double valorTotalTintos = vinotecaTintos.calcularValorTotalEstoque();
    double valorTotalBrancos = vinotecaBrancos.calcularValorTotalEstoque();

    cout << "\nValor Total de Vinhos Tintos R$" << valorTotalTintos << endl;
    cout << "Valor Total de Vinhos Brancos: R$" << valorTotalBrancos << endl;

    return 0;
}
