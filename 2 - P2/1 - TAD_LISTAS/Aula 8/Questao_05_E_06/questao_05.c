#include <stdio.h>
#include <string.h>
#include "pilhaEncadeadaString.h"

void inverterFrase(tipo_pilha *pilha, char frase[21]){
    int resultado;
    char letra;

    pilha = criarPilha();
    if(pilha == NULL){
        printf("\n  Pilha nao alocada!!!\n");
    }

    for( int i = 0; i < strlen(frase); i++){

        resultado = empilhar(pilha, frase[i]);
        if(resultado == 0){
            printf("\n  Letra Nao Alocada!!!\n");
        }
    }

    int tamanho = tamanhoPilha(pilha);
    
    printf("\n\n  Frase Invertida: ");

    for(int i = 0; i < tamanho; i++){
        letra = desempilhar(pilha);
        printf("%c", letra);
    }
    
    printf("\n\n"); 
}

int main(){
    char frase[21];
    tipo_pilha *pilha = NULL;

    printf("\n  Entre com a frase a ser invertida: ");
    scanf(" %[^\n]s", frase);
    
    inverterFrase(pilha, frase);

    return 0;
}