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
    tipo_lista* listaOrdenada_2 = NULL;

    listaOrdenada = criarListaVazia();
    inserirElementoOrdenado(listaOrdenada, 20);
    inserirElementoOrdenado(listaOrdenada, 10);
    inserirElementoOrdenado(listaOrdenada, 15);
    inserirElementoOrdenado(listaOrdenada, 1);
    inserirElementoOrdenado(listaOrdenada, 5);
    imprimirLista(listaOrdenada);

    listaOrdenada_2 = criarListaVazia();
    inserirElementoOrdenado(listaOrdenada_2, 20);
    inserirElementoOrdenado(listaOrdenada_2, 10);
    inserirElementoOrdenado(listaOrdenada_2, 15);
    inserirElementoOrdenado(listaOrdenada_2, 1);
    inserirElementoOrdenado(listaOrdenada_2, 5);
    imprimirLista(listaOrdenada_2);


// ---------------- QUESTÃO 01 --------------------------------
    
    printf("\nMedia da Lista: %.2f \n\n", calcularMedia(listaOrdenada) );
    printf("Profundidade da Lista: %d \n\n", verificaProfundidade(listaOrdenada, 15) );
    
    int resultado = compararListas(listaOrdenada, listaOrdenada_2);

    if( resultado == 0 ){
        printf("Lista nao Existe! \n\n");

    }else if ( resultado == 1 ){
        printf("Lista sao Iguais! \n\n");

    }else if( resultado == -1 ){
        printf("Algum dado de alguma Lista e diferente! \n\n");

    }else if( resultado == -2 ){
        printf("O Tamanho das Listas é Diferente! \n\n");
    }

// ---------------- FIM DA QUESTÃO 01 --------------------------------

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
