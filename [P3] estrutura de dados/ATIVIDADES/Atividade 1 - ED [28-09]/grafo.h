// Grafo Simples (Sem arestas multiplas e Sem laços) Direcionado ponderado

#include <iostream>
#include "dfs-pilha.h"
#include "bfs-fila.h"

using namespace std;
// typedef string TipoItem;

class Grafo{

    private:

    int arestanula;
    int maxvertices;
    int numvertices;
    TipoItem* vertices; //vetor dinamico
    int** matriz; // ** = vetor de vetores = matriz
    bool* marcador;

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

    void limpamarcador();
    void buscaemlargura(TipoItem origem, TipoItem destino);
    void buscaemprofundidade(TipoItem origem, TipoItem destino);
};