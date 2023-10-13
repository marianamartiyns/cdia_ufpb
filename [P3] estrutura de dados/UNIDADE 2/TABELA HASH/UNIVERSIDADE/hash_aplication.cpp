#include <iostream>
#include "hash.h"

using namespace std;

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
