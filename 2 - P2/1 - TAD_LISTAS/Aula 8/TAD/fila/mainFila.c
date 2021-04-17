#include <stdio.h>
#include "filaSequencial.h"

int main(){
    int resultado;
    tipo_fila *fila = NULL;

    // -------------- CRIANDO A FILA -------------------------------
    fila = criarFila();
    if(resultado == 0){
        printf("\n  Fila Não criada!!!\n");
    }
    // -------------- FIM DO CRIANDO A FILA -------------------------

    // ------------------ ENFILEIRANDO ------------------------------
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
    // ------------------ FIM DO ENFILEIRANDO ------------------------

    // ------------------ DESENFILEIRANDO ----------------------------
    resultado = desemfileirar(fila);
    if(resultado == 0){
        printf("\n  Fila Vazia!!!\n");

    }else{
        printf("\n  Dado Excluido: [%d]\n", resultado);
    }

    resultado = desemfileirar(fila);
    if(resultado == 0){
        printf("\n  Fila Vazia!!!\n");

    }else{
        printf("\n  Dado Excluido: [%d]\n", resultado);
    }
    // ------------------ FIM DO DESENFILEIRANDO ---------------------

    // ------------------ ENFILEIRANDO -------------------------------
    resultado = emfileirar(fila, 1);
    if(resultado == 0){
        printf("\n  Elemento NAO Enfileirado!!!\n");
    }
    resultado = emfileirar(fila, 2);
    if(resultado == 0){
        printf("\n  Elemento NAO Enfileirado!!!\n");
    }
    // ------------------ FIM DO ENFILEIRANDO ------------------------
    
    // ------------------ VERIFICA SE A FILA ESTÁ VAZIA --------------
    resultado = filaVazia(fila);
    if(resultado == 1){
        printf("\n  Fila Esta Vazia!!!\n");
    }else{
        printf("\n  Fila NAO Esta Vazia!!!\n");
    }
    // ----------------------------------------------------------------

    // ----------------- VERIFICA O TAMANHO DA FILA -------------------
    resultado = tamanhoFila(fila);
    printf("\n  Tamanho da Fila: [%d]\n", resultado);
    // ----------------------------------------------------------------

    // ----------------- APAGA FILA -----------------------------------
    resultado = apagaFila(fila);
    if(resultado == 1){
        printf("\n  Fila Apagada!!!\n");
    }else{
        printf("\n  Fila NAO Apagada!!!\n");
    }
    // -----------------------------------------------------------------

    // ----------------- VERIFICA O TAMANHO DA FILA --------------------
    resultado = tamanhoFila(fila);
    printf("\n  Tamanho da Fila: [%d]\n", resultado);
    // -----------------------------------------------------------------

    // ------------------ DESENFILEIRANDO ------------------------------
    resultado = desemfileirar(fila);
    if(resultado == 0){
        printf("\n  Fila Vazia!!!\n");

    }else{
        printf("\n  Dado Excluido: [%d]\n", resultado);
    }
    // ------------------------------------------------------------------
    return 0;
}