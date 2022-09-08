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
    if (listDest==NULL || isEmpty(listDest)) return -1;
    if (listSource==NULL || isEmpty(listSource)) return -2;
    Node *last = NULL;
    for (last = listSource->first;last->next!=NULL;last=last->next);
    if (pos == 0) {
        last->next = listDest->first;
        listDest->first = listSource->first;
    } else {
        Node *aux = getNodeByPos(listDest, (pos-1));
        if (aux==NULL) return -3;        
        last->next = aux->next; 
        aux->next = listSource->first;
    }
    listDest->size+=listSource->size;
    return listSource->size;
}

int indexOf(LinkedList *list, void *data, compare equal){
    if (isEmpty(list)) return -1;
    int count=0;
    Node *aux = list->first;
   
    while(aux!=NULL && !equal(aux->data,data)) {
        aux=aux->next;
        count++;
    }
    
    return (aux==NULL)?-1:count;
}

Node* getNodeByPos(LinkedList *list, int pos){
    if (isEmpty(list) || pos>=list->size) return NULL;
    Node *aux = list->first;
    for (int count=0;(aux!=NULL && count<pos);count++,aux=aux->next);
    return aux;
}

void* removePos(LinkedList *list, int pos){
    if (isEmpty(list) || pos>=list->size) return NULL;
    
    Node *nodeRemove = NULL;
    Node *aux = NULL;
       
    if (pos<=0)
        return dequeue(list);
    else
        aux = getNodeByPos(list, pos-1);
    nodeRemove = aux->next;
    aux->next = nodeRemove->next;
    
    void* dataRemove = nodeRemove->data;
    free(nodeRemove);
    list->size--;
    
    return dataRemove;
}

bool removeData(LinkedList *list, void *data, compare equal){
    if (isEmpty(list)) return -1;
    Node *nodeRemove = NULL;
    if (equal(list->first->data,data)) {
        nodeRemove = list->first;
        list->first = list->first->next;
        free(nodeRemove->data);
        free(nodeRemove);
        list->size--;
        return true;
    } else {
        Node *aux = list->first;
        while(aux->next!=NULL && !equal(aux->next->data,data))
            aux=aux->next;
    
        if (aux->next!=NULL) {
            Node *nodeRemove = aux->next;
            aux->next = nodeRemove->next;
            free(nodeRemove->data);
            free(nodeRemove);
            list->size--;
            return true;
        } else {
            return false;
        }
    }
}
