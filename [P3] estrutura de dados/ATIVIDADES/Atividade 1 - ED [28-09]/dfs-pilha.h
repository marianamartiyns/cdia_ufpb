// Pilha Dinâmica = Dynamic Stack

#ifndef PILHADINAMICA_H 
#define PILHADINAMICA_H 

#include "No.h"

class pilhadinamica{
    private:
    No* NoTopo;

    public:
    pilhadinamica(); //construtor //dynamic stack
    ~pilhadinamica(); //destrutor
    bool estavazio(); //isempty
    bool estacheio(); //tem memória //isfull
    void inserir(TipoItem item); //push
    TipoItem remover(); //pop
    void imprimir(); //print

    
};

#endif