#include "conjunto.h"

int main(){
    int opcao = 0, id_conjunto, id_conjunto_2, elemento, resultado, vetor_conjunto[tamanho];
    tipo_conjunto *inicio = NULL;

    while(opcao != 15){
        printf("\n -------------- MENU -------------- \n\n");
        printf(" 1) - Cria um Conjunto Vazio\n\n");
        
        printf(" 2) - Inserir um Elemento no Conjunto vazio\n\n");

        printf(" 3) - Remove um Elemento do Conjunto vazio\n\n");
        
        printf(" 4) - Uniao de 2 Conjuntos\n\n");

        printf(" 5) - Intersecao de 2 Conjuntos\n\n");

        printf(" 6) - Diferenca de 2 Conjuntos\n\n");

        printf(" 7) - Testa se um Numero Pertence ao Conjunto \n\n");

        printf(" 8) - Menor Valor de um Conjunto \n\n");
        
        printf("\n Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao){
            // 1) - CRIAR CONJUNTO VAZIO
            case 1:
                inicio = criarConjuntoVazio(inicio);
                if(inicio != NULL){
                    printf("\n    Conjunto Vazio Criado com Sucesso!");
                }else{
                    printf("\n    Ocorreu um erro e não foi possivel criar o Conjunto Vazio!");
                }

                break;

            // 2) - INSERIR ELEMENTO
            case 2:
                printf("\n    Em qual conjunto vc deseja inserir o elemento: ");
                scanf("%d", &id_conjunto);

                printf("\n    Qual elemento vc deseja inserir no conjunto: ");
                scanf("%d", &elemento);

                resultado = inserirElemento(inicio, id_conjunto, elemento);

                if(resultado == 1){
                    printf("\n        Elemento nao encontrado no Conjunto!");

                }else if(resultado == 2){
                    printf("\n        Conjunto nao encontrado!");

                }else if(resultado == 3){
                    printf("\n        Nao e possivel inserir o elemento, pois e menor que 0 e maior que 99!");
                
                }else if(resultado == 4){
                    printf("\n        Nao e possivel inserir o elemento, nao existe nenhum conjunto para inseri-lo");
                
                }else{
                    printf("\n        Elemento inserido com sucesso!\n\n");
                }

                break;

            // 3) - REMOVER ELEMENTO
            case 3:
                printf("\n    De qual conjunto vc deseja remover o elemento: ");
                scanf("%d", &id_conjunto);

                printf("\n    Qual elemento vc deseja remover do conjunto: ");
                scanf("%d", &elemento);

                resultado = removeElemento(inicio, id_conjunto, elemento);

                if(resultado == 1){
                    printf("\n        Elemento nao encontrado no Conjunto!");
                    
                }else if(resultado == 2){
                    printf("\n        Conjunto nao encontrado!");

                }else if(resultado == 3){
                    printf("\n        Nao e possivel remover o elemento, pois e menor que 0 e maior que 99!");
                
                }else if(resultado == 4){
                    printf("\n        Nao e possivel remover o elemento, nao existe nenhum conjunto para remove-lo");
                
                }else{
                    printf("\n        Elemento removido com sucesso!\n\n");
                }

                break;
            
            // 4) - UNIÃO
            case 4:
                printf("\n    Entre com o Primeiro Conjunto: ");
                scanf("%d", &id_conjunto);

                printf("\n    Entre com o Segundo Conjunto: ");
                scanf("%d", &id_conjunto_2);

                resultado = uniaoConjuntos(inicio, id_conjunto, id_conjunto_2, vetor_conjunto);
                
                if ( resultado == 0 ) {
                    
                    printf("      Conjunto União:");
                    for(int i = 0; i < tamanho; i++){
                        if(vetor_conjunto[i] == 1){
                            printf("[ %d ]", i);
                        }
                    }
                    printf("\n\n");

                } else if( resultado ==1 ){
                    printf("\n        O Primeiro Conjunto Nao Existe!\n\n");

                } else if( resultado == 2){
                    printf("\n        O Segundo Conjunto Nao Existe!\n\n");

                } else if( resultado == 3 ){
                    printf("\n        Os Conjuntos Solicitados Nao Existem!\n\n");
                } else{
                    printf("\n        A lista de Conjuntos para Fazer a Uniao Nao Existe!\n\n");
                }

                break;

            // 5) - INTERSEÇÃO
            case 5:
                printf("\n    Entre com o Primeiro Conjunto: ");
                scanf("%d", &id_conjunto);

                printf("\n    Entre com o Segundo Conjunto: ");
                scanf("%d", &id_conjunto_2);

                resultado = intersecaoConjuntos(inicio, id_conjunto, id_conjunto_2, vetor_conjunto);
                
                if ( resultado == 0 ) {
                    
                    printf("      Conjunto Intersecao:");
                    for(int i = 0; i < tamanho; i++){
                        if(vetor_conjunto[i] == 1){
                            printf("[ %d ]", i);
                        }
                    }
                    printf("\n\n");

                } else if( resultado ==1 ){
                    printf("\n        O Primeiro Conjunto Nao Existe!\n\n");

                } else if( resultado == 2){
                    printf("\n        O Segundo Conjunto Nao Existe!\n\n");

                } else if( resultado == 3 ){
                    printf("\n        Os Conjuntos Solicitados Nao Existem!\n\n");
                } else{
                    printf("\n        A lista de Conjuntos para Fazer a Intersecao Nao Existe!\n\n");
                }

                break;

            // 6) - DIFERENÇA
            case 6:
                printf("\n    Entre com o Primeiro Conjunto: ");
                scanf("%d", &id_conjunto);

                printf("\n    Entre com o Segundo Conjunto: ");
                scanf("%d", &id_conjunto_2);

                resultado = diferencaConjuntos(inicio, id_conjunto, id_conjunto_2, vetor_conjunto);
                
                if ( resultado == 0 ) {
                    
                    printf("      Conjunto Diferenca:");
                    for(int i = 0; i < tamanho; i++){
                        if(vetor_conjunto[i] == 1){
                            printf("[ %d ]", i);
                        }
                    }
                    printf("\n\n");

                } else if( resultado ==1 ){
                    printf("\n        O Primeiro Conjunto Nao Existe!\n\n");

                } else if( resultado == 2){
                    printf("\n        O Segundo Conjunto Nao Existe!\n\n");

                } else if( resultado == 3 ){
                    printf("\n        Os Conjuntos Solicitados Nao Existem!\n\n");
                } else{
                    printf("\n        A lista de Conjuntos para Fazer a Diferenca Nao Existe!\n\n");
                }

                break;
            
            // 7) - VERIFICA SE O ELEMENTO EXISTE EM UM DETERMINADO CONJUNTO
            case 7:
                printf("\n    Entre com o ID do conjunto que deseja verificar o numero: ");
                scanf("%d", &id_conjunto);

                printf("\n    Entre com o numero a ser verificado: ");
                scanf("%d", &elemento);

                resultado = elementoPertenceConjunto(inicio, id_conjunto, elemento);

                if( resultado == 1 ){
                    printf("\n      O numero %d pertence ao Conjunto!\n\n", elemento);
                
                }else if ( resultado == -1 ){
                    printf("\n        O numero informado nao existe no Conjunto!\n\n");
                }else if ( resultado == 2 ){
                    printf("\n        O Conjunto informado nao existe na Lista de Conjuntos!\n\n");
                }else if ( resultado == 3){
                    printf("\n        A lista de Conjuntos Nao Existe!\n\n");
                }

                break;

            // 8) - MENOR VALOR DE UM CONJUNTO
            case 8:
                break;
            
            // EXTRA - IMPRIME TODOS OS CONJUNTOS
            case 10:
                mostrarTodosConjuntos(inicio);
                break;

            default:
                printf("\n    Digite uma opcao valida!\n");
                break;

        }
    }
}