#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "tadArvoreBB3.h"

#define qtd_elementos 1000
#define range 10000

void aleatoriosDistintos(tipo_no_arvore arvore){
    int elemento;
    
    //Semente aleatória criada;
    srand(time(NULL));

    //Preenchendo a arvore
    for(int i = 0; i < qtd_elementos; i++){
        elemento = rand() % range;
        
        if(totalNos(arvore) == 0){
            incluir_no_arvore(arvore, elemento);
        }

        //Verificando se o elemento atual é igual a algum elemento da arvore
        while( encontrar_elemento(arvore, elemento) == 1 ){
            elemento = rand() % range;
        }
        
        incluir_no_arvore(arvore, elemento);
    }
}

int main()
{
    tipo_no_arvore arvore;

    arvore = inicializar_arvore(arvore);

    // QUESTAO 10 -------------------------------------------------------------
    aleatoriosDistintos(arvore);
    printf("\n\n  Listagem em ordem:\n");
    printf("    ");
    percurso_em_ordem(arvore);
    printf("\n\n  Encontrar 45: %d", encontrar_elemento(arvore, 45));
    printf("\n\n  Encontrar 550: %d", encontrar_elemento(arvore, 550));
    printf("\n\n  Encontrar 1056: %d", encontrar_elemento(arvore, 1056));
    printf("\n\n  Encontrar 7859: %d", encontrar_elemento(arvore, 7859));

    // QUESTAO 11 -------------------------------------------------------------
    /*
        OBS:
        QUANDO ENCONTRADO!-----------------------------------------------------
        COMPARAÇÕES DO ELEMENTO 45 COM ARVORE DE BUSCA BINARIA: 10
        COMPARAÇÕES DO ELEMENTO 45 NO VETOR DE BUSCA BINARIA: 10

        COMPARAÇÕES DO ELEMENTO 550 COM ARVORE DE BUSCA BINARIA: 10
        COMPARAÇÕES DO ELEMENTO 550 NO VETOR DE BUSCA BINARIA: 07

        COMPARAÇÕES DO ELEMENTO 1056 COM ARVORE DE BUSCA BINARIA: 12
        COMPARAÇÕES DO ELEMENTO 1056 NO VETOR DE BUSCA BINARIA: 10

        COMPARAÇÕES DO ELEMENTO 7859 COM ARVORE DE BUSCA BINARIA: 14
        COMPARAÇÕES DO ELEMENTO 7859 NO VETOR DE BUSCA BINARIA: 09

        QUANDO NÃO ENCONTRADO! ------------------------------------------------
        COMPARAÇÕES DO ELEMENTO 45 COM ARVORE DE BUSCA BINARIA: 10
        COMPARAÇÕES DO ELEMENTO 45 NO VETOR DE BUSCA BINARIA: 10

        COMPARAÇÕES DO ELEMENTO 550 COM ARVORE DE BUSCA BINARIA: 11
        COMPARAÇÕES DO ELEMENTO 550 NO VETOR DE BUSCA BINARIA: 10

        COMPARAÇÕES DO ELEMENTO 1056 COM ARVORE DE BUSCA BINARIA: 12
        COMPARAÇÕES DO ELEMENTO 1056 NO VETOR DE BUSCA BINARIA: 10

        COMPARAÇÕES DO ELEMENTO 7859 COM ARVORE DE BUSCA BINARIA: 13
        COMPARAÇÕES DO ELEMENTO 7859 NO VETOR DE BUSCA BINARIA: 10
    */
    printf("\n\n  Encontrar 45: %d", encontrar_elemento_comparacoes(arvore, 45));
    printf("\n\n  Encontrar 550: %d", encontrar_elemento_comparacoes(arvore, 550));
    printf("\n\n  Encontrar 1056: %d", encontrar_elemento_comparacoes(arvore, 1056));
    printf("\n\n  Encontrar 7859: %d", encontrar_elemento_comparacoes(arvore, 7859));

    return 0;
}