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
        printf("\nEscolha uma opcao:\n\n");
        printf("1) - Inclusao de elemento no inicio da lista\n");
        printf("2) - Exclusao de elemento do inicio da lista\n");
        printf("3) - Impressao dos elementos da lista\n");
        printf("4) - Finalizacao do programa\n");
        scanf("%d", &opcao);

        switch (opcao){

            case 1:
                printf("Digite o elemento a ser incluido na lista: ");
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
                    free(auxiliar);
                }else{
                    printf("Nao e possivel excluir, pois a lista esta vazia!");
                }

                break;
            
            case 3:
                atual = inicio;

                while (atual != NULL)
                {
                    printf("%d ", atual -> dado);
                    atual = atual -> proximo;
                }
                
                break;
            
            case 4:
                
                while (inicio != NULL){
                    auxiliar = inicio;
                    inicio = auxiliar -> proximo;
                    free(auxiliar);
                }
                printf("Opcao 4 selecionada, programa finalizado!!!");
                
                return 0;

            default:
                printf("\nDigite uma opcao valida!\n");
                break;
        }
    }
}