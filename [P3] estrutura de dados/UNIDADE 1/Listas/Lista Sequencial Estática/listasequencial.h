/* Definir os protótipos das funções, o tipo de dado armazenado na lista, o ponteiro da "lista", o tamanho do vetor usado na lista */

struct  aluno {

    int matricula;
    char nome[30];
    float n1, n2, n3; // dados que guardamos na lista
};
typedef struct lista Lista; // apelido da lista

Lista* cria_lista(); //inicialização

// quando trapablahmos com a lista precisamos destrir ela;
void libera_lista(Lista* li);


// Como descobrir o tamanho da lista
int tamanho_lista(Lista* li);

//Como descobrir se a lista cheia?
int lista_cheia(Lista* li);

//Como descobrir se a lista vazia?
int lista_vazia(Lista* li);

// inserir elemento no fim da lista
int insere_lista_final(Lista* li, struct aluno al);

// inserir elemento no incio da lista
int insere_lista_incio(Lista* li, struct aluno al);

//inserir elemento de forma ordenada
int insere_lista_ordenada(Lista* li, struct aluno al);

// remover elemento no fim da lista
int remove_lista_final(Lista* li);

// remover elemento no incio da lista
int remove_lista_inicio(Lista* li);

// remover elemento da lista
int remove_lista(Lista* li, int mat);

// consulta pela posição
int consulta_lista_pos(Lista* li, int pos, struct aluno *al);

// consulta pela conteudo, nesse exemplo, pela matricula
int consulta_lista_mat(Lista* li, int mat, struct aluno *al);