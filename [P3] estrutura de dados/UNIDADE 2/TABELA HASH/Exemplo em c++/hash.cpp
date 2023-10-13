#include "tudao.h"
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

int main(){

    Hash alunoHash(10);

    int ras[7] = {63814, 54936, 13285, 14283, 10723, 15892, 71659};
    string nomes[7] = {"Rafaela", "Mariana", "Jeova", "Bruno", "Felly", "cLAY", "Carla"};

for (int i = 0; i< 7; i++){
    Aluno aluno = Aluno(ras[i], nomes[i]);
    alunoHash.insert_item(aluno);
    }
alunoHash.print();

}
