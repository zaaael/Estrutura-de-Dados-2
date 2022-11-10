#include <stdlib.h>
#include <stdio.h>
#include "Autocomplete.h"

int main() {
    Node *lista[26];

    for(int i = 0; i < 26; i++) {
        lista[i] = NULL;
    }

    char entrada[MAX];
    char saida[MAX];
    
    int opc = 0;

    do {
        printf("\n");
        printf("Escolha uma opção: \n");
        printf("(1) - Adicionar palavra;\n");
        printf("(2) - Buscar palavra;\n");
        printf("(0) - Sair.\n");
        scanf("%d", &opc);

        switch ( opc ) {
            case 1 :
                printf("\nDigite a palavra: ");
                scanf("%s", entrada);
                printf("Entrada: %s\n", entrada);
                add(&lista[0], entrada);
                printf("\n");
                break;
            case 2 :
                printf("\nProcurar a palavra: ");
                scanf("%s", entrada);
                printf("Entrada: %s\n", entrada);
                found(lista[0], entrada);
                printf("\n");
                break;
            case 0 :
                printf("\n");
                printf("Saindo.\n");
                break;
            default :
                printf("\n");
                printf("Opção inválida.\n");
        }
    } while (opc != 0);

    read(&lista[0]);

    return EXIT_SUCCESS;
}