typedef struct reg_no_arvore **tipo_no_arvore;

tipo_no_arvore inicializar_arvore(tipo_no_arvore);
void incluir_no_arvore(tipo_no_arvore, int);
void percurso_em_ordem(tipo_no_arvore);
void percurso_em_pre_ordem(tipo_no_arvore);
void percurso_em_pos_ordem(tipo_no_arvore);
int encontrar_elemento(tipo_no_arvore, int);
int excluir_menor(tipo_no_arvore);
int excluir_elemento(tipo_no_arvore, int);
// QUESTAO 1 ------------------------------------------------------------------------
int retornarMaior(tipo_no_arvore);
// QUESTAO 2 ------------------------------------------------------------------------
int somaValores(tipo_no_arvore );
// QUESTAO 3 ------------------------------------------------------------------------
int totalNos(tipo_no_arvore );
// QUESTAO 4 ------------------------------------------------------------------------
int mediaNos(tipo_no_arvore );
// QUESTAO 5 ------------------------------------------------------------------------
int numeroFolhas(tipo_no_arvore );
// QUESTAO 6 ------------------------------------------------------------------------
int quantidadeNulls(tipo_no_arvore );
// QUESTAO 7 ------------------------------------------------------------------------
int alturaArvore(tipo_no_arvore );
// QUESTAO 8 ------------------------------------------------------------------------
int nosMultiplos3(tipo_no_arvore );
// QUESTAO 9 ------------------------------------------------------------------------
int encontrar_elemento_comparacoes(tipo_no_arvore , int);

//AULA 11 - QUESTAO 1 ---------------------------------------------------------------
void copia_arvore_em_pre_ordem(tipo_no_arvore sub_raiz, tipo_no_arvore sub_raiz2);