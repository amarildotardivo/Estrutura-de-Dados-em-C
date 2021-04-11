
typedef struct no tipo_no;

typedef struct listaEncadeadaInicio tipo_lista;


// A) CRIAR LISTA - VAZIA
tipo_lista* criarLista();

// B) INCLUSÃO NO FIM DA LISTA
void incluirElemento(tipo_lista* lista, int elemento);

// C) EXCLUSÃO NO FIM DA LISTA
//Retorna 0 - Quando a Lista está vazia
int excluirElemento(tipo_lista* lista);

// D) VERIFICAR SE A LISTA ESTÁ VAZIA
//Retorna 1 - Quando a lista está vazia
//Retorna 0 - Quando a lista não está vazia
int verificaListaVazia(tipo_lista* lista);

// E) OBTER A QUANTIDADE DE ELEMENTOS DA LISTA
int obterQuantidadeElementos(tipo_lista* lista);
 
// F) APAGAR LISTA
//Retorna 1 - Quando a lista foi apagada
//Retorna 0 - Quando a lista está vazia
int apagarLista(tipo_lista* lista);

// G) OBTER ELEMENTOS DA LISTA
int* obterElementos(tipo_lista* lista);

// H) APAGAR ELEMENTOS IGUAIS
void apagarIguais(tipo_lista* lista, int elemento);

// EXTRA - IMPRESSÃO DOS ELEMENTOS DA LISTA
void imprimirLista(tipo_lista* lista);