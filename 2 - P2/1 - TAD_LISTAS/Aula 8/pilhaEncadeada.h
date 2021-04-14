#include <stdlib.h>

typedef struct pilhaEncadeada tipo_pilha;

// A) CRIAR PILHA - VAZIA
tipo_pilha* criarPilha();

// B) INCLUI NO TOPO DA PILHA
void empilhar(tipo_pilha* pilha, int elemento);

// C) EXCLUSÃO NO TOPO DA PILHA
//Retorna o Dado desempilhado
//Retorna 0 - Quando a pilha está vazia
int desempilhar(tipo_pilha* pilha);

// D) VERIFICAR SE A PILHA ESTÁ VAZIA
//Retorna 1 - Quando a pilha está vazia
//Retorna 0 - Quando a pilha não está vazia
int verificaPilhaVazia(tipo_pilha* pilha);

// E) OBTEM O TAMANHO DA PILHA
int tamanhoPilha(tipo_pilha* pilha);

// F) APAGAR PILHA
void apagarPilha(tipo_pilha* pilha);