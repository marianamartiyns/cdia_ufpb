#include <iostream>
#include <vector>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::string;

class cliente{

    string nome, cpf, endereco;

    public:
        // construtor
        cliente(char* n, int c, char* e){
            nome = n;
            cpf = c;
            endereco = e;
        };

        //destrutor
        ~cliente(){}

        // gets
        string get_nome(){
            return nome;
        };

        string get_cpf(){
            return cpf;
        };

        string get_endereco(){
            return endereco;
        };

        // sets

        void set_nome(string novo_nome){
            nome = novo_nome;
        };

        void set_cpf(string novo_cpf){
            cpf = novo_cpf
        };

        void set_endereco(string novo_end){
            endereco = novo_end;
        };

        // visualização dos dados
        void print_info(){
            cout << "Cliente" << endl;
            cout << "Nome: " << nome << endl;
            cout << "CPF: " << cpf << endl;
            cout << "Endereco: " << endereco << endl;
        }
};

class operacao{

    char tipo; //C ou D
    float valor;

    public:
    //construtor
    operacao(char t, float v){
        t = tipo;
        v = valor;
    };

    ~operacao(){};

    //gets
    char get_tipo(){
        return tipo;
    };

    float get_valor(){
        return valor;
    };

    //sets

    void set_tipo(char novo_tipo){
        tipo = novo_tipo;
    };

    void set_valor(float novo_valor){
        valor = novo_valor;
    };

    //mostrar info
    void print_info(){
        cout << "Tipo: " << tipo << endl;
        cout << "Valor: " << valor << endl;
    };
};

class conta{

    int numero;
    cliente *cli;
    float saldo;
    std::vector <operacao> operacoes; // operacoes: É um vetor de objetos da classe operacao, que armazena as operações relacionadas a esta conta.

    public:
        //construtor
        conta(int n, cliente *c, float s){
            numero = n;
            cli = c;
            saldo = s;
        };

        //destrutor
        ~conta(){
            operacoes.clear();
        };

        //gets
        int get_numero(){
            return numero;
        };

        cliente* get_cliente(){
            return cli;
        };

        float get_saldo(){
            return saldo;
        };

        //sets
        void set_numero(int n){
            numero = n;
        };

        void set_cliente(cliente* c){
            cli = c;
        };

        void set_saldo(float s){
            saldo = s;
        };

        /* Este método é usado para adicionar uma operação à conta. 
        Ele recebe um objeto da classe operacao como argumento e o adiciona ao vetor operacoes. 
        Além disso, ele atualiza o saldo da conta com base no tipo de operação ('C' para crédito e 'D' para débito). */

        void add_operacao(operacao o){ // recebe 'o'

            operacoes.push_back(o); //  adiciona o objeto o ao vetor operacoes, O método push_back() é usado para adicionar o objeto o ao final do vetor.

            if (o.get_tipo() == 'C') {
                saldo += o.get_valor();

            } else if (o.get_tipo() == 'D') {
                saldo -= o.get_valor();

            /*
            Esta parte do código verifica o tipo de operação representado pelo objeto o e atualiza o saldo da conta de acordo com o tipo da operação.

            o.get_tipo(): Esta parte chama o método get_tipo() do objeto o para obter o tipo da operação. O método get_tipo() retorna um caractere ('C' para crédito ou 'D' para débito) que representa o tipo da operação.

                Se o tipo da operação for 'C' (crédito), o código adiciona o valor da operação ao saldo da conta com saldo += o.get_valor(). Isso significa que o saldo da conta aumenta quando ocorre uma operação de crédito.

                Se o tipo da operação for 'D' (débito), o código subtrai o valor da operação do saldo da conta com saldo -= o.get_valor(). Isso significa que o saldo da conta diminui quando ocorre uma operação de débito.
            */};
        };

        void print_info() {
            cout << "Numero: " << numero << endl;
            cout << "Cliente: " << cli->get_nome() << endl;
            cout << "Operacoes: " << endl;
            for (int i = 0; i < operacoes.size(); i++) {
                operacoes[i].print_info();
            }
            cout << "Saldo: " << saldo << endl;
        };
};

class banco {

    std::vector<conta> contas; // Um vetor de objetos da classe "conta"

public:

    int codigo;

    // construtor
    banco(int c) { codigo = c; }

    //destrutor que limpa o vetor contas
    ~banco() {
        contas.clear();
    }

    // Método para adicionar uma conta ao vetor de contas.
    void add_conta(conta c) {
        contas.push_back(c); //adiciona no final
    }

    // Método para remover uma conta do vetor com base no número da conta.
    void remove_conta(int n) {
        for (int i = 0; i < contas.size(); i++) {
            if (contas[i].get_numero() == n) {
                contas.erase(contas.begin() + i);
                break;
            }
        }
    }

    //get
    int get_codigo() {
        return codigo;
    }

    // Método para obter um ponteiro para uma conta com base no número da conta.
    conta* get_conta(int n) {
        for (int i = 0; i < contas.size(); i++) {
            if (contas[i].get_numero() == n) {
                return &contas[i];
            }
        }
        return NULL;
    }

    // Método para realizar uma transferência entre duas contas.
    void transfere(conta *c1, conta *c2, float v) {
        operacao o1('D', v); //deposito
        operacao o2('C', v); //saque
        c1->add_operacao(o1);
        c2->add_operacao(o2);
    }

    // Método para imprimir informações sobre o banco e suas contas.
    void print_info() {
        cout << "Banco: " << codigo << endl;
        cout << "Contas: " << endl;
        for (int i = 0; i < contas.size(); i++) {
            contas[i].print_info(); // Chama o método print_info() da classe "conta" para imprimir informações de cada conta.
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






