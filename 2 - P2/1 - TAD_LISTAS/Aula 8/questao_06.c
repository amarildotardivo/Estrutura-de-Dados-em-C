#include <stdio.h>
#include <string.h>
#include "TAD\pilha\pilhaEncadeadaString.h"

int verificaParenteses(char expressao[21]){
    int tamanho_expressao, tamanho_pilha;
    int abre_parenteses = 0, fecha_parenteses = 0;
    int resultado;
    tipo_pilha *pilha = NULL;

    pilha = criarPilha();

    tamanho_expressao = strlen(expressao);
    
    for(int i = 0; i < tamanho_expressao; i++){
        if(expressao[i] == '('){
            abre_parenteses++;
        }

        resultado = empilhar(pilha, expressao[i]);
        if(resultado == 0){
            printf("\n  Letra Nao Alocada!!!\n");
        }
    }
    printf("\n  abre parenteses:    [%d]", abre_parenteses);
    
    tamanho_pilha = tamanhoPilha(pilha);
    for(int i = 0; i < tamanho_pilha; i++){
        if( desempilhar(pilha) == ')'){
            fecha_parenteses++;
        }
    }
    printf("\n  fecha parenteses:   [%d]", fecha_parenteses);

    if( abre_parenteses == fecha_parenteses){
        if(abre_parenteses == 0){
            //Retorna -1 - Quando não há parenteses na expressão
            return -1;
        }
        //Retorna 1 - Quando a quantidade de parenteses é igual
        return 1;

    }else{
        //Retorna 0 - Quando a quantidade de parenteses é diferente
        return 0;
    }
}

int main(){
    char expressao[21];
    int resultado;

    printf("\n  Entre com a expressao matematica: ");
    scanf(" %[^\n]s", expressao);
    
    resultado = verificaParenteses(expressao);

    if(resultado == 1){
        printf("\n\n    Os numeros de parenteses sao Iguais!!!\n\n");

    }else if(resultado == -1){
        printf("\n\n    Nao Existe parenteses neta expressao!!!\n\n");

    }else {
        printf("\n\n    Os numeros de parenteses NAO sao Iguais!!!\n\n");
    }

    printf("\n\n");
    return 0;
}