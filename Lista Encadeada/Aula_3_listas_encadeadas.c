#include <stdio.h>
#include <stdlib.h>

typedef struct no
{
    int dado;
    struct no *proximo;
} tipo_no;

int main(){
    int opcao, elemento;
    tipo_no *inicio = NULL, *novo = NULL, *atual = NULL, *auxiliar = NULL;


    while(opcao != 4){
        printf("\n -------------- MENU -------------- \n\n");
        printf(" 1) - Inclusao de elemento no inicio da lista\n");
        printf(" 2) - Exclusao de elemento do inicio da lista\n");
        printf(" 3) - Impressao dos elementos da lista\n");
        printf(" 4) - Finalizacao do programa\n\n Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao){

            case 1:
                printf("\n    Digite o elemento a ser incluido na lista: ");
                scanf("%d", &elemento);

                novo = (tipo_no*) malloc(sizeof(tipo_no));
                novo -> dado = elemento;
                novo -> proximo = inicio;
                inicio = novo;

                break;

            case 2:

                if(inicio != NULL){
                    auxiliar = inicio;
                    inicio = auxiliar -> proximo;
                    printf("\n    O numero excluido foi: [%d]\n\n", auxiliar -> dado);
                    free(auxiliar);
                }else{
                    printf("\n    Nao e possivel excluir, pois a lista esta vazia!\n\n");
                }

                break;
            
            case 3:
                atual = inicio;

                if(inicio != NULL){

                    printf("\n    Lista: ");
                    while (atual != NULL)
                    {
                        printf("[%d] ", atual -> dado);
                        atual = atual -> proximo;
                    }
                    printf("\n\n");

                }else{

                    printf("\n    Nao e possivel imprimir, pois a lista esta vazia!\n\n");
                }
                
                break;
            
            case 4:
                if(inicio == NULL){
                    printf("\n    Programa finalizado, nao existem ponteiros a serem liberados!!!\n\n");
                    return 0;
                }

                while (inicio != NULL){
                    auxiliar = inicio;
                    inicio = auxiliar -> proximo;
                    free(auxiliar);
                }
                printf("\n    Programa finalizado, ponteiros liberados!!!\n\n");
                
                return 0;

            default:
                printf("\n    Digite uma opcao valida!\n");
                break;
        }
    }
}