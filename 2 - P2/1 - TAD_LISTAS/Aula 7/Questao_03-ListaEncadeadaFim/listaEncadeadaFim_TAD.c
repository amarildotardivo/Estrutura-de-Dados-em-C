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

// B) INCLUSÃO NO FIM DA LISTA
void incluirElemento(tipo_lista* lista, int elemento){
    tipo_no* novo, *atual = lista->inicio;

    novo = (tipo_no*) malloc(sizeof(tipo_no));
    novo -> dado = elemento;

    if( lista -> inicio != NULL ){
        
        //Procura o ultimo elemento da lista
        while( atual ->proximo != NULL ){

            atual = atual->proximo;
        }

        //Incluindo elemento no fim da lista
        atual->proximo = novo;
        novo->proximo = NULL;

        lista->quantidadeElementos++;

    }else {
        //Inclui o primeiro elemento da lista
        novo -> proximo = lista -> inicio;
        lista -> inicio = novo;

        lista -> quantidadeElementos++;
    }


}

// C) EXCLUSÃO NO FIM DA LISTA
int excluirElemento(tipo_lista* lista){
    tipo_no* atual = lista->inicio, *anterior = NULL;
    int dadoExcluido;

    if(lista -> inicio != NULL){
        //Verifica se a lista possui apenas 1 elemento para excluir
        if( lista->quantidadeElementos > 1){

            while( atual != NULL){

                if( atual->proximo == NULL){
                    
                    anterior->proximo = NULL;
                    dadoExcluido = atual -> dado;
                    lista -> quantidadeElementos--;

                    free(atual);
                    return dadoExcluido;                
                }

                anterior = atual;
                atual = atual->proximo;
            }

        }else {

            lista -> inicio = atual -> proximo;
            dadoExcluido = atual -> dado;
            lista -> quantidadeElementos--;

            free(atual);
            return dadoExcluido; 
        }


    }else{
        //Retorna 0 - Quando a Lista está vazia
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
int apagarLista(tipo_lista* lista){
    tipo_no* auxiliar;

    if(lista -> inicio != NULL){
     
        while (lista -> inicio != NULL){
            auxiliar = lista -> inicio;
            lista -> inicio = auxiliar -> proximo;
            lista -> quantidadeElementos--;
            free(auxiliar);
        }
        //Retorna 1 - Quando a lista foi apagada
        return 1;

    }else {
        //Retorna 0 - Quando a lista está vazia
        return 0;
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

// H) APAGAR ELEMENTOS IGUAIS
void apagarIguais(tipo_lista* lista, int elemento){
    tipo_no *atual = lista -> inicio, *anterior = NULL, *auxiliar = NULL;

    while( atual != NULL){
        
        if( elemento == atual -> dado ){

            if( anterior == NULL ){
                lista -> inicio = atual -> proximo;
                lista -> quantidadeElementos--;
                auxiliar = atual;
                
                anterior = atual;
                atual = atual -> proximo;
                
                free(auxiliar);

            }else {
                anterior -> proximo = atual -> proximo;
                lista -> quantidadeElementos--;
                auxiliar = atual;

                atual = atual -> proximo;

                free(auxiliar);
            }
        }else{

            anterior = atual;
            atual = atual -> proximo;
        }

    }
}
