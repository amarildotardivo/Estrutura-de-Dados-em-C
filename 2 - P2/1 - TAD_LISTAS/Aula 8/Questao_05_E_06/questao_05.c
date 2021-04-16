#include <stdio.h>
#include <string.h>
#include "pilhaEncadeadaString.h"

int main(){
    char frase[21], letra;
    int resultado;
    tipo_pilha *pilha = NULL;

    pilha = criarPilha();
    if(pilha == NULL){
        printf("\n  Pilha nao alocada!!!\n");
    }

    printf("\n  Entre com a frase a ser invertida: ");
    scanf(" %[^\n]s", frase);
    
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

    return 0;
}