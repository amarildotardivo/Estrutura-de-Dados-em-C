#include <stdio.h>
#include "TAD\pilha\pilhaEncadeada.h"

int verificarPilhasIguais(tipo_pilha *pilha1, tipo_pilha *pilha2){
    int dado1, dado2;

    if(tamanhoPilha(pilha1) == tamanhoPilha(pilha2)){
        
        while(dado1 != 0){
            dado1 = desempilhar(pilha1);
            dado2 = desempilhar(pilha2);

            if(dado1 != dado2){
                //Retorna 0 - Quando as pilhas são diferentes
                return 0;
            }
        }

        //Retorna 1 - Quando as pilhas são iguais
        return 1;

    }else{
        //Retorna 0 - Quando as pilhas são diferentes
        return 0;
    }
}

int main(){
    int resultado;
    tipo_pilha *pilha1, *pilha2;

    pilha1 = criarPilha();
    pilha2 = criarPilha();

    empilhar(pilha1, 1);
    empilhar(pilha1, 2);
    empilhar(pilha1, 3);
    empilhar(pilha1, 4);

    empilhar(pilha2, 1);
    empilhar(pilha2, 2);
    empilhar(pilha2, 3);
    empilhar(pilha2, 4);

    resultado = verificarPilhasIguais(pilha1, pilha2);

    if(resultado == 1){
        printf("\n  As Pilhas Sao Iguais!\n\n");

    }else{
        printf("\n  As Pilhas Sao Diferentes!\n\n");
    }
    
    return 0;
}