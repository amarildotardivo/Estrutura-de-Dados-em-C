#include <stdio.h>
#include <stdlib.h>

#define tamanho 100

typedef struct conjunto{
    int valores[tamanho];
    int tamanho_conjunto;
    struct conjunto *proximo;    

}tipo_conjunto;

//1) - CRIA UM CONJUNTO VAZIO
tipo_conjunto* criarConjuntoVazio(tipo_conjunto* inicio){
    tipo_conjunto *novo_conjunto, *atual = inicio;

    novo_conjunto = (tipo_conjunto*) malloc(sizeof(tipo_conjunto));

    for(int i = 0; i < tamanho; i++){
        novo_conjunto -> valores[i] = 0;
    }
    novo_conjunto -> tamanho_conjunto = 0;

    if(inicio != NULL){
        while (atual != NULL){

            if(atual -> proximo == NULL){
                atual -> proximo = novo_conjunto;
                novo_conjunto -> proximo = NULL;

                return inicio;
            }
            atual = atual -> proximo;
        }
        
    }else{
        novo_conjunto -> proximo = inicio;
        inicio = novo_conjunto;
    }

    
    printf("\n\n    Conjunto Vazio Criado! tamanho_conjunto: %d\n\n", novo_conjunto -> tamanho_conjunto);
    return inicio;
}

// 2) - INSERE UM ELEMENTO NO CONJUNTO
int inserirElemento(tipo_conjunto* inicio, int id_conjunto, int elemento){
    int posicao = 0;
    tipo_conjunto *atual = inicio;

    if(inicio != NULL){

        if(elemento >= 0 && elemento < 100){

            while(atual != NULL){
                if(posicao == id_conjunto){
                    for(int i = 0; i < tamanho; i++){
                        if(i == elemento && atual -> valores[i] != 1){
                            atual ->valores[i] = 1;
                            atual ->tamanho_conjunto++;
                            //Retorna 0 - Quando o elemento é inserido com sucesso no conjunto
                            return 0;
                        }
                    }
                    //Retorna 1 - Quando o elemento não é encontrado no grupo solicitado
                    return 1;
                }
                posicao++;
                atual = atual -> proximo;
            }
            //Retorna 2 - Quando não encontra o conjunto solicitado pelo usuário
            return 2;

        }else{
            //Retorna 3 - Quando o elemento é menor que 0 e maior que 99
            return 3;
        }

    }else{
        //Retorna 4 - quando não existe nenhum conjunto para inserir o elemento
        return 4;
    }
    
    
}

// 3) - REMOVE UM ELEMENTO DO CONJUNTO
int removeElemento(tipo_conjunto* inicio, int id_conjunto, int elemento){
    int posicao = 0;
    tipo_conjunto *atual = inicio;

    if(inicio != NULL){

        if(elemento >= 0 && elemento < 100){

            while(atual != NULL){
                if(posicao == id_conjunto){
                    for(int i = 0; i < tamanho; i++){
                        if(i == elemento && atual -> valores[i] != 0){
                            atual ->valores[i] = 0;
                            atual ->tamanho_conjunto--;
                            //Retorna 0 - Quando o elemento é removido com sucesso do conjunto
                            return 0;
                        }
                    }
                    //Retorna 1 - Quando o elemento não é encontrado no grupo solicitado
                    return 1;
                }
                posicao++;
                atual = atual -> proximo;
            }
            //Retorna 2 - Quando não encontra o conjunto solicitado pelo usuário
            return 2;

        }else{
            //Retorna 3 - Quando o elemento é menor que 0 e maior que 99
            return 3;
        }

    }else{
        //Retorna 4 - quando não existe nenhum conjunto para remover o elemento
        return 4;
    }
    
    
}

//EXTRA - IMPRIME TODOS OS CONJUNTOS
void mostrarTodosConjuntos(tipo_conjunto* inicio){
    int posicao = 0;
    tipo_conjunto *atual = inicio;
    
    if(inicio != NULL){
        
        printf("\n    Lista de Conjuntos:\n\n");
        while(atual != NULL){
            printf("      Posicao: [%d]\n", posicao);
            printf("      Valores do Conjunto:");
            if(atual -> tamanho_conjunto > 0){
                for(int i = 0; i < tamanho; i++){
                    if(atual -> valores[i] == 1){
                        printf("[ %d ]", i);

                    }
                }
            }else{
                printf("[ Conjunto Vazio ]");
            }
            printf("\n      Tamanho: %d\n\n", atual -> tamanho_conjunto);   
            atual = atual -> proximo;
            posicao++;
        }
        printf("\n\n");

    }else{
        printf("\n    Nao e possivel imprimir, pois nao existe nenhum conjunto!\n\n");
    }
}