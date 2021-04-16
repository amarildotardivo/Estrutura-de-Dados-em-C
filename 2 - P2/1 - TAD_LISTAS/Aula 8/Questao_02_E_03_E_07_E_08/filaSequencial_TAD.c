#include <stdlib.h>
#define tamanho 21

typedef struct filaSequencial{
    int dados[tamanho];
    int inicio;
    int fim;
    int quantidadeElementos;
}tipo_fila;

// A) CRIAR FILA VAZIA
tipo_fila* criarFila(){
    tipo_fila *fila = (tipo_fila*) malloc(sizeof(tipo_fila));

    if(fila == NULL){
        //Retorna 0 - Informando que a alocação não foi realizada com sucesso
        return 0;
    }

    fila -> inicio = 0;
    fila -> fim = 0;
    fila -> quantidadeElementos = 0;

    return fila;
}

// B) - Incluir elemento no final da fila
int emfileirar(tipo_fila* fila, int elemento){
    
    if(fila != NULL){
        
    }else
}

// C) - Exluir elemento no inicio da fila
int desemfileirar(tipo_fila* fila){
    tipo_no *auxiliar;
    int dadoExcluido;

    if(fila->inicio != NULL){
        auxiliar = fila->inicio;
        fila->inicio = auxiliar -> proximo;
        fila->quantidadeElementos--;
        dadoExcluido = auxiliar->dado;
        
        free(auxiliar);

        return dadoExcluido;

    }else{
        // Retorna 0 - Quando a fila Está vazia
        return 0;
    }
}

// D) VERIFICAR SE A FILA ESTÁ VAZIA
int filaVazia(tipo_fila *fila){
    if(fila->quantidadeElementos == 0){
        //Retorna 1 - quando a fila estiver vazia
        return 1;
    }else{
        //Retorna 0 - Quando a fila nao estiver vazia
        return 0;
    }
}

// E) VERIFICAR TAMANHO DA FILA
int tamanhoFila(tipo_fila *fila){
    return fila->quantidadeElementos;
}

// 6) - Limpar a lista
int apagaFila(tipo_fila* fila){
    tipo_no *auxiliar;

    if(fila->inicio != NULL){
        while (fila->inicio != NULL){
            auxiliar = fila->inicio;
            fila->inicio = auxiliar -> proximo;
            free(auxiliar);
        }
        //Retorna 1 - Quando a fila foi apagada com sucesso
        return 1;

    }else{
        //Retorna 0 - Quando não existe fila para apagar
        return 0;
    }
}