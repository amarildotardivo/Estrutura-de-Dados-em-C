#include <stdio.h>
#include "filaEncadeada.h"

int main(){
    int resultado;
    tipo_fila *fila = NULL;

    fila = criarFila();
    if(resultado == 0){
        printf("\n  Fila Não criada!!!\n");
    }

    resultado = emfileirar(fila, 1);
    if(resultado == 0){
        printf("\n  Elemento NAO Enfileirado!!!\n");
    }
    resultado = emfileirar(fila, 2);
    if(resultado == 0){
        printf("\n  Elemento NAO Enfileirado!!!\n");
    }
    resultado = emfileirar(fila, 3);
    if(resultado == 0){
        printf("\n  Elemento NAO Enfileirado!!!\n");
    }

    resultado = desemfileirar(fila);
    if(resultado == 0){
        printf("\n  Fila Vazia!!!\n");

    }else{
        printf("\n  Dado Excluido: [%d]\n", resultado);
    }

    resultado = filaVazia(fila);
    if(resultado == 1){
        printf("\n  Fila Esta Vazia!!!\n");
    }else{
        printf("\n  Fila NAO Esta Vazia!!!\n");
    }

    resultado = tamanhoFila(fila);
    printf("\n  Tamanho da Fila: [%d]\n", resultado);

    resultado = apagaFila(fila);
    if(resultado == 1){
        printf("\n  Fila Apagada!!!\n");
    }else{
        printf("\n  Fila NAO Apagada!!!\n");
    }

    return 0;
}