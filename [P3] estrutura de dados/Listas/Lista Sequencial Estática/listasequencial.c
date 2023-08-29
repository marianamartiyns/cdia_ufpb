/* definir o tipo de dados "lista" e implementar as suas funções*/

#include <listasequencial.h>;
#include <stdio.h>

#define MAX 100

struct lista{
    int qtd; // quantas posições eu ja ocupei da minha lista
    struct aluno dados[MAX]; // vetor da estrutura alunos que terá ate 100 alunos.
};

Lista* cria_lista(){

    Lista *li; //ponteiro

    li = (Lista*) malloc(sizeof(struct lista)); // crie memoria para a varial struct lista

    if (li != NULL){ // verificação da criação da lista
        li -> qtd = 0;
    }

    return li;
};

void libera_lista(Lista* li){
    free(li); // malloc -> free
};


// INFORMAÇÕES SOBRE A LISTA


// Como descobrir o tamanho da lista?
int tamanho_lista(Lista* li){
    if (li == NULL)
        return -1;
    else
        return li -> qtd; // '->' == acesso ao conteudo do ponteiro
};

//Como descobrir se a lista cheia?
int lista_cheia(Lista* li){
    if(li == NULL)
        return -1;
    return (li -> qtd == MAX);
};

//Como descobrir se a lista vazia?
int lista_vazia(Lista* li){
    if(li == NULL)
        return -1;
    return (li -> qtd == 0);
};

/*INSERÇÃO NA LISTA ESTATICA (NO INCIO, NO MEIO OU NO FIM)

/ em uma lista vazia:
li -> dados[0] = al;
li -> qtd++;

*/ 

// inserir elemento no fim da lista
int insere_lista_final(Lista* li, struct aluno al){

    if (li == NULL)
        return 0;
    if (lista_cheia(li))
        return 0;

    li -> dados[li->qtd] = al;
    li -> qtd++;

    return 1;
};

// inserir elemento no inicio da lista
int insere_lista_inicio(Lista* li, struct aluno al){

    if (li == NULL)
        return 0;
    if (lista_cheia(li))
        return 0;

    for(int i = li -> qtd-1; i >= 0; i--)
        li -> dados[i+1] = li -> dados[i];

    li -> dados[0] = al;
    li -> qtd++;

    return 1;
};

// inserir elemento de forma ordenada 9pode ser no fim, no inicio ou no meio)
int insere_lista_ordenada(Lista* li, struct aluno al){

    if (li == NULL) // se a lista é valida
        return 0;
    if (lista_cheia(li))
        return 0;

    int i, k = 0;
    while (i < li ->qtd && li -> dados[i].matricula < al.matricula) // busca, aonde iremos inserir o novo elemento
        i++;

    for(k = li -> qtd-1; k >= i; k--)
        li -> dados[k+1] = li -> dados[k];

    li -> dados[i] = al;
    li -> qtd++;

    return 1;
};

/*REMOÇÃO NA LISTA ESTATICA (NO INCIO, NO MEIO OU NO FIM)
    - - não se pode remover em uma lista vazia */ 

// remover elemento no fim da lista
int remove_lista_final(Lista* li){

    if (li == NULL)
        return 0;
    if (li -> qtd == 0)
        return 0;

    li -> qtd--;

    return 1;
};

// remover elemento no inicio da lista
int remove_lista_inicio(Lista* li){

    if (li == NULL)
        return 0;
    if (li -> qtd == 0)
        return 0;

    for (int k=0; k < li -> qtd-1; k++)
        li -> dados[k] = li -> dados[k+1];

    li -> qtd--;

    return 1;
};

// remover qualquer elemento da lista
int remove_lista(Lista* li, int mat){

    if (li == NULL)
        return 0;
    if (li -> qtd == 0)
        return 0;

    int k,i = 0;
    while( i < li -> qtd && li -> dados[i].matricula != mat)
        i++;

    if (i == li -> qtd)
        return 0;

    for (int k=i; k < li -> qtd-1; k++)
        li -> dados[k] = li -> dados[k+1];

    li -> qtd--;

    return 1;
};

// Consulta por posição
int consulta_lista_pos(Lista* li, int pos, struct aluno *al){

    if (li == NULL || pos <= 0 || pos > li-> qtd)
        return 0;

    *al = li -> dados[pos-1];

    return 1;
};

// consulta pela conteudo, nesse exemplo, pela matricula
int consulta_lista_mat(Lista* li, int mat, struct aluno *al){

    if (li == NULL)
        return 0;

    int k, i = 0;

    while(i <li -> qtd && li -> dados[i].matricula != mat)
        i++;

    if (i == li -> qtd)
        return 0;

    *al = li -> dados[i];

    return 1;
};


void main(){

    Lista *li; // para definir: um ponteiro do tipo lista;

    li = cria_lista();
    libera_lista(li);

    int x = tamanho_lista(li);
    if(lista_cheia(li)); // V = 1 ou F = 0
    if(lista_vazia(li)); // V = 1 ou F = 0

    int y = insere_lista_final(li, dados_aluno);
    int y = insere_lista_inicio(li, dados_aluno);
    int y = insere_lista_ordenada(li, dados_aluno);

    int z = remove_lista_final(li);
    int z = remove_lista_inicio(li);
    int z = remove_lista(li, matricula_aluno);

    int b = consulta_lista_pos(li, posicao, &dados_alunos);
    int b = consulta_lista_mat(li, posicao, &dados_aluno);
    
};
