// Grafo Simples (Sem arestas multiplas e Sem laços) Não-Direcionado ponderado

#include <iostream>
using namespace std;
typedef string TipoItem;

class Grafo{

    private:

    int arestanula;
    int maxvertices;
    int numvertices;
    TipoItem* vertices; //vetor dinamico
    int** matriz; // ** = vetor de vetores = matriz

    public:

    Grafo(int max, int valorarestanula); //construtor
    ~Grafo(); //destrutor

    int obterindice(TipoItem item);
    bool estacheio();
    void inserevertices(TipoItem item);
    void inserearesta(TipoItem Nosaida, TipoItem Noentrada, int peso);
    int obterpeso(TipoItem Nosaida, TipoItem Noentrada);
    int obtergrau(TipoItem item);
    void imprimirmatriz();
    void imprimirvertices();
};