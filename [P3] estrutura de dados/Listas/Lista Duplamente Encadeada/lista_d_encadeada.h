struct aluno{
    int matricula;
    char nome[30];
    float n1, n2, n3;
};

typedef struct elemento* Lista;

Lista* cria_lista();

void libera_lista(Lista* li);

//tamanho da lista
int tamanho_lista(Lista* li);

// lista esta cheia?
int lista_cheia(Lista* li);

// lista esta vazia?
int lista_vazia(Lista* li);