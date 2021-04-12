#include <stdio.h>
#include <stdlib.h>
#include "listaEncadeadaFim_TAD.h"

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
        printf("    Iguais Apagados da Lista 1!!! Numero informado foi 1.");
        apagarIguais(listaEncadeada, 1);
        
        printf("\n\n");

        printf("    Imprimindo Lista 1:");
        imprimirLista(listaEncadeada);

        printf("\n\n");

        resultado = apagarLista(listaEncadeada);
        if( resultado == 1 ){
            printf("    Lista Apagada!!!\n");
        }else {
            printf("    Lista Esta Vazia!!!\n");
        }

        resultado = apagarLista(listaEncadeada_2);
        if( resultado == 1 ){
            printf("    Lista Apagada!!!\n\n");
        }else {
            printf("    Lista Esta Vazia!!!\n\n");
        } 

        return 0; 
    
}