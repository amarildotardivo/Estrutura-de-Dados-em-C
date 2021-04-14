#include <stdlib.h>

typedef struct no
{
    int dado;
    struct no *proximo;
} tipo_no;

typedef struct pilhaEncadeada
{
    tipo_no* topo;
    int quantidadeElementos;
}tipo_pilha;

// A) CRIAR PILHA - VAZIA
tipo_pilha* criarPilha(){
    
    tipo_pilha* pilha = (tipo_pilha*) malloc(sizeof(tipo_pilha));
    pilha -> topo = NULL;
    pilha -> quantidadeElementos = 0;

    return pilha;
}

// B) INCLUI NO TOPO DA PILHA
void empilhar(tipo_pilha* pilha, int elemento){
    tipo_no* novo;

    novo = (tipo_no*) malloc(sizeof(tipo_no));
    novo -> dado = elemento;
    novo -> proximo = pilha -> topo;
    pilha -> topo = novo;

    pilha -> quantidadeElementos++;

}

// C) EXCLUSÃO NO TOPO DA PILHA
int desempilhar(tipo_pilha* pilha){
    tipo_no* auxiliar;
    int dadoExcluido;

    if(pilha != NULL){

        if(pilha -> topo != NULL){
            auxiliar = pilha -> topo;
            pilha -> topo = auxiliar -> proximo;
            dadoExcluido = auxiliar -> dado;
            pilha -> quantidadeElementos--;
            free(auxiliar);

            return dadoExcluido;

        }else{
            //Retorna 0 - Quando a pilha está vazia
            return 0;
        }

    }else{
        //Retorna -1 - Quando Não existir Pilha Criada
        return -1;
    }
}

// D) VERIFICAR SE A PILHA ESTÁ VAZIA
int verificaPilhaVazia(tipo_pilha* pilha){
    
    if(pilha != NULL){

        if(pilha -> quantidadeElementos == 0){
            //Retorna 1 - Quando a pilha está vazia
            return 1;

        }else {
            //Retorna 0 - Quando a pilha não está vazia
            return 0;
        }

    }else{
        //Retorna -1 - Quando Não existir Pilha Criada
        return -1;
    }
}

// E) OBTEM O TAMANHO DA PILHA
int tamanhoPilha(tipo_pilha* pilha){
    
    if(pilha != NULL){
        return pilha -> quantidadeElementos;

    }else{
        //Retorna -1 - Quando Não existir Pilha Criada
        return -1;
    }
}

// F) APAGAR PILHA
int apagarPilha(tipo_pilha* pilha){
    tipo_no* auxiliar;

    if(pilha != NULL){

        if(pilha -> topo != NULL){
        
            while (pilha -> topo != NULL){
                auxiliar = pilha -> topo;
                pilha -> topo = auxiliar -> proximo;
                pilha -> quantidadeElementos--;
                free(auxiliar);
            }
        }

        if(pilha->topo == NULL){
            pilha = NULL;
        }

    }else{
        //Retorna -1 - Quando Não existir Pilha Criada
        return -1;
    }

}