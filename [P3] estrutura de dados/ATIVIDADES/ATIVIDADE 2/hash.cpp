#include <iostream>
#include <vector>
#include <list>

using namespace std;

const int n = 101; // Tamanho da tabela principal

// Fun��o de hash para o primeiro n�vel
int FirstLevelHash(int key) {
    return key % 10;
}

// Fun��o de hash para o segundo n�vel
int SecondLevelHash(int key) {
    return key % (n / 10);
}

class HashTable {
private:
    vector<list<int>> firstLevelTable;
    vector<vector<list<int>>> secondLevelTable;

public:
    HashTable() {
        firstLevelTable.resize(10);
        secondLevelTable.resize(10);
        for (auto& subTable : secondLevelTable) {
            subTable.resize(n / 10);
        }
    }

    // Insere um objeto com uma chave na tabela hash
    void Insert(int key) {
        int firstIndex = FirstLevelHash(key);
        int secondIndex = SecondLevelHash(key);

        secondLevelTable[firstIndex][secondIndex].push_back(key);
    }

    // Procura um objeto na tabela hash
    bool Search(int key) {
        int firstIndex = FirstLevelHash(key);
        int secondIndex = SecondLevelHash(key);

        for (int value : secondLevelTable[firstIndex][secondIndex]) {
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
    cout << "Procurando 10: " << (hashTable.Search(10) ? "Encontrado" : "N�o encontrado") << endl;
    cout << "Procurando 25: " << (hashTable.Search(25) ? "Encontrado" : "N�o encontrado") << endl;
    cout << "Procurando 42: " << (hashTable.Search(42) ? "Encontrado" : "N�o encontrado") << endl;

    return 0;
}

