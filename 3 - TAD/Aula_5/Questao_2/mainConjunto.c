#include "conjunto.h"

int main(){
    int opcao = 0, id_conjunto, elemento, resultado;
    tipo_conjunto *inicio = NULL;

    while(opcao != 15){
        printf("\n -------------- MENU -------------- \n\n");
        printf(" 1) - Cria um Conjunto Vazio\n\n");
        
        printf(" 2) - Inserir um Elemento no Conjunto vazio\n\n");

        printf(" 3) - Remove um Elemento do Conjunto vazio\n\n");
        
        printf("\n Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao){
            case 1:
                inicio = criarConjuntoVazio(inicio);
                break;

            case 2:
                printf("\n    Em qual conjunto vc deseja inserir o elemento: ");
                scanf("%d", &id_conjunto);

                printf("\n    Qual elemento vc deseja inserir no conjunto: ");
                scanf("%d", &elemento);

                resultado = inserirElemento(inicio, id_conjunto, elemento);

                if(resultado == 1){
                    printf("\n    Elemento nao encontrado no Conjunto!");

                }else if(resultado == 2){
                    printf("\n    Conjunto nao encontrado!");

                }else if(resultado == 3){
                    printf("\n    Nao e possivel inserir o elemento, pois e menor que 0 e maior que 99!");
                
                }else if(resultado == 4){
                    printf("\n    Nao e possivel inserir o elemento, nao existe nenhum conjunto para inseri-lo");
                
                }else{
                    printf("\n    Elemento inserido com sucesso!\n\n");
                }

                break;

            case 3:
                printf("\n    De qual conjunto vc deseja remover o elemento: ");
                scanf("%d", &id_conjunto);

                printf("\n    Qual elemento vc deseja remover do conjunto: ");
                scanf("%d", &elemento);

                resultado = removeElemento(inicio, id_conjunto, elemento);

                if(resultado == 1){
                    printf("\n    Elemento nao encontrado no Conjunto!");
                    
                }else if(resultado == 2){
                    printf("\n    Conjunto nao encontrado!");

                }else if(resultado == 3){
                    printf("\n    Nao e possivel remover o elemento, pois e menor que 0 e maior que 99!");
                
                }else if(resultado == 4){
                    printf("\n    Nao e possivel remover o elemento, nao existe nenhum conjunto para remove-lo");
                
                }else{
                    printf("\n    Elemento removido com sucesso!\n\n");
                }

                break;
            
            case 10:
                mostrarTodosConjuntos(inicio);
                break;
            default:
                printf("\n    Digite uma opcao valida!\n");
                break;

        }
    }
}