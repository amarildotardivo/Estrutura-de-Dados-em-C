#include<stdio.h>
#include<stdlib.h>

struct reg_no_arvore
{
    struct reg_no_arvore *ptrEsquerda;
    int chave;
    struct reg_no_arvore *ptrDireita;
};
typedef struct reg_no_arvore **tipo_no_arvore;


tipo_no_arvore inicializar_arvore(tipo_no_arvore sub_raiz)
{
    sub_raiz = (struct reg_no_arvore**)malloc(sizeof(struct reg_no_arvore*));
    *sub_raiz = NULL;
}

void incluir_no_arvore(tipo_no_arvore sub_raiz, int chave)
{
    if (*sub_raiz == NULL)
    {
        *sub_raiz = malloc(sizeof(struct reg_no_arvore));
        (*sub_raiz)->chave = chave;
        (*sub_raiz)->ptrEsquerda = NULL;
        (*sub_raiz)->ptrDireita = NULL;
    }
    else
    {
        if (chave < (*sub_raiz)->chave)
        {
            incluir_no_arvore(&((*sub_raiz)->ptrEsquerda), chave);
        }
        else
        {
            if (chave > (*sub_raiz)->chave)
            {
                incluir_no_arvore(&((*sub_raiz)->ptrDireita), chave);
            }
        }
    }
}

void percurso_em_ordem(tipo_no_arvore sub_raiz)
{
    if (*sub_raiz != NULL)
    {
        percurso_em_ordem(&((*sub_raiz)->ptrEsquerda));
        printf("%d ", (*sub_raiz)->chave);
        percurso_em_ordem(&((*sub_raiz)->ptrDireita));
    }
}

void percurso_em_pre_ordem(tipo_no_arvore sub_raiz)
{
    if (*sub_raiz != NULL)
    {
        printf("%d ", (*sub_raiz)->chave);
        percurso_em_pre_ordem(&((*sub_raiz)->ptrEsquerda));
        percurso_em_pre_ordem(&((*sub_raiz)->ptrDireita));
    }
}

void percurso_em_pos_ordem(tipo_no_arvore sub_raiz)
{
    if (*sub_raiz != NULL)
    {
        percurso_em_pos_ordem(&((*sub_raiz)->ptrEsquerda));
        percurso_em_pos_ordem(&((*sub_raiz)->ptrDireita));
        printf("%d ", (*sub_raiz)->chave);
    }
}

int encontrar_elemento(tipo_no_arvore sub_raiz, int chave)
{
    if ((*sub_raiz) == NULL)
    {
        return 0;
    }
    else
    {
        if (chave == (*sub_raiz)->chave)
        {
            return 1;
        }
        else
        {
            if (chave < (*sub_raiz)->chave)
            {
                return encontrar_elemento(&((*sub_raiz)->ptrEsquerda), chave);
            }
            else
            {
                if (chave > (*sub_raiz)->chave)
                {
                    return encontrar_elemento(&((*sub_raiz)->ptrDireita), chave);
                }
            }
        }
    }
}

int excluir_menor(tipo_no_arvore sub_raiz)
{
    struct reg_no_arvore *auxiliar;
    int chave;

    if (*sub_raiz != NULL)
    {
        if ((*sub_raiz)->ptrEsquerda != NULL)
        {
            return excluir_menor(&((*sub_raiz)->ptrEsquerda));
        }
        else
        {
            auxiliar = *sub_raiz;
            chave = auxiliar->chave;
            *sub_raiz = (*sub_raiz)->ptrDireita;
            free(auxiliar);
            return chave;
        }
    }
    else
    {
        return -1;
    }
}

int excluir_elemento(tipo_no_arvore sub_raiz, int chave)
{
    struct reg_no_arvore *auxiliar;

    if (*sub_raiz != NULL)
    {
        if (chave < (*sub_raiz)->chave)
        {
            return excluir_elemento(&((*sub_raiz)->ptrEsquerda), chave);
        }
        else
        {
            if (chave > (*sub_raiz)->chave)
            {
                return excluir_elemento(&((*sub_raiz)->ptrDireita), chave);
            }
            else
            {
                if ((*sub_raiz)->ptrEsquerda == NULL)
                {
                    auxiliar = *sub_raiz;
                    *sub_raiz = (*sub_raiz)->ptrDireita;
                    free(auxiliar);
                }
                else
                {
                    if ((*sub_raiz)->ptrDireita == NULL)
                    {
                        auxiliar = *sub_raiz;
                        *sub_raiz = (*sub_raiz)->ptrEsquerda;
                        free(auxiliar);
                    }
                    else
                    {
                        (*sub_raiz)->chave = excluir_menor(&((*sub_raiz)->ptrDireita));
                    }
                }
                return 1;
            }
        }
    }
    else
    {
        return 0;
    }
}

