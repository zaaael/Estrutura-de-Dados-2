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