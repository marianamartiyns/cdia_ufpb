#include <iostream>
#include "exemplo-matriz.h"

using namespace std;

    Grafo::Grafo(int max, int valorarestanula){ //construtor

        arestanula = valorarestanula;
        maxvertices = max;
        numvertices = 0;

        vertices = new TipoItem[maxvertices];

        // declarando a matriz para ver um vetor de vetores
        matriz = new int*[maxvertices];
        for(int i=0; i<maxvertices; i++){
            matriz[i] = new int[maxvertices];
        }

        // colocando aresta nula na matriz toda
        for(int i=0; i<maxvertices; i++ ){
            for(int j=0; j<maxvertices; j++){
                matriz[i][j] = arestanula;
            }
        }
    }

    Grafo::~Grafo(){ //destrutor
        delete [] vertices;
        for (int i =0; i<maxvertices; i++){
            delete [] matriz[i];
        }
        delete [] matriz;
    }

    int Grafo::obterindice(TipoItem item){
        int indice = 0;
        while (item != vertices[indice]){
            indice++;
        }
        return indice;
    }

    bool Grafo::estacheio(){
        return(numvertices == maxvertices);
    }

    void Grafo::inserevertices(TipoItem item){
        if( estacheio()){
            cout << "O numero maximo de vertices foi alcancado!" << endl;
        } else{
            vertices[numvertices] = item;
            numvertices++;
        }
    }

    void Grafo::inserearesta(TipoItem Nosaida, TipoItem Noentrada, int peso){
        int linha = obterindice(Nosaida);
        int coluna = obterindice(Noentrada);

        matriz[linha][coluna] = peso;

        matriz[coluna][linha] = peso; // remover se for direcionado
    }

    int Grafo::obterpeso(TipoItem Nosaida, TipoItem Noentrada){
        int linha = obterindice(Nosaida);
        int coluna = obterindice(Noentrada);

        return (matriz[linha][coluna]);
    }

    int Grafo::obtergrau(TipoItem item){

        int linha = obterindice(item);
        int grau = 0;
        for (int i =0; i <maxvertices; i++){
            if (matriz[linha][i] != arestanula){
                grau++;
            }
        }
        return grau;
    }

    void Grafo::imprimirmatriz(){
        cout << "Matriz de Adjacencias:\n";
        for (int i= 0; i <maxvertices; i++){
            for(int j=0; j<maxvertices; j++){
                cout << matriz[i][j] << " ";
            }
            cout << endl;
        }
    }

    void Grafo::imprimirvertices(){
        cout << "Lista de Vertices: \n";

        for(int i=0; i<numvertices; i++){
            cout << i << ": " << vertices[i] << endl;
        }
    }
