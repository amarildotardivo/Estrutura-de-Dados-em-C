#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "TAD\tadArvoreBB3.h"

#define tamanho 10
#define range 200

int main(){
    tipo_no_arvore arvore;
    int elemento;

    srand(280);

    arvore = inicializar_arvore(arvore);

    for(int i = 0; i < tamanho; i++){
        elemento = rand() % range;
        incluir_no_arvore(arvore, elemento);
    }
    //ARVORE GERADA
    //152 17 7 102 83 48 89 124 137
    printf("\n\n");
    printf("\nArvore - Amarildo: 201621200280\n\n");
    percurso_em_pre_ordem(arvore);
    printf("\n\n");
    

    return 0;
}