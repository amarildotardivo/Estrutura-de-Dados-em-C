#include <stdio.h>
#include <stdlib.h>
#include "listaEncadeadaInicio_TAD.h"

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
        vetor = obterElementos(listaEncadeada);
        tamanho = obterQuantidadeElementos(listaEncadeada);

        for(int i = 0; i < tamanho; i++){
            printf(" [%d] ", vetor[i]);
        }
        printf("\n");

        printf("    Elementos Obtidos da Lista 2:");
        vetor = obterElementos(listaEncadeada_2);
        tamanho = obterQuantidadeElementos(listaEncadeada_2);

        for(int i = 0; i < tamanho; i++){
            printf(" [%d] ", vetor[i]);
        }

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