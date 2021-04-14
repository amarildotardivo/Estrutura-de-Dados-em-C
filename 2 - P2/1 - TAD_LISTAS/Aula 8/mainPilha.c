#include <stdio.h>
#include "pilhaEncadeada.h"

int main(){
    int opcao, elemento, resultado;
    tipo_pilha *pilha = NULL;

    while(opcao != 8){

        printf("\n -------------------- MENU -------------------- \n\n");
        printf(" 1) - Cria Pilha Vazia \n\n");
        
        printf(" 2) - Empilhar elemento \n\n");

        printf(" 3) - Desempilhar elemento \n\n");
        
        printf(" 4) - Veriﬁcar se a Pilha esta vazia \n\n");

        printf(" 5) - Veriﬁcar o tamanho da Pilha \n\n");

        printf(" 6) - Apagar Pilha \n\n");

        printf(" 7) - Finalizar Programa \n\n");
        
        printf("\n Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao){

        case 1:
            pilha = criarPilha();

            if( pilha != NULL){
                printf("\n    Pilha Criada com Sucesso!\n");
            }else{
                printf("\n    Ocorreu um erro ao criar a Pilha!\n");
            }

            break;

        case 2:
            printf("\n    Informe o Elemento para empilhar: ");
            scanf("%d", &elemento);
            
            empilhar(pilha, elemento);
            printf("\n");
            break;

        case 3:
            elemento = desempilhar(pilha);
            printf("\n    Elemento Desempilhado foi: [%d]!\n", elemento);
            break;

        case 4:
            resultado = verificaPilhaVazia(pilha);

            if(resultado == 1){
                printf("\n    Pilha Esta Vazia!\n");

            }else{
                printf("\n    Pilha Nao Esta Vazia!\n");
            }

            break;

        case 5:
            resultado = tamanhoPilha(pilha);
            printf("\n    Tamanho da Pilha: [%d]\n", resultado);
            break;
        
        case 6:
            apagarPilha(pilha);
            printf("\n    Pilha Apagada Com Sucesso!\n");
            break;

        case 7:
            printf("\n    Programa Encerrado!\n\n");
            return 0;

        default:
            printf("\n    Digite uma opcao valida!\n");
            break;
        }
    }
    
    return 0;
}