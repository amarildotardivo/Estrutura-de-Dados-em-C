#include <stdio.h>
#include "pilhaEncadeadaString.h"

int main(){
    char caracter;
    char letra1[1] = "v", letra2[1] = "a";
    tipo_pilha *pilha = NULL;

    pilha = criarPilha();

    empilhar(pilha, letra1);
    empilhar(pilha, letra2);

    int tamanho = tamanhoPilha(pilha);
    
    for(int i = 0; i < tamanho; i++){
        caracter = desempilhar(pilha);
        printf("%c", caracter);
    }
    
    return 0;
}