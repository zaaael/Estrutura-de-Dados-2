#include <stdlib.h>
#include <stdio.h>
#include "Stack.h"


void init(Stack *stack){ //inicio
    Node *novono = (Node*)malloc(sizeof(Node));
    if(novono == NULL) return -1;

    novono->data = NULL;
    novono->under = NULL;
    stack->size = 0;
    stack->top = novono;


}  

bool push(Stack *stack, void *data){ //remove inicio
    Node *aux = (Node*)malloc(sizeof(Node));
    if(novono == NULL) return -1;
    aux->data = data;
    aux = stack->top;
    stack->top = stack->under;
    free(aux->data);
    free(aux);

}

void* pop(Stack *stack){ //adiciona no final
    Node *novono = (Node*)malloc(sizeof(Node));
    if(novono == NULL) return -1;
    void* data = novono->data;
    if(isEmpty(stack)){
        stack->top = novono;
    }
    else{
    Node *aux = stack->top;
    while(aux->under != NULL){
            aux = aux->under++;
        }
        aux->under = novovo;

    }
    stack->size++;
}

void* top(Stack *stack){ //adiciona no inicio
    Node *novono = (Node*)malloc(sizeof(Node));
    if(novono == NULL) return -1;
    void* data = novono->data;
    
    if(isEmpty(stack)){
        stack->top = novono;
    }
    stack->size ++;
}   

bool isEmpty(Stack *stack){
    return(stack->size == 0);
}   

void show(Stack *stack){

    Node *aux = stack->top;
    while(aux->under != NULL){
            printf(aux->data);
            aux = aux->under++;
        }

    } 