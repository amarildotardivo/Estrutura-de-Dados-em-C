#include <stdio.h>
#include <stdlib.h>
#define tamanho 100

typedef struct conjunto tipo_conjunto;

//1) - CRIA UM CONJUNTO VAZIO
tipo_conjunto* criarConjuntoVazio(tipo_conjunto* );

// 2) - INSERE UM ELEMENTO NO CONJUNTO, Params(*inicio da lista, int id_conjunto, int elemento)
//Retorna 0 - Quando o elemento é inserido com sucesso no conjunto
//Retorna 1 - Quando o elemento não é encontrado no grupo solicitado
//Retorna 2 - Quando não encontra o conjunto solicitado pelo usuário
//Retorna 3 - Quando o elemento é menor que 0 e maior que 99
//Retorna 4 - quando não existe nenhum conjunto para inserir o elemento
int inserirElemento(tipo_conjunto* , int , int );

// 3) - REMOVE UM ELEMENTO DO CONJUNTO, Params(*inicio da lista, int id_conjunto, int elemento)
//Retorna 0 - Quando o elemento é removido com sucesso do conjunto
//Retorna 1 - Quando o elemento não é encontrado no grupo solicitado
//Retorna 2 - Quando não encontra o conjunto solicitado pelo usuário
//Retorna 3 - Quando o elemento é menor que 0 e maior que 99
//Retorna 4 - quando não existe nenhum conjunto para remover o elemento
int removeElemento(tipo_conjunto* , int , int );

// 4) - UNIÃO - FAZ A UNIÃO DE DOIS CONJUNTOS E RETORNA UM TERCEIRO CONJUNTO
// PARAMS - (*inicio da lista, int id_conjunto, int id_conjunto2, int* vetor_uniao)
//Retorna 0 - Quando o conjunto união é criado com sucesso
//Retorna 1 - Quando o id_conjunto não existir na lista de conjuntos
//Retorna 2 - Quando o id_conjunto_2 não existir na lista de conjuntos
//Retorna 3 - Quando ambos conjuntos solicitados para uniao pelo usuário não existem
//Retorna 4 - Quando não existir nenhum conjunto na lista de conjuntos
int uniaoConjuntos(tipo_conjunto* , int , int, int* );

// 5) - INTERSEÇÃO - FAZ A INTERSEÇÃO DE DOIS CONJUNTOS E RETORNA UM TERCEIRO CONJUNTO
// PARAMS - (*inicio da lista, int id_conjunto, int id_conjunto2, int* vetor_intersecao)
//Retorna 0 - Quando tiver sucesso na interseção
//Retorna 1 - Quando o id_conjunto não existir na lista de conjuntos
//Retorna 2 - Quando o id_conjunto_2 não existir na lista de conjuntos
//Retorna 3 - Quando ambos conjuntos solicitados para uniao pelo usuário não existem
//Retorna 4 - Quando não existir nenhum conjunto na lista de conjuntos
int intersecaoConjuntos(tipo_conjunto* , int , int , int* );

// 6) - DIFERENÇA - FAZ A DIFERENÇA DE DOIS CONJUNTOS E RETORNA UM TERCEIRO CONJUNTO
// PARAMS - (*inicio da lista, int id_conjunto, int id_conjunto2, int* vetor_diferença)
//Retorna 0 - Quando tiver sucesso na diferença
//Retorna 1 - Quando o id_conjunto não existir na lista de conjuntos
//Retorna 2 - Quando o id_conjunto_2 não existir na lista de conjuntos
//Retorna 3 - Quando ambos conjuntos solicitados para uniao pelo usuário não existem
//Retorna 4 - Quando não existir nenhum conjunto na lista de conjuntos
int diferencaConjuntos(tipo_conjunto* , int , int , int* );

// 7) - VERIFICA SE O NÚMERO PERTENCE AO CONJUNTO
// PARAMS - (*inicio da lista, int id_conjunto, int numero)
//Retorna 1 - Quando o número existe no conjunto
//Retorna -1 - Quando o número não existe no conjunto
//Retorna 2 - Quando o conjunto solicitado não existe na lista de conjuntos
//Retorna 3 - Quando a lista de conjuntos não existir
int elementoPertenceConjunto(tipo_conjunto* , int , int );

//EXTRA - IMPRIME TODOS OS CONJUNTOS
void mostrarTodosConjuntos(tipo_conjunto* );