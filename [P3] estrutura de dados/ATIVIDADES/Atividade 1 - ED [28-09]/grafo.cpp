#include <iostream>
#include "grafo.h"
#include "dfs-pilha.h"
#include "bfs-fila.h"

using namespace std;

Grafo::Grafo(int max, int valorarestanula){ //construtor

    arestanula = valorarestanula;
    maxvertices = max;
    numvertices = 0;

    marcador = new bool[maxvertices];

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
    // matriz[coluna][linha] = peso; // remover se for direcionado
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

void Grafo::limpamarcador(){
    for(int i = 0; i < maxvertices; i++){
        marcador[i] = false;
    }
}

void Grafo::buscaemlargura(TipoItem origem, TipoItem destino) {

    filadinamica filavertices;
    bool encontrado = false;
    limpamarcador();
    filavertices.inserir(origem);

    do{
        TipoItem verticeatual = filavertices.remover();
        if (verticeatual == destino){
            cout << "Visitando: " << verticeatual << endl;
            cout << "Caminho encontrado!\n";
            encontrado = true;
        } else{
            int indice = obterindice(verticeatual);
            cout << "Visitando: " << verticeatual << endl;
            for (int i=0 ; i<maxvertices ; i++){
                if (matriz[indice][i] != arestanula){
                    if (!marcador[i]){
                        cout << "Enfileirando: " << vertices[i] << endl;
                        filavertices.inserir(vertices[i]);
                        marcador[i] = true;
                    }
                }  
            }
        }
    } while (!filavertices.estavazio() && !encontrado);
    if (!encontrado){
        cout << "Caminho nao encontrado!\n";
    }
}

void Grafo::buscaemprofundidade(TipoItem origem, TipoItem destino) {

    pilhadinamica pilhavertices;
    bool encontrado = false;
    limpamarcador();
    pilhavertices.inserir(origem);

    do{
        TipoItem verticeatual = pilhavertices.remover();
        if (verticeatual == destino){
            cout << "Visitando: " << verticeatual << endl;
            cout << "Caminho encontrado!\n";
            encontrado = true;
        } else{
            int indice = obterindice(verticeatual);
            cout << "Visitando: " << verticeatual << endl;
            for (int i=0 ; i<maxvertices ; i++){
                if (matriz[indice][i] != arestanula){
                    if (!marcador[i]){
                        cout << "Empilhando: " << vertices[i] << endl;
                        pilhavertices.inserir(vertices[i]);
                        marcador[i] = true;
                    }
                }  
            }
        }
    } while (!pilhavertices.estavazio() && !encontrado);
    if (!encontrado){
        cout << "Caminho nao encontrado!\n";
    }
}

int main(){
    
    int max, valorarestanula;
    cout << "Digite a quantidade maxima de vertices: ";
    cin >> max;

    cout << "Digite o valor para represnetar a ausencia de aresta: ";
    cin >> valorarestanula;

    Grafo grafo1(max, valorarestanula);
    TipoItem item1, item2;
    int opcao, valor, peso;

    do{
        cout << "Digite 0 para parar o algoritmo!\n";
        cout << "Digite 1 para inserir um vertice!\n";
        cout << "Digite 2 para inserir uma aresta!\n";
        cout << "Digite 3 para imprimir o grau de um vertice!\n";
        cout << "Digite 4 para imprimir o peso de uma aresta!\n";
        cout << "Digite 5 para imprimir a matriz de adjacencias!\n";
        cout << "Digite 6 para imrpimir a lista de vertices!\n";
        cin >> opcao;

        if(opcao == 1){

            cout << "Digite o elemento do vertice que sera inserido: ";
            cin >> item1;
            grafo1.inserevertices(item1);

        } else if(opcao == 2){
            cout << "Digite o vertice de saida: " << endl;
            cin >> item1;

            cout << "Digite o vertice de entrada: \n";
            cin >> item2;

            cout << "Digite o peso desta aresta: \n";
            cin >> peso;

            grafo1.inserearesta(item1, item2, peso);

        } else if (opcao == 3){
            cout << "Digite o vertice que sera calculado o grau: \n";
            cin >> item1;

            valor = grafo1.obtergrau(item1);
            cout << "O grau desse vertice eh: " << valor << endl;

        } else if(opcao == 4){

            cout << "Digite o vertice de saida: " << endl;
            cin >> item1;

            cout << "Digite o vertice de entrada: \n";
            cin >> item2;

            valor = grafo1.obterpeso(item1, item2);
            cout << "O peso dessa aresta eh: " << valor << endl;
        } else if (opcao == 5){
            grafo1.imprimirmatriz();
        } else if(opcao == 6){
            grafo1.imprimirvertices();
        }

    } while (opcao != 0);
}

