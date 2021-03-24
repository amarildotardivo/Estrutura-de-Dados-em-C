#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct no{
    char nome[20];
    struct no *proximo;
}tipo_no;

int main(){
    int resul;
    char nome[20] = {"amarildo"};
    tipo_no *anterior = NULL, *novo, *atual;
    
    strcpy(novo -> nome, nome);
    resul = strcmp(novo -> nome, anterior -> nome);
    printf("%d", resul);

    resul = strcmp(novo -> nome, atual -> nome);

}