// OBS: TEM FUNÇÕES A MAIS QUE EU FIZ PARA TESTAR
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define tam_nome 50

typedef struct no{
    char nome[50];
    struct no *proximo;
}tipo_no;

// 1) - Incluir Nome
tipo_no* incluirNome(tipo_no* inicio){
    char nome[tam_nome];
    tipo_no *novo, *atual = inicio, *anterior = NULL;
    
    printf("\n    Digite o nome a ser incluido na lista: ");
    // LIMPA O BUFFER DO TECLADO PARA NÃO VIR COM LIXO
    fflush(stdin);
    scanf("%[^\n]s", nome);
    
    novo = (tipo_no*) malloc(sizeof(tipo_no));
    strcpy(novo -> nome, nome);

    //VERIFICA SE EXISTE ALGUM NOME NA LISTA
    if( inicio != NULL ){

        //CONDIÇÃO QUE INFORMA QUE A LISTA ACABOU E ANDA PELA LISTA
        while( atual != NULL ){
        
            //VERIFICA SE O NOVO NOME É "MENOR" QUE O NOME ATUAL DA LISTA
            if( (strcmp(novo -> nome, atual -> nome) < 0) ){
        
                //INSERI O NOME NO "MEIO"
                if(anterior != NULL){
                    
                    anterior -> proximo = novo;
                    novo -> proximo = atual;

                    printf("\n        O nome [%s] foi incluido com sucesso!\n\n", novo -> nome);
                    return inicio;

                //INSERI O NOME NA PRIMEIRA POSIÇÃO QUANDO A LISTA EXISTE
                }else{
                    
                    novo -> proximo = inicio;
                    inicio = novo;

                    printf("\n        O nome [%s] foi incluido com sucesso!\n\n", novo -> nome);
                    return inicio;
                }
            // INSERI O NOME NA ÚLTIMA POSIÇÃO
            }else if(atual -> proximo == NULL){
                    
                    atual -> proximo = novo;
                    novo -> proximo = NULL;

                    printf("\n        O nome [%s] foi incluido com sucesso!\n\n", novo -> nome);
                    return inicio;

            }
            // ANDA PELA LISTA
            anterior = atual;
            atual = atual -> proximo;
        }
    //INSERI O NOME NA PRIMEIRA POSIÇÃO QUANDO A LISTA NÃO EXISTE
    }else{
        novo -> proximo = inicio;
        inicio = novo;
    }


    printf("\n        O nome [%s] foi incluido com sucesso!\n\n", novo -> nome);
    
    return inicio;
}

// 2) - Excluir Nome
tipo_no* excluirNome(tipo_no* inicio){
    char nome[tam_nome]; 
    tipo_no *atual = inicio, *anterior = NULL;

    printf("\n    Digite o nome a ser excluido: ");
    // LIMPA O BUFFER DO TECLADO PARA NÃO VIR COM LIXO
    fflush(stdin);
    scanf("%[^\n]s", nome);

    if(inicio != NULL){
        //ANDA PELA LISTA ENQUANTO NÃO ENCONTRA O FINAL DA LISTA OU O NOME DIGITADO PELO USUÁRIO
        while(atual != NULL && strcmp(nome, atual -> nome) != 0){
            anterior = atual;
            atual = atual -> proximo;
        }
        // VERIFICA SE O NOME FOI ENCONTRADO PARA EXCLUIR
        if(atual != NULL){
            // EXCLUI O PRIMEIRO NOME
            if(anterior == NULL){
                inicio = atual -> proximo;
            
            // EXCLUI O NOME DO MEIO DA LISTA OU DO FINAL, POIS ATUAL -> PROXIMO == NULL
            }else{
                anterior -> proximo = atual -> proximo;

            }
            // INFORMA AO USUÁRIO O NOME EXCLUIDO E LIBERA DA MEMÓRIA
            printf("\n        O nome excluido foi: [%s]\n\n", atual -> nome);
            free(atual);

        // A LISTA EXISTE, PORÉM O NOME NÃO FOI ENCONTRADO
        }else{
            printf("\n        O nome nao foi encontrado para ser excluido!\n\n");
        }
    //INFORMA AO USUÁRIO QUE NÃO EXISTE LISTA DE NOMES PARA EXCLUIR UM POSSIVEL NOME
    }else{
        printf("\n        Nao e possivel excluir nome, lista nao existe!\n");
    }

    return inicio;
}

