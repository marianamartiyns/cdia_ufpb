/*Exercício 3: Sistema de Reservas de Voo

Crie uma classe `Voo` que armazena informações sobre voos, como número do voo, origem, destino e data de partida. Implemente um sistema de reservas de voos que permita adicionar voos, listar voos disponíveis e reservar lugares em um voo.
Utilize um `std::vector` para armazenar objetos `Voo`. */

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Voo {

public:
    Voo(int numero, const string& origem, const string& destino, const string& data)
        : numeroVoo(numero), origem(origem), destino(destino), dataPartida(data) {}

    int getNumeroVoo() const { return numeroVoo; }
    const string& getOrigem() const { return origem; }
    const string& getDestino() const { return destino; }
    const string& getDataPartida() const { return dataPartida; }

private:
    int numeroVoo;
    string origem;
    string destino;
    string dataPartida;
};

class SistemaReservas {

    vector<Voo> voos;

public:
    void adicionarVoo(const Voo& voo) {
        voos.push_back(voo);
    }

    void listarVoosDisponiveis() {
        for (const Voo& voo : voos) {
            cout << "Número do Voo: " << voo.getNumeroVoo() << endl;
            cout << "Origem: " << voo.getOrigem() << endl;
            cout << "Destino: " << voo.getDestino() << endl;
            cout << "Data de Partida: " << voo.getDataPartida() << endl;
            cout << endl;
        }
    }

};

int main() {

    SistemaReservas sistema;

    sistema.adicionarVoo(Voo(1, "New York", "Los Angeles", "2023-11-10"));
    sistema.adicionarVoo(Voo(2, "Chicago", "Miami", "2023-11-12"));
    sistema.adicionarVoo(Voo(3, "San Francisco", "Las Vegas", "2023-11-15"));

    cout << "Voos Disponíveis:" << endl;
    sistema.listarVoosDisponiveis();

    return 0;
}
