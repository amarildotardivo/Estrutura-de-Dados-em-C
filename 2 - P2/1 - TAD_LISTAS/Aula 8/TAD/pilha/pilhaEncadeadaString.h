
typedef struct pilhaEncadeada tipo_pilha;

// A) CRIAR PILHA - VAZIA
tipo_pilha* criarPilha();

// B) INCLUI NO TOPO DA PILHA
//Retorna 0 - Informando que a alocação não foi realizada com sucesso
int empilhar(tipo_pilha* pilha, char elemento);

// C) EXCLUSÃO NO TOPO DA PILHA
//Retorna o Dado desempilhado
//Retorna 0 - Quando a pilha está vazia
//Retorna -1 - Quando Não existir Pilha Criada
char desempilhar(tipo_pilha* pilha);

// D) VERIFICAR SE A PILHA ESTÁ VAZIA
//Retorna 1 - Quando a pilha está vazia
//Retorna 0 - Quando a pilha não está vazia
//Retorna -1 - Quando Não existir Pilha Criada
int verificaPilhaVazia(tipo_pilha* pilha);

// E) OBTEM O TAMANHO DA PILHA
//Retorna a Quantidade de elementos
//Retorna -1 - Quando Não existir Pilha Criada
int tamanhoPilha(tipo_pilha* pilha);

// F) APAGAR PILHA
//Retorna -1 - Quando Não existir Pilha Criada
int apagarPilha(tipo_pilha* pilha);