#include "hash.h"
//#include "aluno.h"
#include <iostream>

using namespace std;

Hash:: Hash(int max){

    length = 0;
    max_items = max;
    structure = new Aluno[max_items];
}

Hash:: ~Hash(){
    delete [] structure;
}

bool Hash:: is_full() const {
    return (length == max_items);
}

void Hash:: retrieve_item(Aluno& aluno, bool& found){
    int location = get_hash(aluno);
    Aluno aux = structure[location];
    if (aluno.get_ra() != aux.get_ra()){
            found = false;
    } else{
        found = true;
        aluno = aux;
    }
}

void Hash::insert_item(Aluno aluno) {

    int location = get_hash(aluno);
    structure[location] = aluno;
    length++;
}

void Hash::delete_item(Aluno aluno) {

    int location = get_hash(aluno);
    structure[location] = Aluno();
    length--;
}

void Hash::print(){
    for (int i = 0; i < max_items; i++){
            cout << i << ":" <<
                structure[i].get_ra()<< ", " <<
                structure[i].get_nome() << endl;
    }
}

int Hash::get_hash(Aluno aluno){
    return aluno.get_ra() % max_items;
}

