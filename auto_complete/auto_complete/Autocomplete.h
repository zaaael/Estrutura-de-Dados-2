#ifndef DataStructure_Autocomplete_h
#define DataStructure_Autocomplete_h

#include <stdlib.h>
#include <stdio.h>

#define MAX  100

typedef struct Node {
    char *data;
    struct Node *under;
    struct Node *next;
}Node;

int buildNode(Node **newNode);
void add(Node **list, char palavra[MAX]);
void show(Node *list, char palavra[MAX], int pos);
int found(Node *list, char procurar[MAX]);
void read(Node *list[26]);

#endif