// QUESTAO 1 ---------------------------------------------------
int retornarMaior(tipo_no_arvore sub_raiz)
{

    if (*sub_raiz != NULL)
    {
        if ((*sub_raiz)->ptrDireita != NULL)
        {
            return retornarMaior(&((*sub_raiz)->ptrDireita));
        }
        else
        {
            return (*sub_raiz)->chave;
        }
    }
    else
    {
        return -1;
    }
}

// QUESTAO 2 ---------------------------------------------------
int somaValores(tipo_no_arvore sub_raiz)
{
    int soma = 0;
    if (*sub_raiz != NULL)
    {
        soma += somaValores(&((*sub_raiz)->ptrEsquerda));
        soma += somaValores(&((*sub_raiz)->ptrDireita));
        return soma += (*sub_raiz)->chave;
    }
    
    return soma;
}

// QUESTAO 3 ---------------------------------------------------
int totalNos(tipo_no_arvore sub_raiz)
{
    int soma = 0;

    if (*sub_raiz != NULL)
    {
        soma += totalNos(&((*sub_raiz)->ptrEsquerda));
        soma += totalNos(&((*sub_raiz)->ptrDireita));
        soma ++;

    }
    return soma;
    
}

// QUESTAO 4 ---------------------------------------------------
int mediaNos(tipo_no_arvore sub_raiz)
{
    float media;

    media = somaValores(sub_raiz) / totalNos(sub_raiz);

    return media;
}

// QUESTAO 5 ---------------------------------------------------
int numeroFolhas(tipo_no_arvore sub_raiz )
{
    int soma_folhas = 0;
    
    
    if(*sub_raiz != NULL){

        soma_folhas += numeroFolhas(&((*sub_raiz)->ptrEsquerda));
        soma_folhas += numeroFolhas(&((*sub_raiz)->ptrDireita));

        if((*sub_raiz)->ptrEsquerda == NULL && (*sub_raiz)->ptrDireita == NULL){
            soma_folhas++;
        }  
    }

    return soma_folhas;
}

// QUESTAO 6 ---------------------------------------------------
int quantidadeNulls(tipo_no_arvore sub_raiz)
{   
    int soma_nulls = 0;

    if(*sub_raiz != NULL){
        soma_nulls += quantidadeNulls(&((*sub_raiz)->ptrEsquerda));
        soma_nulls += quantidadeNulls(&((*sub_raiz)->ptrDireita));    
    }else{
        return 1;
    }

    return soma_nulls;
    
}

// QUESTAO 7 ---------------------------------------------------
int alturaArvore(tipo_no_arvore sub_raiz)
{   
    int alturaEsq = 0, alturaDir = 0;

    if(*sub_raiz != NULL){

        if(&((*sub_raiz)->ptrEsquerda) != NULL){
            alturaEsq++;
            alturaEsq += alturaArvore(&((*sub_raiz)->ptrEsquerda));
        }
        if(&((*sub_raiz)->ptrDireita) != NULL){
            alturaDir++;
            alturaDir += alturaArvore(&((*sub_raiz)->ptrDireita));
        }

        if(alturaEsq > alturaDir){
            return alturaEsq;

        }else{
            return alturaDir;
        }

    }else{
        return 0;
    }
}

// QUESTAO 8 ---------------------------------------------------
int nosMultiplos3(tipo_no_arvore sub_raiz)
{
    int multiplos = 0;

    if (*sub_raiz != NULL)
    {
        multiplos += nosMultiplos3(&((*sub_raiz)->ptrEsquerda));
        multiplos += nosMultiplos3(&((*sub_raiz)->ptrDireita));
        
        if((*sub_raiz)->chave % 3 == 0){
            multiplos ++;
        }

    }
    return multiplos;
    
}

// QUESTAO 9 ---------------------------------------------------
// RESPOSTA QUESTAO 11: 
int encontrar_elemento_comparacoes(tipo_no_arvore sub_raiz, int chave)
{   int comparacoes = 0;

    if ((*sub_raiz) == NULL)
    {
        return 0;
    }
    else
    {
        comparacoes++;
        if (chave == (*sub_raiz)->chave)
        {
            return comparacoes;
        }
        else
        {
            if (chave < (*sub_raiz)->chave)
            {
                return comparacoes += encontrar_elemento_comparacoes(&((*sub_raiz)->ptrEsquerda), chave);
            }
            else
            {
                if (chave > (*sub_raiz)->chave)
                {
                    return comparacoes += encontrar_elemento_comparacoes(&((*sub_raiz)->ptrDireita), chave);
                }
            }
        }
    }

}

//AULA 11 - QUESTAO 1
void copia_arvore_em_pre_ordem(tipo_no_arvore sub_raiz, tipo_no_arvore sub_raiz2){
    
    if (*sub_raiz != NULL)
    {   
        incluir_no_arvore(sub_raiz2, (*sub_raiz)->chave);
        copia_arvore_em_pre_ordem(&((*sub_raiz)->ptrEsquerda), sub_raiz2);
        copia_arvore_em_pre_ordem(&((*sub_raiz)->ptrDireita), sub_raiz2);
    }
}
