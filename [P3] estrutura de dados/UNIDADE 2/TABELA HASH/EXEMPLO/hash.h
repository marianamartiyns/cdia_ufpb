#include "aluno.h"

class Hash{

private:
    int get_hash(Aluno aluno);
    int max_items;
    int length;
    Aluno* structure; // um vetor de objetos aluno

public:
    Hash(int max_items = 100);
    ~Hash();
    bool is_full() const;
    int get_length() const;

    void retrieve_item(Aluno& aluno, bool& found);
    void insert_item(Aluno aluno);
    void delete_item(Aluno aluno);
    void print();
};
