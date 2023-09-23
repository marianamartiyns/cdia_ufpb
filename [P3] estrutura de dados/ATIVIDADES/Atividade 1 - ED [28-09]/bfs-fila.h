#ifndef FILADINAMICA_H 
#define FILADINAMICA_H 

#include "No.h"

class filadinamica{ 

    private:
    No* primeiro; //front
    No* ultimo; //rear

    public:
    filadinamica(); // Constructor
    ~filadinamica(); // Destrutor  
    bool estavazio(); //isEmpty
    bool estacheio(); //isFull
    void inserir(TipoItem item); //enqueue //push
    TipoItem remover(); //dequeue //pop
    void imprimir(); //print
  
};

#endif