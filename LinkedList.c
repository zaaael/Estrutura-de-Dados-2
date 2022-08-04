#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"

void init(LinkedList *list){
    list->first=NULL;
    list->size=0;
}
int enqueue(LinkedList *list, void *data){

    Node* novono = (Node*)malloc(sizeof(Node));
    if(novono == NULL) return -1;
    novono->data = data;
    novono->next = NULL;

    if (isEmpty(list)){ //Se a lista estiver vazia
        list->first = novono;  //Novo nó é o primeiro
    }
    else{

        Node* aux = list->first; //Aux recebe o primeiro
        while(aux->next != NULL){ //Enquanto não for o último nó
            aux = aux->next;      //Aux avança para o nó seguinte
        }
        aux->next = novono; //Último nó aponta para o novo nó

    }

    list->size++;
    return 1;
}

bool isEmpty(LinkedList *list){

    return list->first==NULL;
}

void* dequeue(LinkedList *list){

    Node* aux;
    if (isEmpty(list)) return NULL;

    aux = list->first; //aux pega o primeiro nó da lista
    list->first = list->first->next; //primero nó passa a ser o próximo da lista
    void *data = aux->data;
    free(aux);
    list->size --;
    return data;
}

void* first(LinkedList *list){
     if (isEmpty(list)) return NULL; //Se a lista estiver vazia ele retorna NULL
     return list->first->data; //retornamos o endereço guardado no primeiro nó
}

void* last(LinkedList *list){

    if (isEmpty(list)) return NULL;
    Node* aux = list->first; //Aux recebe o primeiro
        while(aux->next != NULL){ //Enquanto não for o último nó
            aux = aux->next;      //Aux avança para o nó seguinte
    return aux->next;
}
}
int push(LinkedList *list, void *data){
    
}                         
