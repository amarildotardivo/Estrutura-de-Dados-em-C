#include<stdlib.h>

typedef struct no
{
    int dado;
    struct no *proximo;
} tipo_no;

typedef struct reg_lista
{
    tipo_no *inicio;
    int quantidadeElementos;
} tipo_lista;

tipo_lista* criarListaVazia()
{
    tipo_lista* lista = (tipo_lista*) malloc(sizeof(tipo_lista));
    lista->inicio = NULL;
    lista->quantidadeElementos = 0;
    return lista;
}

int listaVazia(tipo_lista* lista)
{
    if (lista->quantidadeElementos == 0)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}

int quantidadeElementosLista(tipo_lista* lista)
{
    return lista->quantidadeElementos;
}

tipo_lista* apagarLista(tipo_lista* lista)
{
    tipo_no *auxiliar;

    while (!listaVazia(lista))
    {
        auxiliar = lista->inicio;
        lista->inicio = lista->inicio->proximo;
        free(auxiliar);
    }
    free(lista);
    return NULL;
}

void inserirElementoOrdenado(tipo_lista* lista, int dado)
{
    tipo_no *novo, *atual = lista->inicio, *anterior = NULL;

    novo = (tipo_no*) malloc(sizeof(tipo_no));
    novo->dado = dado;

    if (lista->inicio == NULL)
    {
        novo->proximo = NULL;
        lista->inicio = novo;
    }
    else
    {
        while ((atual != NULL) && (atual->dado < dado))
        {
            anterior = atual;
            atual = atual->proximo;
        }
        if (anterior == NULL)
        {
            novo->proximo = lista->inicio;
            lista->inicio = novo;
        }
        else
        {
            anterior->proximo = novo;
            novo->proximo = atual;
        }
    }
    lista->quantidadeElementos++;
}

int* obterElementosLista(tipo_lista* lista)
{
    tipo_no *atual = lista->inicio;
    int *elementosImpressos, posicao;

    elementosImpressos = (int*) malloc(lista->quantidadeElementos * sizeof(int));

    posicao = 0;
    while (atual != NULL)
    {
        elementosImpressos[posicao] = atual->dado;
        atual = atual->proximo;
        posicao++;
    }
    return elementosImpressos;
}

int excluirElementoOrdenado(tipo_lista* lista, int dado)
{
    tipo_no *auxiliar, *anterior = NULL, *atual = lista->inicio;

    while ((atual != NULL) && (atual->dado != dado))
    {
        anterior = atual;
        atual = atual->proximo;
    }
    if (atual->dado == dado)
    {
        if (anterior == NULL)
        {
            lista->inicio = atual->proximo;
        }
        else
        {
            anterior->proximo = atual->proximo;
        }
        auxiliar = atual;
        free(auxiliar);
        lista->quantidadeElementos--;
        return 1;
    }
    else
    {
        return 0;
    }
}

// ---------------- QUESTÃO 01 --------------------------------
// 1 - CALCULAR MEDIA ARITIMÉTICA DA LISTA
int calcularMedia( tipo_lista* lista ){

    tipo_no *atual = lista -> inicio;
    int elementos = 0, media; 

    if( lista -> inicio != NULL){

        while( atual != NULL){
            elementos += atual -> dado;

            atual = atual -> proximo;
        }

        media = elementos / lista -> quantidadeElementos;

        return media;

    }else {
        // Retorna 0 - Quando lista não existe
        return 0;
    }
}

// 2 - VERIFICA PROFUNDIDADE DE UMA CELULA DA LISTA
int verificaProfundidade( tipo_lista* lista, int elemento ){
    tipo_no *atual = lista ->inicio;
    int profundidade;

    if ( lista ->inicio != NULL ){

        while( atual != NULL ){

            if ( atual -> dado == elemento){
                profundidade++;
                return profundidade;
            }

            profundidade++;
            atual = atual -> proximo;
        }

    }else {
        // Retorna 0 - Quando lista não existe
        return 0;
    }
}

// 3 - COMPARAR 2 LISTAS ÁRA VERIFICAR SE SÃO IGUAIS
int compararListas( tipo_lista* lista_1, tipo_lista* lista_2 ){
    tipo_no *atual_1 = lista_1 -> inicio, *atual_2 = lista_2 -> inicio;

    if ( ( lista_1 -> inicio != NULL ) && ( lista_2 -> inicio != NULL ) ){
    
        if(lista_1 -> quantidadeElementos == lista_2 -> quantidadeElementos){

            while( ( atual_1 != NULL ) && ( atual_2 != NULL ) ){

                if( atual_1 -> dado != atual_2 -> dado){
                    //Retorna -1 - Quando o dado das listas forem diferentes
                    return -1;
                }

                atual_1 = atual_1 -> proximo;
                atual_2 = atual_2 -> proximo;
            }
            //Retorna 1 - Quando as listas são iguais
            return 1;

        }else {
            //Retorna 2 - Quando os tamanhos das listas são diferentes
            return -2;
        }
    }else {
        // Retorna 0 - Quando lista não existe
        return 0;
    }

}

// ---------------- FIM DA QUESTÃO 01 --------------------------------
