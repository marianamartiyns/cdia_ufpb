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






