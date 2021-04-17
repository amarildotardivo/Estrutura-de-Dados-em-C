#include <stdio.h>
#include "TAD\fila\filaEncadeada.h"

#define elementos_fila_Original 10

void separaElementos(tipo_fila *filaOriginal, tipo_fila *filaImpares, tipo_fila *filaPares){
    int tamanho_fila, elemento, resultado;

    tamanho_fila = tamanhoFila(filaOriginal);

    for(int i = 0; i < tamanho_fila; i++){
        elemento = desemfileirar(filaOriginal);

        if(elemento % 2 == 0){
            resultado = emfileirar(filaPares, elemento);

        }else{
            resultado = emfileirar(filaImpares, elemento);

        }
    }   


}

int main(){
    int tamanho_fila, elemento;
    tipo_fila *filaOriginal = NULL, *filaImpares = NULL, *filaPares = NULL;
    
    filaOriginal = criarFila();
    filaImpares = criarFila();
    filaPares = criarFila();

    printf("\n  Elementos da Fila Original: ");
    for(int i = 0; i < elementos_fila_Original; i++){
        emfileirar(filaOriginal, i + 1);
        printf(" [%d] ", i + 1);
    }

    separaElementos(filaOriginal, filaImpares, filaPares);

    printf("\n\n  Elementos da Fila Pares:    ");
    
    tamanho_fila = tamanhoFila(filaPares);
    for(int i = 0; i < tamanho_fila; i++){
        elemento = desemfileirar(filaPares);
        printf(" [%d] ", elemento);
    }

    printf("\n\n  Elementos da Fila Impares:  ");
    
    tamanho_fila = tamanhoFila(filaImpares);
    for(int i = 0; i < tamanho_fila; i++){
        elemento = desemfileirar(filaImpares);
        printf(" [%d] ", elemento);
    }

    printf("\n\n");
    return 0;
}