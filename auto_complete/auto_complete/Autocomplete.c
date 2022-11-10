#include <stdlib.h>
#include <stdio.h>
#include <locale.h>
#include <string.h>

#include "Autocomplete.h"

int buildNode(Node **newNode) {
    Node *aux = (Node *)malloc(sizeof(Node));
    if(aux == NULL) {
        return -1;
    }
    aux->data = (char *)malloc(sizeof(char));
    if(aux->data == NULL) {
        return -1;
    }
    aux->next = NULL;
    aux->under = NULL;
    *aux->data = '\0';
    *newNode = aux;
    return 1;
}

void add(Node **list, char palavra[MAX]) {
    int i = 0;
    Node *newNode;
    Node *auxlist = NULL;
    if(*list == NULL) {
        buildNode(&newNode);
        *newNode->data = palavra[i];
        *list = newNode;
    }
    auxlist = *list;
    // printf("add: %d Letra: %c\n", i, *auxlist->data); 
    i++;
    for(i; palavra[i] != '\0' && i < (MAX - 1); i++) {
        if(auxlist->next == NULL) {
            buildNode(&newNode);
            *newNode->data = palavra[i];
            auxlist->next = newNode;
            auxlist = auxlist->next;  
            // printf("add: %d Letra: %c\n", i, *auxlist->data);
        }
        else if(*auxlist->next->data == palavra[i]) {
            auxlist = auxlist->next;
            // printf("add: %d Letra: %c\n", i, *auxlist->data);
        } 
        else if(*auxlist->next->data == '\0') {
            auxlist = auxlist->next;
            if(auxlist->next == NULL) {
                buildNode(&newNode);
                *newNode->data = palavra[i];
                auxlist->next = newNode;
                auxlist = auxlist->next; 
                // printf("add: %d Letra: %c\n", i, *auxlist->data);
            }
            else if(*auxlist->next->data == palavra[i]) {
                auxlist = auxlist->next;
                // printf("add: %d Letra: %c\n", i, *auxlist->data);
            }
            else if(*auxlist->next->data != palavra[i]) {
                if(auxlist->under != NULL) {
                    for(auxlist; auxlist->under != NULL; auxlist = auxlist->under) {
                        if(*auxlist->next->data == palavra[i]) {
                            auxlist = auxlist->next;
                            // printf("add: %d Letra: %c\n", i, *auxlist->data);
                            break;
                        }
                    }
                }
                if(*auxlist->data != palavra[i] && auxlist->under == NULL) {
                    buildNode(&newNode);
                    auxlist->under = newNode;
                    auxlist = auxlist->under;
                    buildNode(&newNode);
                    *newNode->data = palavra[i];
                    auxlist->next = newNode;
                    auxlist = auxlist->next;
                    // printf("add: %d Letra: %c\n", i, *auxlist->data);
                }
            }
        }
        else if(*auxlist->next->data != palavra[i]) {
            if(auxlist->under != NULL) {
                for(auxlist; auxlist->under != NULL; auxlist = auxlist->under) {
                    if(*auxlist->next->data == palavra[i]) {
                        auxlist = auxlist->next;
                        // printf("add: %d Letra: %c\n", i, *auxlist->data);
                        break;
                    }
                }
            }
            if(*auxlist->data != palavra[i] && auxlist->under == NULL) {
                buildNode(&newNode);
                auxlist->under = newNode;
                auxlist = auxlist->under;
                buildNode(&newNode);
                *newNode->data = palavra[i];
                auxlist->next = newNode;
                auxlist = auxlist->next;
                // printf("add: %d Letra: %c\n", i, *auxlist->data);
            }
        }
    }
    if(auxlist->next == NULL) {
        buildNode(&newNode);
        auxlist->next = newNode;
    }
    else if(*auxlist->next->data != '\0') {
        buildNode(&newNode);
        newNode->next = auxlist->next;
        auxlist->next = newNode;
    }
    // printf("add: %d Letra: nula\n", i);
}

void show(Node *list, char palavra[MAX], int pos) {
    if(list != NULL) {
        Node *aux = list;
        palavra[pos] = *aux->data;
        // printf("show: %d Letra: %c\n", pos, *aux->data);
        pos++;
        for(aux; aux->next != NULL; aux = aux->next) {
            while(aux->under != NULL) {
                show(aux->next, palavra, pos);
                aux = aux->under;
            }
            if(*aux->next->data == '\0') {
                palavra[pos] = *aux->next->data;
                // printf("show: %d Letra: nula\n", pos);
                printf("Saída: %s\n", palavra);
            }
            else
            {
                palavra[pos] = *aux->next->data;
                // printf("show: %d Letra: %c\n", pos, *aux->next->data);
                pos++;
            }
        }
    }
}

int found(Node *list, char procurar[MAX]) {
    if(list != NULL) {
        int pos = 0;
        Node *auxlist = list;
        // printf("found: %d Letra: %c\n", pos, *auxlist->data);
        pos++;
        for(pos; procurar[pos] != '\0'; pos++) {
            if(auxlist->next == NULL) {
                printf("Sem registros.\n");
                return 0;
            }
            else if(*auxlist->next->data == procurar[pos]) {
                auxlist = auxlist->next;
                // printf("found: %d Letra: %c\n", pos, *auxlist->data);
            }
            else if(*auxlist->next->data != procurar[pos]) {
                if(auxlist->under != NULL) {
                    Node *aux = auxlist;
                    for(aux; aux->under != NULL; aux = aux->under) {
                        if(*aux->next->data == procurar[pos]) {
                            auxlist = aux->next;
                            // printf("found: %d Letra: %c\n", pos, *auxlist->data);
                            break;
                        }
                    }
                }
                else if(*auxlist->next->data == '\0') {
                    auxlist = auxlist->next;
                    if(auxlist->next == NULL) {
                        printf("Sem registros.\n");
                    return 0;
                    }
                    else if(*auxlist->next->data == procurar[pos]) {
                        auxlist = auxlist->next;
                        // printf("found: %d Letra: %c\n", pos, *auxlist->data);
                    }
                    else if(*auxlist->next->data != procurar[pos]) {
                        if(auxlist->under != NULL) {
                            Node *aux = auxlist;
                            for(aux; aux->under != NULL; aux = aux->under) {
                                if(*aux->next->data == procurar[pos]) {
                                    auxlist = aux->next;
                                    // printf("found: %d Letra: %c\n", pos, *auxlist->data);
                                    break;
                                }
                            }
                        }
                        else {
                            printf("Sem registros.\n");
                            return 0;
                        }
                    }
                }
            }
            }
        pos--;
        show(auxlist, procurar, pos);
    }
    else {
        printf("Sem registros.\n");
        return 0;
    }
    return 1;
}

void read(Node *list[26]) {
    char palavra[MAX];

    FILE *arquivo;
    arquivo = fopen("ListaDePalavrasPT.txt", "r");

    if(arquivo == NULL) {
        printf("Erro ao tentar abrir o arquivo\n");
    }
    else {     
        while(fscanf(arquivo,"%[^\n]%*c\n", palavra)!=EOF) {
            printf("Entrada: %s\n", palavra);
            add(&list[palavra[0]], palavra);
            found(list[palavra[0]], palavra);
        }
	}

    fclose(arquivo);
}
