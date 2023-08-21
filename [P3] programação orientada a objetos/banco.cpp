/*
Sistema de Controle Bancário com Operações
 
Descrição:
Você foi contratado para desenvolver um sistema de controle bancário para uma instituição financeira.
O sistema deve permitir a gestão de contas bancárias, saques, depósitos, operações e relatórios.
Crie classes que representem cada uma dessas entidades e explore os conceitos de programação
orientada a objetos como:
    - declaração de classes, instanciação de objetos
    - métodos de acesso e modificação (gets e sets)    
    - arrays de objetos
    - métodos construtores e destrutores
    - uso de atributos alocados dinamicamente
    - diferentes tipos de composição    
 
Requisitos:
 
Crie uma classe Cliente que contenha informações sobre os clientes do banco, como nome, CPF e endereço.
Crie uma classe Operacao que represente as operações realizadas nas contas. Cada operação deve ter um tipo (saque ou depósito) e um valor associado.
Crie uma classe Conta que represente as contas bancárias. Cada conta deve ter um número de conta, um cliente associado, um saldo e uma lista das operações realizadas.
Crie uma classe Banco que gerencie as contas bancárias. A classe deve conter um array dinâmico de contas, permitindo que contas sejam adicionadas e removidas dinamicamente.
 
Defina as relações entre as classes utilizando os diferentes tipos de composição.
 
Implemente métodos para criar contas, realizar depósitos, saques, exibir extratos e relatórios de contas no sistema.
 
Utilize métodos construtores para inicializar os objetos e métodos destrutores para liberar memória alocada dinamicamente.
 
Crie uma função de teste que demonstre a criação e uso das classes, incluindo a criação de clientes, contas bancárias, transações bancárias e ações de gerenciamento do banco.
*/

#include <iostream>
#include <vector>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::string;

class cliente {
    string nome;
    string cpf;
    string endereco;
public:
    cliente(string n, string c, string e) {
        nome = n;
        cpf = c;
        endereco = e;
    }
    ~cliente() {}
    string get_nome() {
        return nome;
    }
    string get_cpf() {
        return cpf;
    }
    string get_endereco() {
        return endereco;
    }

    void set_nome(string n) {
        nome = n;
    }
    void set_cpf(string c) {
        cpf = c;
    }
    void set_endereco(string e) {
        endereco = e;
    }
    void print_info() {
        cout << "Nome: " << nome << endl;
        cout << "CPF: " << cpf << endl;
        cout << "Endereco: " << endereco << endl;
    }
};

class operacao {
    char tipo; //C ou D
    float valor;
public:
    operacao(char t, float v) {
        tipo = t;
        valor = v;
    }
    ~operacao() {}
    char get_tipo() {
        return tipo;
    }
    float get_valor() {
        return valor;
    }
    void set_tipo(char t) {
        tipo = t;
    }
    void set_valor(float v) {
        valor = v;
    }
    void print_info() {
        cout << "Tipo: " << tipo << endl;
        cout << "Valor: " << valor << endl;
    }
};    

class conta {
    int numero;
    cliente *cli;
    float saldo;
    std::vector<operacao> operacoes;
public:
    conta(int n, cliente *c, float s) {
        numero = n;
        cli = c;
        saldo = s;
    }
    ~conta() {
        operacoes.clear();
    }
    int get_numero() {
        return numero;
    }
    cliente* get_cliente() {
        return cli;
    }
    float get_saldo() {
        return saldo;
    }
    void set_numero(int n) {
        numero = n;
    }
    void set_cliente(cliente *c) {
        cli = c;
    }
    void set_saldo(float s) {     
        saldo = s;
    }
    void add_operacao(operacao o) {
        operacoes.push_back(o);
        if (o.get_tipo() == 'C') {
            saldo += o.get_valor();
        } else if (o.get_tipo() == 'D') {
            saldo -= o.get_valor();
        }
    }
    void print_info() {
        cout << "Numero: " << numero << endl;
        cout << "Cliente: " << cli->get_nome() << endl;
        cout << "Operacoes: " << endl;
        for (int i = 0; i < operacoes.size(); i++) {
            operacoes[i].print_info();
        }
        cout << "Saldo: " << saldo << endl;
    }
};

class banco {
    std::vector<conta> contas;
public:
    int codigo;
    banco(int c) { codigo = c; }
    ~banco() {
        contas.clear();
    }
    void add_conta(conta c) {
        contas.push_back(c);
    }
    void remove_conta(int n) {
        for (int i = 0; i < contas.size(); i++) {
            if (contas[i].get_numero() == n) {
                contas.erase(contas.begin() + i);
                break;
            }
        }
    }

    int get_codigo() {
        return codigo;
    }

    conta* get_conta(int n) {
        for (int i = 0; i < contas.size(); i++) {
            if (contas[i].get_numero() == n) {
                return &contas[i];
            }
        }
        return NULL;
    }

    void transfere(conta *c1, conta *c2, float v) {
        operacao o1('D', v);
        operacao o2('C', v);
        c1->add_operacao(o1);
        c2->add_operacao(o2);
    }

    void print_info() {
        cout << "Banco: " << codigo << endl;
        cout << "Contas: " << endl;
        for (int i = 0; i < contas.size(); i++) {
            contas[i].print_info();
        }
    }
};

int main(void) {
    cliente *c1 = new cliente("Joao", "123456789-00", "Rua 1");
    cliente *c2 = new cliente("Maria", "987654321-00", "Rua 2");

    conta *conta1 = new conta(1, c1, 1000.0);
    conta *conta2 = new conta(2, c2, 2000.0);

    banco *b = new banco(1);

    b->add_conta(*conta1);
    b->add_conta(*conta2);

    b->print_info();

    char ch;
    
    cout << "Digite uma tecla para continuar" << endl;

    cin >> ch;

    b->transfere(b->get_conta(1), b->get_conta(2), 100);

    b->print_info();

    return 0;
}