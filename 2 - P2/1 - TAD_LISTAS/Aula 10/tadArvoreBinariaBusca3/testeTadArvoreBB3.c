#include<stdio.h>
#include"tadArvoreBB3.h"
int main()
{
    tipo_no_arvore arvore;
    int chave, soma = 0, total_nos = 0, soma_folhas = 0, soma_nulls = 0, altura = 0;

    arvore = inicializar_arvore(arvore);

    incluir_no_arvore(arvore, 100);
    incluir_no_arvore(arvore, 50);
    incluir_no_arvore(arvore, 150);
    incluir_no_arvore(arvore, 125);
    incluir_no_arvore(arvore, 25);
    incluir_no_arvore(arvore, 75);
    incluir_no_arvore(arvore, 45);
    incluir_no_arvore(arvore, 35);
    incluir_no_arvore(arvore, 48);
    incluir_no_arvore(arvore, 175);
    incluir_no_arvore(arvore, 165);
    incluir_no_arvore(arvore, 160);
    printf("\n\n  Listagem em ordem:\n");
    printf("    ");
    percurso_em_ordem(arvore);
    printf("\n\n  Listagem em pre-ordem:\n");
    printf("    ");
    percurso_em_pre_ordem(arvore);
    printf("\n\n  Listagem em pos-ordem:\n");
    printf("    ");
    percurso_em_pos_ordem(arvore);

    // QUESTAO 1 ------------------------------------------------
    printf("\n\n  Encontrar Maior Elemento: %d", retornarMaior(arvore));

    // QUESTAO 2 ------------------------------------------------
    printf("\n\n  Soma de Todos os Elementos: %d", somaValores(arvore));

    // QUESTAO 3 ------------------------------------------------
    printf("\n\n  Total de Nos: %d", totalNos(arvore));

    // QUESTAO 4 ---------------------------------------------------
    printf("\n\n  Media dos Nos: %d", mediaNos(arvore));

    // QUESTAO 5 ---------------------------------------------------
    printf("\n\n  Numero de Folhas: %d", numeroFolhas(arvore));

    // QUESTAO 6 ---------------------------------------------------
    printf("\n\n  Numero de NULLS: %d", quantidadeNulls(arvore));

    // QUESTAO 7 ---------------------------------------------------
    printf("\n\n  Altura da Arvore: %d", alturaArvore(arvore)); 

    // QUESTAO 8 ------------------------------------------------
    printf("\n\n  Nos Multiplos de 3: %d", nosMultiplos3(arvore));

    //---------------------------------------------------------------------------------------

    printf("\n\n  Encontrar 45: %d", encontrar_elemento(arvore, 45));
    printf("\n  Encontrar 44: %d", encontrar_elemento(arvore, 44));
    chave = excluir_menor(arvore);
    printf("\n\n  Menor elemento excluido: %d", chave);
    printf("\n\n  Excluir 45: %d", excluir_elemento(arvore, 45));
    printf("\n  Excluir 44: %d\n\n", excluir_elemento(arvore, 44));
    printf("    ");
    percurso_em_ordem(arvore);
    printf("\n\n");
    return 0;
}
