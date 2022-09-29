#include <stdlib.h>
#include <stdio.h>
#include "Hash.h"
#include "DoublyLinkedList.h"
#define MAX 10

void initHash(HashStruct *hashStruct){
    for(int i=0; i<MAX; i++){
        init(&(hashStruct->hashes[i]));
    }
    HashStruct->size = 0;
}

bool isHashEmpty(HashStruct *hashStruct);{
    return(hashStruct->size == 0);
}

int hash(char *key){
    int sum = 0;
    for(int i=0; key[i]!=0; i++){
        sum += key[i]*(i+1);
    }
    return(sum%MAX);
}

int put(HashStruct *hashStruct, char *key, void *data, compare equal){
    if(!containsKey(hashStruct, key)){
    int res = enqueue(&hashStruct->hashes[hash(key)], data);
    hashStruct->size+=res; 
    }
    return 0;
}

bool containsKey(HashStruct *hashStruct, char *key, compare equal){
    int hashvalue = hash(key);
    int pos = indexOf(&hashStruct->hashes[hashvalue], key, equal);
    return(pos!=-1)?true:false;
}

void* get(HashStruct *hashStruct, char *key, compare equal){
    int hashvalue = hash(key);
    Node *aux = hashStruct->hashes[hashvalue].first->next;
}

void* removeKey(HashStruct *hashStruct, char *key, compare equal){

}

void showHashStruct(HashStruct *hashStruct){

}
