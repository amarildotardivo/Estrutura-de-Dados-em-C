#include <stdio.h>
#include "pilhaEncadeada.h"

verificarPilhasIguais(tipo_pilha *pilha1, tipo_pilha *pilha2){
    
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
    empilhar(pilha2, 7);
    empilhar(pilha2, 4);

    resultado = verificarPilhasIguais(pilha1, pilha2);
    
    return 0;
}