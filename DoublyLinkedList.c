#include <stdio.h>
#include <stdlib.h>
#include "DoublyLinkedList.h"

void init(DoublyLinkedList *list){
    Node *trashNode = (Node*)malloc(sizeof(Node));  //trashNode é igual a Nó de lixo.
    trashNode->data = NULL;
    trashNode->previous = trashNode;
    trashNode->next = trashNode;
    list->first = trashNode;
    list->size = 0;

}

int enqueue(DoublyLinkedList *list, void *data){ // Nesse caso o previous se refere ao final da lista
    Node *novono = (Node*)malloc(sizeof(Node));
    if(novono == NULL) return -1;
    novono->data = data;
    novono->next = list->first;
    novono->previous = list->first->previous;
    list->first->previous->next = novono;
    list->first->previous = novono;
    list->size ++;
    return 1;
}
void* dequeue(DoublyLinkedList *list){
    Node *sentinela = list->first;
    Node *primeiro = list->first->next;
    if(list->first == NULL) return NULL;
    primeiro->next->previous = sentinela;
    sentinela->next = primeiro->next;
    void *data = primeiro->data;
    free(primeiro);
    list->size --;
    return data;
}

void* first(DoublyLinkedList *list){
    if(list->first == NULL) return NULL;
    return list->first->next->data;
}

void* last(DoublyLinkedList *list){
    return list->first->previous->data;
}
int push(DoublyLinkedList *list, void *data){
    Node* novono = (Node*)malloc(sizeof(Node));
    if(novono == NULL) return -1;
    novono->data = data;
    novono->next = list->first->next;
    novono->previous = list->first;
    list->first->next->previous = novono;
    list->first->next = novono;
    list->size ++;
}

void* pop(DoublyLinkedList *list){
    return dequeue(list);
}

void* top(DoublyLinkedList *list){
return first(list);
}

bool isEmpty(DoublyLinkedList *list){
    return (list->size == 0);
}

int indexOf(DoublyLinkedList *list,void *data, compare equal){
    if(isEmpty(list)) return -1;
    int count = 0;
    Node *aux = list->first->next;
    while(aux != list->first && !equal(aux->data, data)){
        aux = aux->next;
        count++;
    }
    return (aux==list->first)?-1:count;
}

    Node* getNodeByPos(DoublyLinkedList *list,int pos){
    if (isEmpty(list) || pos>=list->size) return NULL;
    Node *aux = list->first->next;
    for (int count=0;(aux!=list->first && count<pos);count++,aux=aux->next);
    return aux;
}

void* getPos(DoublyLinkedList *list,int pos){
    Node *res = getNodeByPos(list,pos);
    return (res==NULL)?NULL:res->data;
}

int add(DoublyLinkedList *list, int pos, void *data){
    Node *aux = getNodeByPos(list, pos);
    if (aux==NULL) return -2;
    Node *newNode = (Node*) malloc(sizeof(Node));
    if (newNode==NULL) return -1;
    newNode->data = data;
    newNode->next = aux;
    newNode->previous = aux->previous;
    aux->previous->next = newNode;
    aux->previous = newNode;
    list->size++;
    return 1;
}

int addAll(DoublyLinkedList *listDest, int pos, DoublyLinkedList *listSource){
    Node *aux = getNodeByPos(listDest, pos);
    if(aux==NULL) return -2;
    if(isEmpty(listSource)) return -1;
    listSource->first->previous->next = aux;
    listSource->first->next->previous = aux->previous;
    aux->previous->next = listSource->first->next;
    aux->previous = listSource->first->previous;
    listDest->size+=listSource->size;
    }

void* removePos(DoublyLinkedList *list, int pos){
    if (isEmpty(list) || pos>=list->size) return NULL;
    Node *nodeRemove = getNodeByPos(list, pos);
    nodeRemove->previous->next = nodeRemove->next;
    nodeRemove->next->previous = nodeRemove->previous;
    void* dataRemove = nodeRemove->data;
    free(nodeRemove);
    list->size--;
    return dataRemove;
}

bool removeData(DoublyLinkedList *list, void *data, compare equal){
    if (isEmpty(list)) return -1;
    Node *nodeRemove = list->first->next;
    while(nodeRemove!=list->first && !equal(nodeRemove->data,data))
        nodeRemove=nodeRemove->next;
    if (nodeRemove!=list->first) {
        nodeRemove->previous->next = nodeRemove->next;
        nodeRemove->next->previous = nodeRemove->previous;
        free(nodeRemove->data);
        free(nodeRemove);
        list->size--;
        return 1;
    } else {
        return 0;
    }
}


void show(DoublyLinkedList *list, printNode print){
    Node *aux = list->first->next;
    while (aux!=list->first) {
        print(aux->data);
        aux=aux->next;
    }
    printf("\n");
}

void showMem(DoublyLinkedList *list){
    printf("Trash Node: %p\n\n",list->first);
    Node *aux = list->first->next;
    printf("Node Addr : Previous - Data - Next\n\n");
    while (aux!=list->first) {
        printf("%p: %p - %p - %p\n",aux, aux->previous, aux->data, aux->next);
        aux=aux->next;
    }
}
