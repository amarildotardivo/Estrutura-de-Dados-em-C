
typedef struct filaEncadeada tipo_fila;

// A) CRIAR FILA VAZIA
//Retorna 0 - Informando que a alocação não foi realizada com sucesso
tipo_fila* criarFila();

// B) - Incluir elemento no final da fila
//Retorna 0 - Informando que a alocação não foi realizada com sucesso
int emfileirar(tipo_fila* fila, int elemento);

// C) - Exluir elemento no inicio da fila
//Retorna o Dado Excluido
// Retorna 0 - Quando a fila Está vazia
int desemfileirar(tipo_fila* fila);

// D) VERIFICAR SE A FILA ESTÁ VAZIA
//Retorna 1 - quando a fila estiver vazia
//Retorna 0 - Quando a fila nao estiver vazia
int filaVazia(tipo_fila *fila);

// E) VERIFICAR TAMANHO DA FILA
int tamanhoFila(tipo_fila *fila);

// 6) - Limpar a lista
//Retorna 0 - Quando não existe fila para apagar
//Retorna 1 - Quando a fila foi apagada com sucesso
int apagaFila(tipo_fila* fila);