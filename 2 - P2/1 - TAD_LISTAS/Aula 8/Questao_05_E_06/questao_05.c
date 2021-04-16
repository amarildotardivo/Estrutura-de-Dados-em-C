#include <stdio.h>
#include "pilhaEncadeadaString.h"

int main(){
    char letra;
    int resultado;
    tipo_pilha *pilha = NULL;

    pilha = criarPilha();

    for(int i = 0; i < 4; i++){
        printf("Entre com a %d Letra: ", i + 1);
        scanf(" %c", letra);
        
        resultado = empilhar(pilha, letra);
        
        if(resultado == 0){
            printf("Letra Nao Empilhada!!!");
            
        }else{
            printf("Letra Empilhada com Sucesso!!!");
        }
    }

    int tamanho = tamanhoPilha(pilha);
    
    for(int i = 0; i < tamanho; i++){
        letra = desempilhar(pilha);
        printf("%c", letra);
    }
    
    return 0;
}