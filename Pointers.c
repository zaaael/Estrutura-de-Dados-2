#include <stdio.h>
#include <stdlib.h>

int main(){

    int number = 10;
    int* numberP = &number;
    int** numberPP = &numberP;

    printf("\nValor da variavel number: %d", number);
    printf("\nEnderesso da variavel number: %p", &number);
    printf("\nValor da variavel numberP: %p", numberP);
    printf("\nValor apontado por numberP: %d", *numberP);
    printf("\nEnderesso de memoria da var numberP: %p\n", &numberP);
    printf("Enderesso de memoria da var numberPP: %p\n", &numberPP);
    printf("Conteudo de numberPP: %p\n", numberPP);
     printf("Valor apontado no primeiro nivel por numberPP: %p\n", *numberPP);
     printf("Valor apontado no segundo nivel por numberPP: %d\n\n", **numberPP);
    //numberP++;
    //printf("\nValor da variavel numberP++: %p", numberP);
    

   /* float* pi = (float *)malloc(sizeof(float));
    printf("Endereço de pi: %p\n", pi);
    *pi = 3.1415;
    //*pi = 0;
    free(pi);
    printf("Valor de pi após free: %f\n", *pi);
    printf("Endereço após free: %p\n", pi);
    pi = NULL;
    printf("Endereço após free receber NULL: %p\n", pi);
*/
    return EXIT_SUCCESS;
}