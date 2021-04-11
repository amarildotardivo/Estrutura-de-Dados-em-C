#include <stdio.h>
#include <stdlib.h>
#include "listaEncadeadaFim.h"

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
        
        imprimirLista(listaEncadeada);
        imprimirLista(listaEncadeada_2);

        printf("\n");

        printf("    Quantidade de elementos da Lista 1: [%d] \n\n", obterQuantidadeElementos(listaEncadeada));
        printf("    Quantidade de elementos da Lista 2: [%d] \n\n", obterQuantidadeElementos(listaEncadeada_2));

        printf("\n");

        printf("    Elementos Obtidos da Lista 1:");
        vetor = obterElementos(listaEncadeada);
        tamanho = obterQuantidadeElementos(listaEncadeada);

        for(int i = 0; i < tamanho; i++){
            printf(" [%d] ", vetor[i]);
        }
        printf("\n\n");

        printf("    Elementos Obtidos da Lista 2:");
        vetor = obterElementos(listaEncadeada_2);
        tamanho = obterQuantidadeElementos(listaEncadeada_2);

        for(int i = 0; i < tamanho; i++){
            printf(" [%d] ", vetor[i]);
        }
        printf("\n\n");
        
        
        dado = excluirElemento(listaEncadeada);  
        printf("\n    O Elemento Excluido da Lista 1 foi: [%d]\n", dado);

        dado = excluirElemento(listaEncadeada_2);
        printf("\n    O Elemento Excluido da Lista 2 foi: [%d]\n", dado);

        printf("\n\n");

        resultado = verificaListaVazia(listaEncadeada);      
        if( resultado == 1 ){
            printf("    Lista Esta Vazia!\n\n");
        }else {
            printf("    Lista Nao Esta Vazia!!!\n\n");
        }

        resultado = verificaListaVazia(listaEncadeada_2);      
        if( resultado == 1 ){
            printf("    Lista Esta Vazia!\n\n");
        }else {
            printf("    Lista Nao Esta Vazia!!!\n\n");
        }

        apagarIguais(listaEncadeada, 1);
        imprimirLista(listaEncadeada);

        resultado = apagarLista(listaEncadeada);
        if( resultado == 1 ){
            printf("    Lista Apagada!!!\n\n");
        }else {
            printf("    Lista Esta Vazia!!!\n\n");
        }

        resultado = apagarLista(listaEncadeada_2);
        if( resultado == 1 ){
            printf("    Lista Apagada!!!\n\n");
        }else {
            printf("    Lista Esta Vazia!!!\n\n");
        } 

        return 0; 
    
}