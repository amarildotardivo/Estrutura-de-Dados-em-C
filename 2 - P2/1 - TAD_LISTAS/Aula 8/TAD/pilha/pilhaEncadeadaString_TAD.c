#include <stdlib.h>

typedef struct no
{
    char caracter;
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

    if(pilha == NULL){
        //Retorna 0 - Informando que a alocação não foi realizada com sucesso
        return NULL;
    }

    pilha -> topo = NULL;
    pilha -> quantidadeElementos = 0;

    return pilha;
}

// B) INCLUI NO TOPO DA PILHA
int empilhar(tipo_pilha* pilha, char elemento){
    tipo_no* novo;
    
    novo = (tipo_no*) malloc(sizeof(tipo_no));

    if(novo == NULL){
        //Retorna 0 - Informando que a alocação não foi realizada com sucesso
        return 0;
    }

    novo->caracter = elemento;
    novo -> proximo = pilha -> topo;
    pilha -> topo = novo;

    pilha -> quantidadeElementos++;
}

// C) EXCLUSÃO NO TOPO DA PILHA
char desempilhar(tipo_pilha* pilha){
    char caracterExcluido;
    tipo_no* auxiliar;

    auxiliar = pilha -> topo;
    pilha -> topo = auxiliar -> proximo;
    caracterExcluido = auxiliar->caracter;
    pilha -> quantidadeElementos--;
    free(auxiliar);

    return caracterExcluido;
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