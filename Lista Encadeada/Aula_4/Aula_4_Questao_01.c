#include <stdio.h>
#include <stdlib.h>

typedef struct no{
    int dado;
    struct no *proximo;
}tipo_no;

tipo_no* incluirElementoInicio(tipo_no* inicio){
    int elemento;
    tipo_no *novo;

    printf("\n    Digite o elemento a ser incluido no inicio da lista: ");
    scanf("%d", elemento);

    novo = (tipo_no*) malloc(sizeof(tipo_no));
    novo -> dado = elemento;
    novo -> proximo = inicio;
    inicio = novo;

    return inicio;
}

void imprimirLista(inicio){

    while( inicio != NULL){
        printf("");
    }
}

int main(){
    int opcao;
    tipo_no *inicio = NULL;

    while(opcao != 4){
        printf("\n -------------- MENU -------------- \n\n");

        printf(" 1) - Inclusao de elemento no inicio da lista\n");
        printf(" 2) - Inclusao de elemento no fim da lista\n");

        printf(" 3) - Exclusao de elemento do inicio da lista\n");
        printf(" 4) - Exclusao de elemento do fim da lista\n");

        printf(" 5) - Impressao dos elementos da lista\n");

        printf(" 6) - Limpar a lista - Excluir todos os elementos\n");

        printf(" 7) - Finalizacao do programa\n");

        printf("\n Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch(opcao){
            case1:
                incluirElementoInicio(inicio);
                break;

            case 5:
                imprimirLista(inicio);
                break;
            default:
                printf("Escolha uma opcao válida!");
                break;
        }
    }
}