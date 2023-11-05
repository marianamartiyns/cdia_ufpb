/*Sistema de Gerenciamento de Funcionários em C++

Desenvolva um programa em C++ que simule um sistema de gerenciamento de funcionários em uma empresa. O programa deve ser orientado a objetos e suportar diferentes tipos de funcionários, como empregados regulares, gerentes e estagiários. Além disso, o programa deve incorporar os seguintes recursos:

2. **Métodos e Atributos de Classe**:
   - Crie métodos de classe para realizar operações comuns em funcionários, como aumentar o salário de todos os funcionários em uma porcentagem.
   - Implemente atributos de classe, como um contador para manter o número total de funcionários na empresa.

3. **Padrão de Projeto Singleton**:
   - Utilize o padrão de projeto Singleton para criar uma classe `Empresa` que represente a empresa como uma única instância em todo o programa. Isso garantirá que apenas uma empresa exista.

4. **Templates**:
   - Use templates para criar uma estrutura de dados flexível que possa conter funcionários de diferentes tipos.

5. **Estruturas de Dados STL**:
   - Utilize as estruturas de dados da STL (Standard Template Library) para armazenar os funcionários da empresa, como um `vector` ou `map`.

Requisitos:

*/

#include <iostream>
#include <string>
#include <vector>
#include <map>

// 1. Crie uma classe base chamada `funcionario` que contenha informações comuns a todos os funcionários, como nome, ID e salário. Use templates para permitir diferentes tipos numéricos para o salário (por exemplo, `double` ou `int`).


template <typename T>
class Funcionario {
public:
    Funcionario(const std::string& nome, int id, T salario) : nome(nome), id(id), salario(salario) {}
    virtual ~Funcionario() {}

    virtual void imprimir() const = 0;
    virtual T calcularSalario() const = 0;
    int getId() const { return id; }

protected:
    std::string nome;
    int id;
    T salario;
};

// 2. Derive classes para representar diferentes tipos de funcionários:

// `empregado_regular`: Funcionário regular com salário fixo.
template <typename T>
class EmpregadoRegular : public Funcionario<T> {

public:
    EmpregadoRegular(const std::string& nome, int id, T salario) : Funcionario<T>(nome, id, salario) {}

    void imprimir() const override {
        std::cout << "Empregado Regular - ID: " << this->id << ", Nome: " << this->nome << ", Salario: " << this->salario << std::endl;
    }

    T calcularSalario() const override {
        return this->salario;
    }
};

// `gerente`: Funcionário com um salário fixo e bônus adicional.
template <typename T>
class Gerente : public Funcionario<T> {
public:
    Gerente(const std::string& nome, int id, T salario, T bonus) : Funcionario<T>(nome, id, salario), bonus(bonus) {}

    void imprimir() const override {
        std::cout << "Gerente - ID: " << this->id << ", Nome: " << this->nome << ", Salario: " << this->salario << ", Bonus: " << bonus << std::endl;
    }

    T calcularSalario() const override {
        return this->salario + bonus;
    }

private:
    T bonus;
};

// `estagiario`: Funcionário em treinamento com um salário menor.
template <typename T>
class Estagiario : public Funcionario<T> {
public:
    Estagiario(const std::string& nome, int id, T salario) : Funcionario<T>(nome, id, salario) {}

    void imprimir() const override {
        std::cout << "Estagiario - ID: " << this->id << ", Nome: " << this->nome << ", Salario: " << this->salario << std::endl;
    }

    T calcularSalario() const override {
        return this->salario;
    }
};

// 3. Use herança múltipla para criar uma classe `empregado_gerente` que herda de ambas as classes `empregado_regular` e `gerente`. Este funcionário é um empregado regular com responsabilidades de gerenciamento e recebe tanto um salário fixo quanto um bônus.
template <typename T>
class EmpregadoGerente : public EmpregadoRegular<T>, public Gerente<T> {
public:
    EmpregadoGerente(const std::string& nome, int id, T salario, T bonus) : EmpregadoRegular<T>(nome, id, salario), Gerente<T>(nome, id, salario, bonus) {}

    void imprimir() const override {
        EmpregadoRegular<T>::imprimir();
        Gerente<T>::imprimir();
    }

    T calcularSalario() const override {
        return EmpregadoRegular<T>::calcularSalario() + Gerente<T>::calcularSalario();
    }
};

//5. Crie uma classe `empresa` que segue o padrão Singleton e mantém um registro de todos os funcionários da empresa. Implemente métodos para adicionar funcionários, calcular salários, listar funcionários e aumentar o salário de todos os funcionários.
template <typename T>
class Empresa {
public:
    static Empresa& getInstance() {
        static Empresa instance;
        return instance;
    }

    void adicionarFuncionario(Funcionario<T>* funcionario) {
        funcionarios[funcionario->getId()] = funcionario;
    }

    void listarFuncionarios() const {
        for (const auto& pair : funcionarios) {
            pair.second->imprimir();
        }
    }

    void aumentarSalario(double aumentoPercentual) {
        for (auto& pair : funcionarios) {
            T novoSalario = pair.second->calcularSalario() * (1 + aumentoPercentual / 100);
            pair.second->setSalario(novoSalario);
        }
    }

private:
    Empresa() {}
    ~Empresa() {
        for (auto& pair : funcionarios) {
            delete pair.second;
        }
    }

    std::map<int, Funcionario<T>*> funcionarios;
};

int main() {

    Empresa<double>& empresa = Empresa<double>::getInstance();

    Funcionario<double>* empregado1 = new EmpregadoRegular<double>("Empregado1", 1, 3000);
    Funcionario<double>* gerente1 = new Gerente<double>("Gerente1", 2, 5000, 1000);
    Funcionario<double>* estagiario1 = new Estagiario<double>("Estagiario1", 3, 1000);
    Funcionario<double>* empregadoGerente1 = new EmpregadoGerente<double>("EmpregadoGerente1", 4, 4000, 800);

    empresa.adicionarFuncionario(empregado1);
    empresa.adicionarFuncionario(gerente1);
    empresa.adicionarFuncionario(estagiario1);
    empresa.adicionarFuncionario(empregadoGerente1);

    empresa.listarFuncionarios();
    empresa.aumentarSalario(10);
    empresa.listarFuncionarios();

    return 0;
}

