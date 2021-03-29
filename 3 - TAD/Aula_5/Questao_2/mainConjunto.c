#include "conjunto.h"

int main(){
    int opcao = 0, id_conjunto, id_conjunto_2, elemento, resultado, vetor_conjunto[tamanho];
    tipo_conjunto *inicio = NULL;

    while(opcao != 15){
        printf("\n -------------- MENU -------------- \n\n");
        printf(" 1) - Cria Um Conjunto Vazio \n\n");
        
        printf(" 2) - Inserir Um Elemento no Conjunto vazio \n\n");

        printf(" 3) - Remove Um Elemento do Conjunto vazio \n\n");
        
        printf(" 4) - Uniao de 2 Conjuntos \n\n");

        printf(" 5) - Intersecao de 2 Conjuntos \n\n");

        printf(" 6) - Diferenca de 2 Conjuntos \n\n");

        printf(" 7) - Testa se Um Numero Pertence ao Conjunto \n\n");

        printf(" 8) - Menor Valor de Um Conjunto \n\n");

        printf(" 9) - Maior Valor de Um Conjunto \n\n");

        printf(" 10) - Verifica se Dois Conjuntos sao Iguais \n\n");

        printf(" 11) - Verifica o Tamanho de um Conjunto \n\n");

        printf(" 12) - Verifica se o Conjunto e Vazio \n\n");

        printf(" 13) - Imprime Um Conjunto \n\n");

        printf(" 14) - Mostra Todos os Conjuntos \n\n");
        
        printf("\n Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao){
            // 1) - CRIAR CONJUNTO VAZIO
            case 1:
                inicio = criarConjuntoVazio(inicio);
                if(inicio != NULL){
                    printf("\n    Conjunto Vazio Criado com Sucesso!\n\n");
                }else{
                    printf("\n    Ocorreu um erro e não foi possivel criar o Conjunto Vazio!\n\n");
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
                    printf("\n        Nao e possivel inserir o elemento, pois e menor que 0 ou maior que 99!");
                
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

            // 5) - INTERSECÇÃO
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
                printf("\n    Entre com o ID do conjunto que deseja saber o menor numero: ");
                scanf("%d", &id_conjunto);
        
                resultado = menorValor(inicio, id_conjunto);

                if( resultado == -1 ){
                    printf("\n      O Conjunto esta Vazio!\n\n", elemento);
                
                }else if ( resultado == -2 ){
                    printf("\n        O Conjunto Informado nao Existi!\n\n");

                }else if ( resultado == -3 ){
                    printf("\n        A lista de Conjuntos Nao Existe!\n\n");

                }else {
                    printf("\n        O menor numero e: %d!\n\n", resultado);
                }

                break;
            
            // 9) - MAIOR VALOR DE UM CONJUNTO
            case 9:
                printf("\n    Entre com o ID do conjunto que deseja saber o maior numero: ");
                scanf("%d", &id_conjunto);
        
                resultado = maiorValor(inicio, id_conjunto);

                if( resultado == -1 ){
                    printf("\n      O Conjunto esta Vazio!\n\n", elemento);
                
                }else if ( resultado == -2 ){
                    printf("\n        O Conjunto Informado nao Existi!\n\n");

                }else if ( resultado == -3 ){
                    printf("\n        A lista de Conjuntos Nao Existe!\n\n");

                }else {
                    printf("\n        O maior numero e: %d!\n\n", resultado);
                }

                break;

            // 10) - TESTA SE DOIS CONJUNTOS SÃO IGUAIS
            case 10:
                printf("\n    Entre com o Primeiro Conjunto: ");
                scanf("%d", &id_conjunto);

                printf("\n    Entre com o Segundo Conjunto: ");
                scanf("%d", &id_conjunto_2);
                
                resultado = verificaIguais(inicio, id_conjunto, id_conjunto_2);

                if ( resultado == 0 ){
                    printf("\n        Os Conjuntos: %d e %d, Nao sao Iguais!\n\n", id_conjunto, id_conjunto_2);

                }else if ( resultado == 1 ){
                    printf("\n        Os Conjuntos: %d e %d, sao Iguais!\n\n", id_conjunto, id_conjunto_2);

                }else if ( resultado == 2 ){
                    printf("\n        O Primeiro Conjunto nao Existe!\n\n");
                }else if ( resultado == 3 ){
                    printf("\n        O Segundo Conjunto nao Existe!\n\n");
                }else if ( resultado == 4 ){
                    printf("\n        Amabos Conjuntos nao Existem!\n\n");
                }else if ( resultado == 5 ){
                    printf("\n        A lista de Conjuntos Nao Existe!\n\n");
                }

                break;

            // 11) - TAMANHO DE UM CONJUNTO
            case 11:
                printf("\n    Entre com o ID do conjunto que deseja saber o tamanho: ");
                scanf("%d", &id_conjunto);

                resultado = tamanhoConjunto(inicio, id_conjunto);

                if ( resultado == -1 ){
                    printf("\n        O Conjunto %d que foi Informado, Nao foi Encontrado!\n\n", id_conjunto);
                
                } else if ( resultado == -2 ){
                    printf("\n        A lista de Conjuntos Nao Existe!\n\n");

                } else {
                    printf("\n        O Tamanho do Conjunto %d e: %d!\n\n", id_conjunto, resultado);
                }

                break;

            // 12) - VERIFICA SE O CONJUNTO É VAZIO
            case 12:
                printf("\n    Entre com o ID do conjunto que deseja verificar se e Vazio: ");
                scanf("%d", &id_conjunto);

                resultado = verificaConjuntoVazio(inicio, id_conjunto);

                if ( resultado == 0 ){
                    printf("\n        O Conjunto e Vazio!\n\n");
                }else if ( resultado == 1 ){
                    printf("\n        O Conjunto Nao e Vazio!\n\n");

                }else if ( resultado == -1 ){
                    printf("\n        O Conjunto %d que foi Informado, Nao foi Encontrado!\n\n", id_conjunto);

                }else if ( resultado == -2 ){
                    printf("\n        A lista de Conjuntos Nao Existe!\n\n");
                }

                break;

            // 13) - IMPRIME UM CONJUNTO
            case 13:
                printf("\n    Entre com o ID do conjunto que deseja Imprimir: ");
                scanf("%d", &id_conjunto);

                resultado = mostrarConjunto(inicio, id_conjunto, vetor_conjunto);

                if ( resultado == 0 ){
                    printf("\n        Conjunto %d: [ Conjunto Vazio ]\n\n", id_conjunto);
                    
                }else if ( resultado == -1 ){
                    printf("\n        O Conjunto %d que foi Informado, Nao foi Encontrado!\n\n", id_conjunto);

                }else if ( resultado == -2 ){
                    printf("\n        A lista de Conjuntos Nao Existe!\n\n");

                }else {
                    printf("\n    Conjunto %d: ", id_conjunto);
                    for(int i = 0; i < tamanho; i++){
                        if(vetor_conjunto[i] == 1){
                            printf("[ %d ]", i);

                        }
                    }
                    printf("\n\n");
                }

                break;

            // EXTRA - IMPRIME TODOS OS CONJUNTOS
            case 14:
                mostrarTodosConjuntos(inicio);
                break;

            default:
                printf("\n    Digite uma opcao valida!\n");
                break;

        }
    }
}