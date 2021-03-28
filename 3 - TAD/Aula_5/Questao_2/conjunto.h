#include <stdio.h>
#include <stdlib.h>

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

//EXTRA - IMPRIME TODOS OS CONJUNTOS
void mostrarTodosConjuntos(tipo_conjunto* );