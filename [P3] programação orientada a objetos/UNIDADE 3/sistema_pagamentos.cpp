/* Sistema de pagamentos

Crie uma classe pagamento que represente um pagamento genérico.
- campos: valor, data, numero_cartao
Crie uma classe pagamento_online que herde da classe pagamento.
- campos: nome_site, codigo_seguranca
Crie uma classe pagamento_presencial que herde da classe pagamento.
- campos: nome_loja
Crie uma classe template fatura que represente uma fatura com multiplos
pagamentos (online ou presencial).
- A classe deve ter um campo double limite_credito que representa o limite
- A classe deve ter um campo vector de pagamentos.
- A classe deve ter um método adicionar_pagamento() que recebe como parâmetro
um pagamento e o adiciona ao vector de pagamentos.
- A classe deve ter um método calcular_valor_total() que calcula o valor total
da fatura com base nos pagamentos adicionados.

Sobrecarregue o operador << para imprimir as informações de um objeto da classe fatura.
Sobrecarregue o operador + para adicionar um pagamento a uma fatura.
Sobrecarregue o operador - para remover um pagamento de uma fatura.

Crie uma função friend template chamada transferir_pagamentos() que receba como parâmetros
dois objetos da classe fatura (com o mesmo tipo template) e transfira todos os pagamentos
da primeira fatura para a segunda fatura.

Adicione tratamento de exceções ao código para lidar com situações em que o usuário tente
adicionar pagamentos acima do limite (campo limite_credito).

Crie uma funcao main que crie três objetos da classe fatura, com pelo menos três pagamentos
cada. Imprima as informações de cada fatura e transfira os pagamentos da primeira fatura
para a segunda fatura. Imprima novamente as informações de cada fatura.
*/

#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>

using namespace std;

class Pagamento {
public:
    double valor;
    string data;
    string numero_cartao;

    Pagamento(double _valor, const string& _data, const string& _numero_cartao)
        : valor(_valor), data(_data), numero_cartao(_numero_cartao) {}
};

class PagamentoOnline : public Pagamento {
public:
    string nome_site;
    string codigo_seguranca;

    PagamentoOnline(double _valor, const string& _data, const string& _numero_cartao, const string& _nome_site, const string& _codigo_seguranca)
        : Pagamento(_valor, _data, _numero_cartao), nome_site(_nome_site), codigo_seguranca(_codigo_seguranca) {}
};

class PagamentoPresencial : public Pagamento {
public:
    string nome_loja;

    PagamentoPresencial(double _valor, const string& _data, const string& _numero_cartao, const string& _nome_loja)
        : Pagamento(_valor, _data, _numero_cartao), nome_loja(_nome_loja) {}
};

template <class T>
class Fatura {
public:
    double limite_credito;
    vector<T> pagamentos;

    Fatura(double _limite_credito) : limite_credito(_limite_credito) {}

    void adicionar_pagamento(const T& pagamento) {
        if (calcular_valor_total() + pagamento.valor > limite_credito) {
            throw overflow_error("Limite de crédito excedido.");
        }
        pagamentos.push_back(pagamento);
    }

    double calcular_valor_total() const {
        double total = 0;
        for (const T& pagamento : pagamentos) {
            total += pagamento.valor;
        }
        return total;
    }

    friend ostream& operator<<(ostream& os, const Fatura<T>& fatura) {
        os << "Limite de Crédito: " << fatura.limite_credito << endl;
        os << "Pagamentos na Fatura:" << endl;
        for (const T& pagamento : fatura.pagamentos) {
            os << "Valor: " << pagamento.valor << ", Data: " << pagamento.data << ", Número do Cartão: " << pagamento.numero_cartao << endl;
        }
        os << "Valor Total: " << fatura.calcular_valor_total() << endl;
        return os;
    }

    Fatura<T>& operator+(const T& pagamento) {
        adicionar_pagamento(pagamento);
        return *this;
    }

    Fatura<T>& operator-(const T& pagamento) {
        for (auto it = pagamentos.begin(); it != pagamentos.end(); ++it) {
            if (it->numero_cartao == pagamento.numero_cartao) {
                pagamentos.erase(it);
                break;
            }
        }
        return *this;
    }

};

template <class T>
void transferir_pagamentos(Fatura<T>& fatura_origem, Fatura<T>& fatura_destino) {
    for (const T& pagamento : fatura_origem.pagamentos) {
        fatura_destino.adicionar_pagamento(pagamento);
    }
    fatura_origem.pagamentos.clear();
}

int main() {
    Fatura<PagamentoOnline> fatura_online(1000.0);
    Fatura<PagamentoPresencial> fatura_presencial(1500.0);
    Fatura<PagamentoOnline> fatura_destino(2000.0);

    PagamentoOnline pagamento1(100.0, "2023-11-05", "1234-5678", "Online Shop", "123");
    PagamentoOnline pagamento2(50.0, "2023-11-05", "5678-1234", "Web Store", "456");
    PagamentoPresencial pagamento3(200.0, "2023-11-05", "8765-4321", "Local Store");
    PagamentoPresencial pagamento4(300.0, "2023-11-05", "4321-8765", "Local Mall");

    fatura_online + pagamento1 + pagamento2;
    fatura_presencial + pagamento3 + pagamento4;

    cout << "Fatura Online:" << endl << fatura_online << endl;
    cout << "Fatura Presencial:" << endl << fatura_presencial << endl;

    transferir_pagamentos(fatura_online, fatura_destino);
    cout << "Transferência de pagamentos realizada." << endl;

    cout << "Fatura Online após a transferência:" << endl << fatura_online << endl;
    cout << "Fatura de Destino após a transferência:" << endl << fatura_destino << endl;

    return 0;
}

