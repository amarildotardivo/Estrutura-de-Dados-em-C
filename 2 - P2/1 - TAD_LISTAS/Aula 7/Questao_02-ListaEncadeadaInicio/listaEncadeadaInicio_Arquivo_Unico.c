#include <stdio.h>
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

// EXTRA - IMPRESSÃO DOS ELEMENTOS DA LISTA
void imprimirLista(tipo_lista* lista){
    int *vetor, tamanho;

        vetor = obterElementos(lista);
        tamanho = obterQuantidadeElementos(lista);

        for(int i = 0; i < tamanho; i++){
            printf(" [%d] ", vetor[i]);
        }
}


int main(){
    int *vetor, tamanho, dado, resultado;
    tipo_lista *listaEncadeada = NULL, *listaEncadeada_2 = NULL;

        listaEncadeada = criarLista();
        listaEncadeada_2 = criarLista();

        incluirElemento(listaEncadeada, 1);
        incluirElemento(listaEncadeada, 2);
        incluirElemento(listaEncadeada, 1);
        incluirElemento(listaEncadeada, 3);
        
        incluirElemento(listaEncadeada_2, 5);
        incluirElemento(listaEncadeada_2, 6);
        incluirElemento(listaEncadeada_2, 7);
        incluirElemento(listaEncadeada_2, 8);
        
        printf("\n");
        printf("    Imprimindo Lista 1:");
        imprimirLista(listaEncadeada);
        
        printf("\n");

        printf("    Imprimindo Lista 2:");
        imprimirLista(listaEncadeada_2);
        
        printf("\n\n");

        printf("    Quantidade de elementos da Lista 1: [%d] \n", obterQuantidadeElementos(listaEncadeada));
        printf("    Quantidade de elementos da Lista 2: [%d] \n", obterQuantidadeElementos(listaEncadeada_2));

        printf("\n\n");

        printf("    Elementos Obtidos da Lista 1:");
        imprimirLista(listaEncadeada);

        printf("\n");

        printf("    Elementos Obtidos da Lista 2:");
        imprimirLista(listaEncadeada_2);

        printf("\n\n");
        
        dado = excluirElemento(listaEncadeada);  
        printf("    O Elemento Excluido da Lista 1 foi: [%d]\n", dado);

        dado = excluirElemento(listaEncadeada_2);
        printf("    O Elemento Excluido da Lista 2 foi: [%d]\n", dado);

        printf("\n");

        resultado = verificaListaVazia(listaEncadeada);      
        if( resultado == 1 ){
            printf("    Lista Esta Vazia!\n");
        }else {
            printf("    Lista Nao Esta Vazia!!!\n");
        }

        resultado = verificaListaVazia(listaEncadeada_2);      
        if( resultado == 1 ){
            printf("    Lista Esta Vazia!\n\n");
        }else {
            printf("    Lista Nao Esta Vazia!!!\n\n");
        }

        printf("\n");
        printf("    Concatenando 2 listas!");
        concatenarListas(listaEncadeada, listaEncadeada_2);
        
        printf("\n\n");

        printf("    Imprimindo Lista Concatenada:");
        imprimirLista(listaEncadeada);

        printf("\n\n");

        printf("    Lista 1 Apagada!");
        apagarLista(listaEncadeada);

        printf("\n");
        printf("    Lista 2 Apagada!");
        apagarLista(listaEncadeada_2);

        return 0; 
    
}