#include <stdio.h>
#include <stdlib.h>

typedef struct no{
    int dado;
    struct no *proximo;
}tipo_no;

// 1) - Incluir elemento no inicio da lista
tipo_no* incluirElementoInicio(tipo_no* inicio){
    int elemento;
    tipo_no *novo;

    printf("\n    Digite o elemento a ser incluido no inicio da lista: ");
    scanf("%d", &elemento);

    novo = (tipo_no*) malloc(sizeof(tipo_no));
    novo -> dado = elemento;
    novo -> proximo = inicio;
    inicio = novo;

    return inicio;
}

// 2) - Incluir elemento no final da lista
tipo_no* incluirElementoFinal(tipo_no* inicio){
    int elemento;
    tipo_no *atual, *novo;
    atual = inicio;

    printf("\n    Digite o elemento a ser incluido no fim da lista: ");
    scanf("%d", &elemento);

    novo = (tipo_no*) malloc(sizeof(tipo_no));
    novo -> dado = elemento;
    novo -> proximo = NULL;

    if(inicio != NULL){
        while(atual -> proximo != NULL){
            atual = atual -> proximo;
        }
        atual -> proximo = novo;
    }else{
        // Setando novo elemento no inicio da lista caso ela esteja vazia
        inicio = novo;
    }

    return inicio;
}

// 3) - Exluir elemento no inicio da lista
tipo_no* excluirElementoInicio(tipo_no* inicio){
    tipo_no *auxiliar;

    if(inicio != NULL){
        auxiliar = inicio;
        inicio = auxiliar -> proximo;
        free(auxiliar);
    }else{
        printf("\n    Nao e possivel excluir o elemento, pois a lista nao existe!\n\n");
    }

    return inicio;
}

// 4) - Excluir elemento no final da lista
tipo_no* excluirElementoFinal(tipo_no* inicio){

}

// 5) - Imprimir lista
void imprimirLista(tipo_no* inicio){
    tipo_no *atual;
    atual = inicio;

    if(atual != NULL){
        printf("\n    Lista: ");
        while( atual != NULL){
            printf("[%d] ", atual -> dado);
            atual = atual -> proximo;
        }
        printf("\n\n");

    }else{
        printf("\n    Nao e possivel imprimir, pois a lista nao existe!\n\n");
    }
}

// 6) - Limpar a lista
tipo_no* limparLista(tipo_no* inicio){
    tipo_no *auxiliar;

    if(inicio != NULL){
        while (inicio != NULL){
            auxiliar = inicio;
            inicio = auxiliar -> proximo;
            free(auxiliar);
        }
        printf("\n    Lista Limpa, ponteiros liberados!!!\n\n");

    }else{
        printf("\n   Nao existe lista para ser limpa!!!\n\n");
    }

    return inicio;
}

// 7) - Finalizar programa
int finalizarPrograma(tipo_no* inicio){
    tipo_no *auxiliar;
    
    if(inicio != NULL){
        while (inicio != NULL){
            auxiliar = inicio;
            inicio = auxiliar -> proximo;
            free(auxiliar);
        }
        return 1;

    }else{
        return 0;
    }
    
}
int main(){
    int opcao, fim;
    tipo_no *inicio = NULL;

    while(opcao != 7){
        printf("\n -------------- MENU -------------- \n\n");

        printf(" 1) - Inclusao de elemento no inicio da lista\n");
        printf(" 2) - Inclusao de elemento no fim da lista\n\n");

        printf(" 3) - Exclusao de elemento no inicio da lista\n");
        printf(" 4) - Exclusao de elemento no fim da lista\n\n");

        printf(" 5) - Impressao dos elementos da lista\n\n");

        printf(" 6) - Limpar a lista - Excluir todos os elementos\n\n");

        printf(" 7) - Finalizar programa\n\n");

        printf("\n Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch(opcao){
            case 1:
                inicio = incluirElementoInicio(inicio);
                break;

            case 2:
                inicio = incluirElementoFinal(inicio);
                break;

            case 3:
                inicio = excluirElementoInicio(inicio);
                break;

            case 4:
                inicio = excluirElementoFinal(inicio);
                break;

            case 5:
                imprimirLista(inicio);
                break;

            case 6:
                inicio = limparLista(inicio);
                break;

            case 7:
                fim = finalizarPrograma(inicio);

                if(fim == 1){
                    printf("\n    Programa finalizado, ponteiros liberados!!!\n\n");
                }else{
                    printf("\n    Programa finalizado, nao existem ponteiros a serem liberados!!!\n\n");
                }

                return 0;

            default:
                printf("\n    Digite uma opcao valida!\n");
                break;
        }
    }
}