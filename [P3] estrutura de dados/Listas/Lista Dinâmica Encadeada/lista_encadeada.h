
struct aluno{
    int matricula;
    char nome[30];
    float n1, n2, n3;
};

Lista* cria_lista();

void libera_lista(Lista* li);

//tamanho da lista
int tamanho_lista(Lista* li);

//Lista cheia
int lista_cheia(Lista* li);

//Lsta vazia
int lista_vazia(Lista* li);

// insere no inicio da lista
int insere_lista_inicio(Lista* li, dados_alunos);

// insere no fim da lista
int insere_lista_final(Lista* li, struct aluno al);

//insere um elemento de forma ordenada
int insere_lista_ordenada(Lista* li, struct aluno al);

//remove no inicio da lista
int remove_lista_inicio(Lista* li);

//remove no final da lista
int remove_lista_final(Lista* li);

//
int remove_lista(Lista* li, int mat);

// consulta por posição
int consulta_lista_pos(Lista* li, int pos, struct aluno *al);

// consulta por conteudo
int consulta_lista_mat(Lista* li, int mat, struct aluno *al);