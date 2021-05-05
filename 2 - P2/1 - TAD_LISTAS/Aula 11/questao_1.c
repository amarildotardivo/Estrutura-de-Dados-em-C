#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "TAD\tadArvoreBB3.h"

#define tamanho 50
#define range 1000

int main(){
    tipo_no_arvore arvore, arvore2;
    int elemento;

    srand(time(NULL));

    arvore = inicializar_arvore(arvore);
    arvore2 = inicializar_arvore(arvore2);

    for(int i = 0; i < tamanho; i++){
        elemento = rand() % range;
        incluir_no_arvore(arvore, elemento);
    }
    printf("\n\n");
    printf("\nArvore - a original:\n\n");
    percurso_em_pre_ordem(arvore);
    printf("\n\n");

    copia_arvore_em_pre_ordem(arvore, arvore2);

    printf("\n\n");
    printf("\nArvore 2 - a copia:\n\n");
    percurso_em_pre_ordem(arvore2);
    printf("\n\n");

    return 0;
}