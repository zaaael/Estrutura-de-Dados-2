#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "log.h"

void init(LinkedList *list){
    log_info("Inicializando a Lista");
    log_trace("Entrando em init");
    list->first=NULL;
    list->size=0;
    log_debug("list->first: %p", list->first);
    log_debug("list->size: %p", list->size);
    log_trace("Saindo de init");
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
    Node* novono = (Node*)malloc(sizeof(Node));
    if(novono == NULL) return -1;
    novono->data = data;
    novono->next = NULL;

    if (isEmpty(list)){ //Se a lista estiver vazia
        list->first = novono;  //Novo nó é o primeiro
    }
    else{

        Node* aux = list->first; //Aux recebe o primeiro
        list->first = novono;
        list->size++;
    }
    return 1;
    
}

void* pop(LinkedList *list){
    dequeue(list);
}

void* top(LinkedList *list){
 first(list);
}

int add(LinkedList *list, int pos, void *data){

    int cont=0;
    Node* novono = (Node*)malloc(sizeof(Node));
    if(novono == NULL) return -1;
    novono->data = data;
    novono->next = NULL;
    Node* aux = list->first; //Aux recebe o primeiro
        while(cont != pos-1 && aux->next != NULL){ 
            cont++;
            aux = aux->next;   
        }
        
        novono->next = aux->next;
        aux->next = novono; //Último nó aponta para o novo nó

        list->size++;

        return 1;
}

void* getPos(LinkedList *list, int pos){
        int cont=0;
    Node* novono = (Node*)malloc(sizeof(Node));
    if(novono == NULL) return NULL;

    Node* aux = list->first; //Aux recebe o primeiro
        while(cont != pos && aux->next != NULL){ 
            cont++;
            aux = aux->next;      
        }

        if(aux = NULL){
            return NULL;
        }
        else{
        return aux->data;
        }
}

int addAll(LinkedList *listDest, int pos, LinkedList *listSource){
    
}