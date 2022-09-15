#include <stdio.h>
#include <stdlib.h>
#include "GeneralizedLinkedList.h"

int addAtom(Node **list, int atom){ //adiciona um átomo na lista;

    Node* novono = (Node*)malloc(sizeof(Node));
    if(novono == NULL) return -1;

    novono->type = 0;
    novono->next = NULL;
    novono->atomList.atom = atom;
    
    if(*list == NULL){
        *list = novono;
    }
    else{
    Node* aux = NULL;
    for(aux = *list; aux->next != NULL; aux = aux->next){
        aux = novono;
    }

        return 1;
}
}

int addList(Node **list, Node **subList){ //adiciona uma sublista na lista;

    Node* novono = (Node*)malloc(sizeof(Node));
    if(novono == NULL) return -1;

    novono->type = 1;
    novono->next = NULL;
    novono->atomList.list = *subList;
    
    if(*list == NULL){
        *list = novono;
    }
    else{
    Node* aux = NULL;
    for(aux = *list; aux->next != NULL; aux = aux->next){
        aux = novono;
    }

        return 1;
}
}

Node* head(Node *list){ //retorna o primeiro elemento da lista (átomo ou lista);

    Node *aux = NULL;
    
    if(list->type == 0){
    aux = (Node*)malloc(sizeof(Node));

    aux->type = 0;
    aux->next = NULL;
    aux->atomList.atom = list->atomList.atom;
    }
    else{
    aux = list->atomList.list;
    }
    return aux;
}

Node* tail(Node *list){ //retorna o resto (uma outra lista, mesmo que vazia).
 return list->next;
}

void show(Node *list){ //exibe a lista.

    Node* aux = NULL;
    for(aux = list; aux->next != NULL; aux->next++){
        if(aux->type == 0){
            printf("\n %d", aux->atomList.atom);
        }
        else{
            show(aux->atomList.list);
        }
    }
}

bool search(Node *list, int atom){ // localiza um átomo na lista;
    Node *aux = NULL;
    for(aux = list; aux != NULL; aux->next++){
        if(aux->type == 0){
             aux->atomList.atom;
        }
        else{
           aux->atomList.list;
        }
    }
}

int depth(Node *list){ //retorna a profundidade da lista;
    int profundidadeAtual = 0;
    if (list==NULL)
        return 0;
    
    Node *aux = NULL;
    for (aux = list; aux != NULL; aux=aux->next) {
        if (aux->type==1) {
            int prof = depth(aux->atomList.list);
            if (prof>profundidadeAtual)
                profundidadeAtual=prof;
        }
    }
    return profundidadeAtual+1;
}