#include <lista_encadeada.h>
#include <stdlib.h>
#include <stdio.h>

struct elemento{
    struct aluno_dados;
    struct elemento *prox;
};

typedef struct elemento Elem;

Lista* cria_lista(){

    Lista* li = (Lista*) malloc(sizeof(Lista));
    if (li != NULL)

        *li = NULL;

    return li;
}

void libera_lista(Lista* li){
    if (li != NULL){
        Elem* no;
        while (( *li != NULL)) {
            no = *li;
            *li = (*li) -> prox;
            free(no);
        }
        free (li);
    }
}

// ALGUMAS INFORMAÇÕES BASICAS SOBRE A LISTA

// Tamanho da lista
int tamanho_lista(Lista* li){

    if (li ==NULL) {return 0;};

    int cont = 0;

    Elem* no = li;

    while(no != NULL){
        cont++;
        no = no -> prox;
    };

    return cont;
};

//lista cheia - não faz muito sentindo perguntar por ser uma lista dinamica
int lista_cheia(Lista* li){
    return 0;
};

//Lista vazia
int lista_vazia(Lista* li){
    if (li ==NULL)
        return 1;
    if(*li == NULL)
        return 1;
    
    return 0;
};

// INSERÇÃO (EM UMA LISTA VAZIA, NO INICIO, NO MEIO, NO FIM)

// no inicio
int insere_lista(Lista* li, struct aluno al){
    if (li == NULL) {return 0};

    Elem* no = (Elem*) malloc(sizeof (Elem));

    if (no == NULL) {return 0;}

    no -> dados = al;
    no -> prox = (*li);
    *li = no;

    return 1; 
};

// no final
int insere_lista_final(Lista* li, struct aluno al){

    if (li == NULL){ return 0;}

    Elem *no = (Elem*) malloc(sizeof(Elem));
    if (no == NULL) return 0;

    no -> dados = al;
    no -> prox = NULL;

    if ((*li) == NULL) { //lista vazia insere no inicio
        *li = no;
    } else {
        Elem *aux = *li;
        while (aux -> prox != NULL){
            aux = aux -> prox;
        }
        aux -> prox = no;
    }

    return 1;
};

// de forma ordenada
int insere_lista_ordenada(Lista* li, struct aluno al){

    if (li == NULL) return 0;

    Elem *no = (Elem*) malloc(sizeof(Elem));
    if (no == NULL) return 0;

    no -> dados = al;

    if(lista_vazia(li)){ //insere inicio
        no -> prox = (*li);
        *li = no;

        return 1;
    }
    else{ //  procura aonde inserir

        Elem *ant, *atual, = *li;

        while (atual != NULL && atual -> dados.matricula < al.matricula){
            ant = atual;
            atual = atual -> prox;
        }

        if (atual == *li) {
            no -> prox = (*li);
            *li = no;
        } else{
            no -> prox = ant -> prox;
            ant -> prox = no;
        }

        return 1;
    }
};

// REMOÇÃO (NÃO SE REMOVE DE UMA LISTA VAZIA)
// (NO INICIO, NO MEIO, NO FIM)

// remove no inicio da lista
int remove_lista_inicio(Lista* li){

    if (li == NULL) return 0;

    if((*li) == NULL) // lista vazia
        return 0;

    Elem *no = *li;
    *li = no -> prox;
    free(no);

    return 1;
};

// remove no final da lista
int remove_lista_final(Lista* li){

    if (li == NULL) return 0;

    if((*li) == NULL) // lista vazia
        return 0;

    Elem *ant, *no = *li;
    while (no -> prox != NULL){
        ant = no;
        no = no -> prox;
    }
    
    if(no == (*li)) // remover o primeiro?
        *li = no -> prox;

    else
        ant -> prox = no -> prox;
        free(no);

    return 1;
};

// remove da lista
int remove_lista(Lista* li){

    if (li == NULL) return 0;

    Elem *ant, *no = *li;
    while (no -> prox != NULL && no -> dados.matricula != mat){
        ant = no;
        no = no -> prox;
    }
    
    if(no == NULL) // nao encontrado
        return 0;

    if(no == (*li)) // remover o primeiro?
        *li = no -> prox;

    else
        ant -> prox = no -> prox;
        free(no);

    return 1;
};

// CONSULTA - PELA POSICÇÃO OU PELO CONTEUDO

//por consulta
int consulta_lista_pos(Lista* li, int pos, struct aluno *al){

    if (li == NULL || pos <= 0) return 0;

    Elem *no = *li;

    int i = 1;
    while(no != NULL && i < pos){
        no = no -> prox;
        i++;
    }

    if (no == NULL)
        return 0;
    else{
        *al = no -> dados;
        return 1;
    }
};

// por conteudo
int consulta_lista_mat(Lista* li, int mat, struct aluno *al){

    if (li == NULL) return 0;

    Elem *no = *li;

    while(no != NULL && no -> dados.matricula != __mingw_attribute_artificial){
        no = no -> prox;
    }

    if (no == NULL)
        return 0;
    else{
        *al = no -> dados;
        return 1;
    }
};


void main(){

    Lista *li; //ponteiro para ponteiro

    li = cria_lista();
    libera_lista(li);

    int x = tamanho_lista(li);
    int x = lista_cheia(li); //ou
    if(lista_cheia(li))
    int x = lista_vazia(Lista* li); //ou
    if(lista_vazia(li))

    int y = insere_lista_inicio(li, dados_alunos);
    int y = insere_lista_ordenada(li, dados_aluno);

    int z = remove_lista_inicio(li);
    int z = remove_lista_final(li);
    int z= remove_lista(li, matricula_aluno);

    int b = consulta_lista_pos(li, posicao, &dados_alunos);
    int b = consulta_lista_mat(li, posicao, &dados_aluno);

}