// 3) - Buscar Nome
void buscarNome(tipo_no* inicio){
    char nome[tam_nome]; 
    int posicao = 0;
    tipo_no *atual = inicio;

    printf("\n    Digite o nome a ser buscado: ");
    // LIMPA O BUFFER DO TECLADO PARA NÃO VIR COM LIXO
    fflush(stdin);
    scanf("%[^\n]s", nome);

    if(inicio != NULL){

        while(atual != NULL && strcmp(nome, atual -> nome) != 0){
            atual = atual -> proximo;
            posicao++;
        }

        if(atual != NULL){
            printf("\n        Posicao: %d Nome: %s ", posicao + 1, atual -> nome);

        }else{
            printf("\n        O nome nao existe na lista!\n\n");
        }

    }else{
        printf("\n        Lista nao existe, impossivel imprimir! ");
    }
}

// 4) - Exibi todos os nomes da lista
void buscarTodosNomes(tipo_no* inicio){
    int posicao = 0;
    tipo_no *atual = inicio;
    
    if(inicio != NULL){
        
        printf("\n    Lista de Nomes:\n");
        while(atual != NULL){
            printf("      Posicao: [%d] Nome: %s\n", posicao + 1, atual -> nome);   
            atual = atual -> proximo;
            posicao++;
        }
        printf("\n\n");

    }else{
        printf("\n    Nao e possivel imprimir, pois a lista nao existe!\n\n");
    }
}

// 5) - Excluir todos os nomes da lista
tipo_no* excluirTodosNomes(tipo_no* inicio){
    tipo_no *atual;

    if(inicio != NULL){
        while(inicio != NULL){
            atual = inicio;
            inicio = atual -> proximo;
            free(atual);
        }
        printf("\n    Lista Limpa, nao existe mais nomes na lista!!!\n\n");

    }else{
        printf("\n    Nao e possivel excluir, pois a lista nao existe!\n\n");
    }

    return inicio;
}

// 6) - Finalizar o programa e liberar os ponteiros se existirem
int finalizarPrograma(tipo_no* inicio){
    tipo_no *atual;

    if(inicio != NULL){
        while(inicio != NULL){
            atual = inicio;
            inicio = atual -> proximo;
            free(atual);
        }
        return 1;

    }else{
        return 0;
    }
}

int main(){
    int opcao = 0, finalizar = 0;
    tipo_no *inicio = NULL;

    while (opcao != 6){
        printf("\n -------------- MENU -------------- \n\n");
        printf(" 1) - Inclusao de Nome\n\n");
        
        printf(" 2) - Exclusao de Nome\n\n");
        
        printf(" 3) - Busca por um Nome\n");
        printf(" 4) - Exibe todos os Nomes\n\n");
        
        printf(" 5) - Limpar a lista - Excluir todos os Nomes\n\n");
        
        printf(" 6) - Finalizacao do programa\n\n");
        
        printf("\n Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao){
        case 1:
            inicio = incluirNome(inicio);
            break;
        
        case 2:
            inicio = excluirNome(inicio);
            break;
        
        case 3:
            buscarNome(inicio);
            break;

        case 4:
            buscarTodosNomes(inicio);
            break;

        case 5:
            inicio = excluirTodosNomes(inicio);
            break;

        case 6:
            finalizar = finalizarPrograma(inicio);

            if(finalizar == 1){
                printf("\n    Programa Finalizado, todos os nomes foram excluidos!!!\n\n");
            }else{
                printf("\n    Programa Finalizado, nao existiam nomes para excluir!!!\n\n");
            }

            return 0;

        default:
            printf("\n    Digite uma opcao valida!\n");
            break;
        }
    }
    

}