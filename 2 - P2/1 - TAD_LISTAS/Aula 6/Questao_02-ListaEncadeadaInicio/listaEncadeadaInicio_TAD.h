
typedef struct no tipo_no;

typedef struct listaEncadeadaInicio tipo_lista;


// A) CRIAR LISTA - VAZIA
tipo_lista* criarLista();

// B) INCLUSÃO NO INICIO DA LISTA
void incluirElemento(tipo_lista* lista, int elemento);

// C) EXCLUSÃO NO INICIO DA LISTA
//Retorna 0 - Quando a Lista não existe
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

// H) CONCATENAR LISTAS
void concatenarListas(tipo_lista* lista, tipo_lista* lista_2);

// EXTRA - IMPRESSÃO DOS ELEMENTOS DA LISTA
void imprimirLista(tipo_lista* lista);
