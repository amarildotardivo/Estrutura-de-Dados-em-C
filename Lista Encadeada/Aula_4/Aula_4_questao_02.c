#include <stdio.h>
#include <stdlib.h>

typedef struct no{
    char nome;
    struct no *proximo;
}tipo_no;

// 1) - Incluir Nome
tipo_no* incluirNome(tipo_no* inicio){
    char nome;
    tipo_no *novo;
    
    printf("\n    Digite o nome a ser incluido no inicio da lista: ");
    scanf("%[\n^s]", &nome);

    novo = (tipo_no*) malloc(sizeof(tipo_no));
    novo -> nome = nome;
    novo -> proximo = inicio;
    inicio = novo;

    printf("%s", novo -> nome);

    return inicio;
}

int main(){
    int opcao;
    tipo_no *inicio = NULL;

    while (opcao != 4){
        printf("\n -------------- MENU -------------- \n\n");
        printf(" 1) - Inclusao de Nome\n\n");
        
        printf(" 2) - Exclusao de Nome\n\n");
        
        printf(" 3) - Busca por um Nome\n\n");
        
        printf(" 6) - Limpar a lista - Excluir todos os Nomes\n\n");
        
        printf(" 4) - Finalizacao do programa\n\n");
        
        printf("\n Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao){
        case 1:
            inicio = incluirNome(inicio);
            break;
        
        default:
            printf("\n    Digite uma opcao valida!\n");
            break;
        }
    }
    

}