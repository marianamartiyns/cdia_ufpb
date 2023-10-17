#include <iostream>
#include <vector>
#include <list>

using namespace std;

const int n = 101; // Tamanho da tabela principal

// Função de hash para o primeiro nível
int FirstLevelHash(int key) {
    return key % 10;
}

// Função de hash para o segundo nível
int SecondLevelHash(int key) {
    return key % (n / 10);
}

class HashTable {
private:
    vector<list<int>> firstLevelTable[10];
    vector<list<int>> secondLevelTable[n / 10];

public:
    // Insere um objeto com uma chave na tabela hash
    void Insert(int key) {
        int firstIndex = FirstLevelHash(key);
        int secondIndex = SecondLevelHash(key);

        firstLevelTable[firstIndex][secondIndex].push_back(key);
    }

    // Procura um objeto na tabela hash
    bool Search(int key) {
        int firstIndex = FirstLevelHash(key);
        int secondIndex = SecondLevelHash(key);

        for (int value : firstLevelTable[firstIndex][secondIndex]) {
            if (value == key) {
                return true;
            }
        }
        return false;
    }
};

int main() {
    HashTable hashTable;

    // Inserindo valores de exemplo
    hashTable.Insert(10);
    hashTable.Insert(25);
    hashTable.Insert(35);

    // Procurando valores de exemplo
    cout << "Procurando 10: " << (hashTable.Search(10) ? "Encontrado" : "Não encontrado") << endl;
    cout << "Procurando 25: " << (hashTable.Search(25) ? "Encontrado" : "Não encontrado") << endl;
    cout << "Procurando 42: " << (hashTable.Search(42) ? "Encontrado" : "Não encontrado") << endl;

    return 0;
}

