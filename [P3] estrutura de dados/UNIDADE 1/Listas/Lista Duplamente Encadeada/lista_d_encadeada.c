#include <lista_d_encadeada.h>
#include <stdlib.h>
#include <stdio.h>


struct elemento {
    struct elemento *ant;
    struct aluno dados;
    struct elemento *prox;
};

typedef struct elemento Elem;

Lista* cria_lista(){
    Lista* li = (Lista*) malloc(sizeof(Lista));

    if(li != NULL)
        *li = NULL;

    return li;
};

void libera_lista(Lista* li){

    if(li != NULL){
        Elem* no;
        while ((*li) != NULL){
            no = *li;
            *li = (*li) -> prox;
            free(li);
        };
    };
};

// INFORMACOES DA LISTA - TAMANHO, ESTA CHEIA, OU ESTA VAZIA?

//tamanho da lista
int tamanho_lista(Lista* li){

    if (li ==NULL) return 0;
    int cont = 0;

    Elem* no = *li;

    while (no != NULL){
        cont++;
        no = no -> prox;
    }

    return cont;
};

//lista cheia
int lista_cheia(Lista* li){
    return 0;}

//lista vazia
int lista_vazia(Lista* li){

    if (li ==NULL)
        return 1;
    if(*li == NULL)
        return 1;

    return 0;
}

//inserção 

void main(){

    Lista *li;
    li = cria_lista();
    libera_lista(li);

    int x = tamanho_lista(li);
    int x = lista_cheia(li); //ou
    if (lista_cheia(li));
    int x = lista_vazia(li); //ou
    if (lista_vazia(li));
}