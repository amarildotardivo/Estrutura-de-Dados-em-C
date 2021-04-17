#include <stdio.h>
#include "TAD\fila\filaEncadeada.h"
#include "TAD\pilha\pilhaEncadeada.h"

#define quantidade_Itens_Fila 10

void inverterElementosFila(tipo_fila *F){
    int tamanho_fila, tamanho_pilha, TipoItem;
    tipo_pilha *P = NULL;
    
    P = criarPilha();

    tamanho_fila = tamanhoFila(F);
    for(int i = 0; i < tamanho_fila; i++){
        TipoItem = desemfileirar(F);
        empilhar(P, TipoItem);
    }

    tamanho_pilha = tamanhoPilha(P);
    printf("\n  Elementos Invertidos: ");
    for(int i = 0; i < tamanho_pilha; i++){
        TipoItem = desempilhar(P);

        printf(" [%d] ", TipoItem);
    }
}

int main(){
    int resultado;
    tipo_fila *F = NULL;

    F = criarFila();

    for(int i = 0; i < quantidade_Itens_Fila; i++){
        resultado = emfileirar(F, i + 1);
        if(resultado == 0){
            printf("\n\n    Ocorreu um erro ao ENFILEIRAR! Programa Finalizado!!!\n\n\n");
            return 0;
        }
    }

    inverterElementosFila(F);

    printf("\n\n");
    return 0;
}