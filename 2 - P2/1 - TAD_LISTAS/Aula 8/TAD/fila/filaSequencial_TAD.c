#include <stdlib.h>
#define tamanho_vetor 3

typedef struct filaSequencial{
    int dados[tamanho_vetor];
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
    
    if(fila->fim != tamanho_vetor){
        
        if(fila->fim + 1 != fila->inicio){

            fila->dados[fila->fim] = elemento;
            
            fila->quantidadeElementos++;
            fila->fim++;

            return elemento;
        }

    }else if(fila->inicio > 1){
        fila->fim = 0;

        fila->dados[fila->fim] = elemento;
            
        fila->quantidadeElementos++;
        fila->fim++;

        return elemento;
        
    }else{
        //Retorna 0 - Informando que a alocação não foi realizada com sucesso
        return 0;
    }

}

// C) - Exluir elemento no inicio da fila
int desemfileirar(tipo_fila* fila){
    int dadoExcluido;

    if(fila->quantidadeElementos != 0){
        
        dadoExcluido = fila->dados[fila->inicio];
        //fila->dados[inicial] = NULL;
        fila->inicio++;

        if(fila->inicio == tamanho_vetor){
            fila->inicio = 0;
        }

        fila->quantidadeElementos--;

        if(fila->fim == tamanho_vetor){
            fila->fim = 0;
        }
        
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
    
    if(fila != NULL){

        fila->inicio = 0;
        fila->fim = 0;
        fila->quantidadeElementos = 0;

        //Retorna 1 - Quando a fila foi apagada com sucesso
        return 1;

    }else{
        //Retorna 0 - Quando não existe fila para apagar
        return 0;
    }
}