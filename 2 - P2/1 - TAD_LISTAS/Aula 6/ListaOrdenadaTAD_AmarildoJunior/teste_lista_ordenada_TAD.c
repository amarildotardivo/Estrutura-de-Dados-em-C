#include<stdio.h>
#include"lista_ordenada_TAD.h"

void imprimirLista(tipo_lista* listaOrdenada)
{
    int *elementosLista, posicao;
    elementosLista = obterElementosLista(listaOrdenada);
    for (posicao = 0; posicao < quantidadeElementosLista(listaOrdenada); posicao++)
    {
        printf("%d ", elementosLista[posicao]);
    }
    printf("\n");
}

int main()
{
    tipo_lista* listaOrdenada = NULL;

    listaOrdenada = criarListaVazia();
    inserirElementoOrdenado(listaOrdenada, 20);
    inserirElementoOrdenado(listaOrdenada, 10);
    inserirElementoOrdenado(listaOrdenada, 15);
    inserirElementoOrdenado(listaOrdenada, 1);
    inserirElementoOrdenado(listaOrdenada, 5);
    imprimirLista(listaOrdenada);

    excluirElementoOrdenado(listaOrdenada, 5);
    imprimirLista(listaOrdenada);

    excluirElementoOrdenado(listaOrdenada, 1);
    imprimirLista(listaOrdenada);

    excluirElementoOrdenado(listaOrdenada, 20);
    imprimirLista(listaOrdenada);

    excluirElementoOrdenado(listaOrdenada, 15);

    excluirElementoOrdenado(listaOrdenada, 10);
    imprimirLista(listaOrdenada);

    inserirElementoOrdenado(listaOrdenada, 20);
    inserirElementoOrdenado(listaOrdenada, 10);
    inserirElementoOrdenado(listaOrdenada, 15);
    inserirElementoOrdenado(listaOrdenada, 1);
    inserirElementoOrdenado(listaOrdenada, 5);
    imprimirLista(listaOrdenada);
    printf("%d\n", quantidadeElementosLista(listaOrdenada));
    excluirElementoOrdenado(listaOrdenada, 10);
    printf("%d\n", quantidadeElementosLista(listaOrdenada));
    listaOrdenada = apagarLista(listaOrdenada);
    if (!listaOrdenada)
    {
        printf("Lista apagada!");
    }
    else
    {
        printf("A lista ainda existe!");
    }
    return 0;
}
