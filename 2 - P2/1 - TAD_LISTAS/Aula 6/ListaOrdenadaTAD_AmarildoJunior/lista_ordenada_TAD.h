
typedef struct reg_lista tipo_lista;

tipo_lista* criarListaVazia();
int listaVazia(tipo_lista*);
void inserirElementoOrdenado(tipo_lista*, int);
int excluirElementoOrdenado(tipo_lista*, int);
int quantidadeElementosLista(tipo_lista*);
int* obterElementosLista(tipo_lista*);
tipo_lista* apagarLista(tipo_lista*);

// ---------------- QUESTÃO 01 --------------------------------

// 1 - CALCULAR MEDIA ARITIMÉTICA DA LISTA
// Retorna "media"
// Retorna 0 - Quando lista não existe
int calcularMedia( tipo_lista* lista);

// 2 - VERIFICA PROFUNDIDADE DE UMA CELULA DA LISTA
// Retorna "profundidade"
// Retorna 0 - Quando lista não existe
int verificaProfundidade( tipo_lista* lista, int elemento );

// 3 - COMPARAR 2 LISTAS ÁRA VERIFICAR SE SÃO IGUAIS
int compararListas( tipo_lista* lista_1, tipo_lista* lista_2 );

// ---------------- FIM DA QUESTÃO 01 --------------------------------