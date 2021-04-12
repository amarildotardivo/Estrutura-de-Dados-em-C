#include <stdlib.h>

typedef struct no
{
    int dado;
    struct no *proximo;
} tipo_no;

typedef struct listaEncadeadaInicio
{
    tipo_no* inicio;
    int quantidadeElementos;
}tipo_lista;


// A) CRIAR LISTA - VAZIA
tipo_lista* criarLista(){
    
    tipo_lista* lista = (tipo_lista*) malloc(sizeof(tipo_lista));
    lista -> inicio = NULL;
    lista -> quantidadeElementos = 0;

    return lista;
}

// B) INCLUSÃO NO INICIO DA LISTA
void incluirElemento(tipo_lista* lista, int elemento){
    tipo_no* novo;

    novo = (tipo_no*) malloc(sizeof(tipo_no));
    novo -> dado = elemento;
    novo -> proximo = lista -> inicio;
    lista -> inicio = novo;

    lista -> quantidadeElementos++;

}

// C) EXCLUSÃO NO INICIO DA LISTA
int excluirElemento(tipo_lista* lista){
    tipo_no* auxiliar;
    int dadoExcluido;

    if(lista -> inicio != NULL){
        auxiliar = lista -> inicio;
        lista -> inicio = auxiliar -> proximo;
        dadoExcluido = auxiliar -> dado;
        lista -> quantidadeElementos--;
        free(auxiliar);

        return dadoExcluido;

    }else{
        //Retorna 0 - Quando a Lista não existe
        return 0;
    }


}

// D) VERIFICAR SE A LISTA ESTÁ VAZIA
int verificaListaVazia(tipo_lista* lista){

        if(lista -> quantidadeElementos == 0){
            //Retorna 1 - Quando a lista está vazia
            return 1;

        }else {
            //Retorna 0 - Quando a lista não está vazia
            return 0;
        }
}

// E) OBTER A QUANTIDADE DE ELEMENTOS DA LISTA
int obterQuantidadeElementos(tipo_lista* lista){
    return lista -> quantidadeElementos;
}
 
// F) APAGAR LISTA
void apagarLista(tipo_lista* lista){
    tipo_no* auxiliar;

    if(lista -> inicio != NULL){
     
        while (lista -> inicio != NULL){
            auxiliar = lista -> inicio;
            lista -> inicio = auxiliar -> proximo;
            lista -> quantidadeElementos--;
            free(auxiliar);
        }
    }

}

// G) OBTER ELEMENTOS DA LISTA
int* obterElementos(tipo_lista* lista){
    tipo_no *atual = lista -> inicio;
    int posicao = 0, *vetorElementos;

    vetorElementos = (int*) malloc(sizeof(lista -> quantidadeElementos));

        while( atual != NULL){
            vetorElementos[posicao] = atual -> dado;

            posicao++;
            atual = atual -> proximo;
        }

        return vetorElementos;
}

// H) CONCATENAR LISTAS
void concatenarListas(tipo_lista* lista, tipo_lista* lista_2){
    tipo_no *atual_2 = lista_2 -> inicio;

    while( atual_2 != NULL ){
        incluirElemento(lista, atual_2 -> dado);
        
        atual_2 = atual_2 -> proximo;
    }

    apagarLista(lista_2);
}
