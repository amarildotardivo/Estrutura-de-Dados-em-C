#include <stdio.h>
#include <stdlib.h>

#define tamanho 100

typedef struct conjunto{
    int valores[tamanho];
    int tamanho_conjunto;
    struct conjunto *proximo;    

}tipo_conjunto;

//1) - CRIA UM CONJUNTO VAZIO
tipo_conjunto* criarConjuntoVazio(tipo_conjunto* inicio){
    tipo_conjunto *novo_conjunto, *atual = inicio;

    novo_conjunto = (tipo_conjunto*) malloc(sizeof(tipo_conjunto));

    for(int i = 0; i < tamanho; i++){
        novo_conjunto -> valores[i] = 0;
    }
    novo_conjunto -> tamanho_conjunto = 0;

    if (inicio != NULL){
        while (atual != NULL){

            if(atual -> proximo == NULL){
                atual -> proximo = novo_conjunto;
                novo_conjunto -> proximo = NULL;

                return inicio;
            }
            atual = atual -> proximo;
        }
        
    } else {
        novo_conjunto -> proximo = inicio;
        inicio = novo_conjunto;
    }

    return inicio;
}

// 2) - INSERE UM ELEMENTO NO CONJUNTO
int inserirElemento(tipo_conjunto* inicio, int id_conjunto, int elemento){
    int posicao = 0;
    tipo_conjunto *atual = inicio;

    if(inicio != NULL){

        if(elemento >= 0 && elemento < 100){

            while(atual != NULL){
                //ENCONTRA O CONJUNTO INFORMADO PELO USUÁRIO
                if(posicao == id_conjunto){
                    //VARRE O VETOR DO CONJUNTO AFIM DE INSERIR O NUMERO
                    for(int i = 0; i < tamanho; i++){
                        //VERIFICA SE O NUMERO SOLICITADO É IGUAL A POSIÇÃO DO VETOR
                        if(i == elemento && atual -> valores[i] != 1){
                            atual ->valores[i] = 1;
                            atual ->tamanho_conjunto++;
                            //Retorna 0 - Quando o elemento é inserido com sucesso no conjunto
                            return 0;
                        }
                    }
                    //Retorna 1 - Quando o elemento não é encontrado no grupo solicitado
                    return 1;
                }
                posicao++;
                atual = atual -> proximo;
            }
            //Retorna 2 - Quando não encontra o conjunto solicitado pelo usuário
            return 2;

        }else{
            //Retorna 3 - Quando o elemento é menor que 0 e maior que 99
            return 3;
        }

    } else {
        //Retorna 4 - quando não existe nenhum conjunto para inserir o elemento
        return 4;
    }
    
    
}

// 3) - REMOVE UM ELEMENTO DO CONJUNTO
int removeElemento(tipo_conjunto* inicio, int id_conjunto, int elemento){
    int posicao = 0;
    tipo_conjunto *atual = inicio;

    if(inicio != NULL){

        if(elemento >= 0 && elemento < 100){

            while(atual != NULL){
                //ENCONTRA O CONJUNTO INFORMADO PELO USUÁRIO
                if(posicao == id_conjunto){
                    //VARRE O VETOR DO CONJUNTO AFIM DE INSERIR O NUMERO
                    for(int i = 0; i < tamanho; i++){
                        //VERIFICA SE O NUMERO SOLICITADO É IGUAL A POSIÇÃO DO VETOR
                        if(i == elemento && atual -> valores[i] != 0){
                            atual ->valores[i] = 0;
                            atual ->tamanho_conjunto--;
                            //Retorna 0 - Quando o elemento é removido com sucesso do conjunto
                            return 0;
                        }
                    }
                    //Retorna 1 - Quando o elemento não é encontrado no grupo solicitado
                    return 1;
                }
                posicao++;
                atual = atual -> proximo;
            }
            //Retorna 2 - Quando não encontra o conjunto solicitado pelo usuário
            return 2;

        }else{
            //Retorna 3 - Quando o elemento é menor que 0 ou maior que 99
            return 3;
        }

    } else {
        //Retorna 4 - quando não existe nenhum conjunto para remover o elemento
        return 4;
    }
    
    
}

// 4) - UNIÃO - FAZ A UNIÃO DE DOIS CONJUNTOS E RETORNA UM TERCEIRO CONJUNTO
// DEFINIÇÃO: A união de conjuntos corresponde a junção dos elementos dos conjuntos dados
//OBS: Se existirem elementos que se repetem nos conjuntos, ele aparecerá uma única vez no conjunto união
int uniaoConjuntos(tipo_conjunto* inicio, int id_conjunto, int id_conjunto_2, int* conjunto_uniao){
    int posicao = 0, resultado;
    tipo_conjunto *atual = inicio, *conjunto_1 = NULL, *conjunto_2 = NULL;

    if( inicio != NULL ){
        
        while( atual != NULL ){
            //ENCONTRA O CONJUNTO INFORMADO PELO USUÁRIO
            if( id_conjunto == posicao ){
                
                conjunto_1 = atual;

            }else if(id_conjunto_2 == posicao){

                conjunto_2 = atual;
            }
            posicao++;
            atual = atual ->proximo;
        }
        //VERIFICA SE OS CONJUNTOS PARA UNIAO SOLICITADOS EXISTEM
        if(conjunto_1 != NULL && conjunto_2 != NULL){

            for(int i = 0; i < tamanho; i++){
                
                //VERIFICAÇÃO QUE REALIZA A UNIÃO DOS CONJUNTOS
                if( conjunto_1 ->valores[i] == 1 || conjunto_2 ->valores[i] == 1 ){
                    conjunto_uniao[i] = 1;

                }else{
                    conjunto_uniao[i] = 0;
                }
            }
            //Retorna 0 - Quando tiver sucesso na união
            resultado = 0;
        }else{
            if(conjunto_1 == NULL){
                //Retorna 1 - Quando o id_conjunto não existir na lista de conjuntos
                resultado = 1;
            }else if(conjunto_2 == NULL){
                //Retorna 2 - Quando o id_conjunto_2 não existir na lista de conjuntos
                resultado = 2;
            }
            
            if ( conjunto_1 == NULL && conjunto_2 == NULL){
                //Retorna 3 - Quando ambos conjuntos solicitados para uniao pelo usuário não existem
                resultado = 3;
            }
        }


    } else {
        //Retorna 4 - Quando não existir nenhum conjunto na lista de conjuntos
        resultado = 4;        
    }

    return resultado;
}

// 5) - INTERSECÇÃO - FAZ A INTERSECÇÃO DE DOIS CONJUNTOS E RETORNA UM TERCEIRO CONJUNTO
// DEFINIÇÃO: A intersecção de conjuntos corresponde aos elementos que se repetem nos conjuntos dados.
int intersecaoConjuntos(tipo_conjunto* inicio, int id_conjunto, int id_conjunto_2, int* conjunto_intersecao){
    int posicao = 0, resultado;
    tipo_conjunto *atual = inicio, *conjunto_1 = NULL, *conjunto_2 = NULL;

    if( inicio != NULL ){
        
        while( atual != NULL ){
            //ENCONTRA O CONJUNTO INFORMADO PELO USUÁRIO
            if( id_conjunto == posicao ){
                
                conjunto_1 = atual;

            }else if(id_conjunto_2 == posicao){

                conjunto_2 = atual;
            }
            posicao++;
            atual = atual ->proximo;
        }
        //VERIFICA SE OS CONJUNTOS PARA INTERSECÇÃO SOLICITADOS EXISTEM
        if(conjunto_1 != NULL && conjunto_2 != NULL){

            for(int i = 0; i < tamanho; i++){
                
                //VERIFICAÇÃO QUE REALIZA A INTERSECÇÃO DOS CONJUNTOS
                if( conjunto_1 ->valores[i] == 1 && conjunto_2 ->valores[i] == 1 ){
                    conjunto_intersecao[i] = 1;

                }else{
                    conjunto_intersecao[i] = 0;
                }
            }
            //Retorna 0 - Quando tiver sucesso na intersecção
            resultado = 0;
        }else{
            if(conjunto_1 == NULL){
                //Retorna 1 - Quando o id_conjunto não existir na lista de conjuntos
                resultado = 1;
            }else if(conjunto_2 == NULL){
                //Retorna 2 - Quando o id_conjunto_2 não existir na lista de conjuntos
                resultado = 2;
            }
            
            if ( conjunto_1 == NULL && conjunto_2 == NULL){
                //Retorna 3 - Quando ambos conjuntos solicitados para intersecção pelo usuário não existem
                resultado = 3;
            }
        }


    } else {
        //Retorna 4 - Quando não existir nenhum conjunto na lista de conjuntos
        resultado = 4;        
    }

    return resultado;
}

// 6) - DIFERENÇA - FAZ A DIFERENÇA DE DOIS CONJUNTOS E RETORNA UM TERCEIRO CONJUNTO
// DEFINIÇÃO: A diferença de conjuntos é representada pelos elementos de um conjunto que não aparecem no outro conjunto.
//OBS: Dados dois conjuntos A e B, o conjunto diferença é indicado por A - B 
int diferencaConjuntos(tipo_conjunto* inicio, int id_conjunto, int id_conjunto_2, int* conjunto_diferenca){
    int posicao = 0, resultado;
    tipo_conjunto *atual = inicio, *conjunto_1 = NULL, *conjunto_2 = NULL;

    if( inicio != NULL ){
        
        while( atual != NULL ){
            //ENCONTRA O CONJUNTO INFORMADO PELO USUÁRIO
            if( id_conjunto == posicao ){
                
                conjunto_1 = atual;

            }else if(id_conjunto_2 == posicao){

                conjunto_2 = atual;
            }
            posicao++;
            atual = atual ->proximo;
        }
        //VERIFICA SE OS CONJUNTOS PARA DIFERENCIAÇÃO SOLICITADOS EXISTEM
        if(conjunto_1 != NULL && conjunto_2 != NULL){

            for(int i = 0; i < tamanho; i++){
                
                //VERIFICAÇÃO QUE REALIZA A DIFERENÇA DOS CONJUNTOS
                if( conjunto_1 ->valores[i] == 1 && conjunto_2 ->valores[i] == 0 ){
                    conjunto_diferenca[i] = 1;

                }else{
                    conjunto_diferenca[i] = 0;
                }
            }
            //Retorna 0 - Quando tiver sucesso na diferença
            resultado = 0;
        }else{
            if(conjunto_1 == NULL){
                //Retorna 1 - Quando o id_conjunto não existir na lista de conjuntos
                resultado = 1;
            }else if(conjunto_2 == NULL){
                //Retorna 2 - Quando o id_conjunto_2 não existir na lista de conjuntos
                resultado = 2;
            }
            
            if ( conjunto_1 == NULL && conjunto_2 == NULL){
                //Retorna 3 - Quando ambos conjuntos solicitados para diferença pelo usuário não existem
                resultado = 3;
            }
        }


    } else {
        //Retorna 4 - Quando não existir nenhum conjunto na lista de conjuntos
        resultado = 4;        
    }

    return resultado;
}

// 7) - VERIFICA SE O NÚMERO PERTENCE AO CONJUNTO
int elementoPertenceConjunto(tipo_conjunto* inicio, int id_conjunto, int elemento){
    int resultado = 0, posicao = 0;
    tipo_conjunto *atual = inicio, *conjunto = NULL;

    if (inicio != NULL){

        while( atual != NULL ){

            //ENCONTRA O CONJUNTO SOLICITADO PELO USUÁRIO
            if(id_conjunto == posicao){
                
                conjunto = atual;

                for(int i = 0; i < tamanho; i++){

                    //VERIFICA SE O NUMERO EXISTE NO CONJUNTO
                    if ( elemento == i && conjunto -> valores[i] == 1 ){
                        
                        //Retorna 0 - Quando o número existe no conjunto
                        resultado = 1;
                    }
                }

                if( resultado == 0 ){

                    //Retorna -1 - Quando o número não existe no conjunto
                    resultado = -1;
                }
            }
            posicao++;
            atual = atual -> proximo;
        }
        
        //VERIFICA SE O CONJUNTO SOLICITADO PELO USUÁRIO EXISTE
        if (conjunto == NULL){
            //Retorna 2 - Quando o conjunto solicitado não existe na lista de conjuntos
            return 2;
        }
    } else {
        //Retorna 3 - Quando a lista de conjuntos não existi
        resultado = 3;
    }
    
    return resultado;
}

// 8) - MENOR VALOR DE UM CONJUNTO
int menorValor(tipo_conjunto* inicio, int id_conjunto){
    int posicao = 0;
    tipo_conjunto *atual = inicio, *conjunto = NULL;

    if( inicio != NULL ){

        while ( atual != NULL){
            //ENCONTRA O CONJUNTO INFORMADO PELO USUÁRIO
            if( posicao == id_conjunto ){

                conjunto = atual;
                //VERIFICA SE O CONJUNTO NÃO É VAZIO
                if ( conjunto -> tamanho_conjunto > 0 ){

                    for(int i = 0; i < tamanho; i++){

                        if( conjunto -> valores[i] == 1){
                            //Retorna o menor valor - Quando encontra o primeiro valor do vetor
                            return i;
                        }
                    }
                } else {
                    //Retorna -1 - Quando o conjunto está vazio
                    return -1;
                }
                
            }
            atual = atual -> proximo;
        }

        if( conjunto == NULL){
            //Retorna -2 - Quando o conjunto solicitado pelo usuário não existir
            return -2;
        }

    } else {
        //Retorna -3 - Quando a lista de conjuntos não existi
        return -3;
    }
}

// 9) - MAIOR VALOR DE UM CONJUNTO
int maiorValor(tipo_conjunto* inicio, int id_conjunto){
    int posicao = 0;
    tipo_conjunto *atual = inicio, *conjunto = NULL;
    
    if( inicio != NULL ){

        while ( atual != NULL){
            //ENCONTRA O CONJUNTO INFORMADO PELO USUÁRIO
            if( posicao == id_conjunto ){

                conjunto = atual;
                //VERIFICA SE O CONJUNTO NÃO É VAZIO
                if ( conjunto -> tamanho_conjunto > 0 ){

                    for(int i = tamanho - 1; i >= 0; i--){

                        if( conjunto -> valores[i] == 1){
                            //Retorna o maior valor - Quando encontra o ultimo valor do vetor
                            return i;
                        }
                    }
                } else {
                    //Retorna -1 - Quando o conjunto está vazio
                    return -1;
                }
                
            }
            atual = atual -> proximo;
        }

        if( conjunto == NULL){
            //Retorna -2 - Quando o conjunto solicitado pelo usuário não existir
            return -2;
        }

    } else {
        //Retorna -3 - Quando a lista de conjuntos não existi
        return -3;
    }
}

// 10) - TESTA SE DOIS CONJUNTOS SÃO IGUAIS
int verificaIguais(tipo_conjunto* inicio, int id_conjunto, int id_conjunto2){
    int posicao = 0, resultado = 0;
    tipo_conjunto *atual = inicio, *conjunto_1 = NULL, *conjunto_2 = NULL;

    if ( inicio != NULL ){

        while( atual != NULL ){
            //ENCONTRA O CONJUNTO INFORMADO PELO USUÁRIO
            if ( id_conjunto == posicao ){
                conjunto_1 = atual;

            } else if ( id_conjunto2 == posicao ){
                conjunto_2 = atual;
            }
            posicao++;
            atual = atual -> proximo;
        }
        //VERIFICA SE OS DOIS CONJUNTOS NECESSÁRIOS PARA VERIFICAÇÃO FORAM ENCONTRADOS
        if ( conjunto_1 != NULL && conjunto_2 != NULL ){

            for ( int i = 0; i < tamanho; i++ ){

                if ( conjunto_1 -> valores[i] != conjunto_2 -> valores[i] ){
                    //Retorna 0 - Quando 1 elemento do conjunto for diferente, pois já não é igual.
                    return 0;
                }
            }
            //Retorna 1 - Quando os conjuntos forem iguais
            return 1;

        }else{
            if( conjunto_1 == NULL ){
                //Retorna 2 - Quando o primeiro conjunto informado não existe
                resultado = 2;

            }else if ( conjunto_2 == NULL ){
                //Retorna 3 - Quando o segundo conjunto informado não existe
                resultado = 3;

            }else if ( conjunto_1 == NULL && conjunto_2 == NULL){
                //Retorna 4 - Quando ambos conjuntos solicitados pelo usuário não existem
                resultado = 4;
            }
        }

    } else {
        //Retorna 5 - Quando a lista de conjuntos não existi
        return 5;
    }

    return resultado;
    
}

// 11) - TAMANHO DE UM CONJUNTO
int tamanhoConjunto(tipo_conjunto* inicio, int id_conjunto){
    int posicao = 0;
    tipo_conjunto *atual = inicio;

    if( inicio != NULL){

        while ( atual != NULL){
            //ENCONTRA O CONJUNTO INFORMADO PELO USUÁRIO
            if(id_conjunto == posicao){
                //Retorna o Tamanho do Conjunto
                return atual -> tamanho_conjunto;
            }
            posicao++;
            atual = atual -> proximo;
        }
        //Retorna 0 - Quando o conjunto informado não foi encontrado
        return -1;

    } else {
        //Retorna 1 - Quando a lista de conjuntos não existi
        return -2;
    }
}

// 12) - VERIFICA SE O CONJUNTO É VAZIO
int verificaConjuntoVazio(tipo_conjunto* inicio, int id_conjunto){
    int posicao = 0;
    tipo_conjunto *atual = inicio;

    if( inicio != NULL){

        while ( atual != NULL){
            //ENCONTRA O CONJUNTO INFORMADO PELO USUÁRIO
            if(id_conjunto == posicao){
                //VERIFICA SE  CONJUNTO É VAZIO OU NÃO
                if ( atual -> tamanho_conjunto == 0 ){
                    //Retorna 0 - Quando o conjunto é vazio
                    return 0;

                } else {
                    //Retorna 1 - Quando conjunto não é vazio
                    return 1;
                }
            }
            posicao++;
            atual = atual -> proximo;
        }
        //Retorna -1 - Quando o conjunto informado não foi encontrado
        return -1;

    } else {
        //Retorna -2 - Quando a lista de conjuntos não existi
        return -2;
    }
}

// 13) - IMPRIME UM CONJUNTO
int mostrarConjunto(tipo_conjunto* inicio, int id_conjunto, int* vetor_conjunto){
    int posicao = 0;
    tipo_conjunto *atual = inicio;
    
    if( inicio != NULL ){

        while ( atual != NULL ){
            //ENCONTRA O CONJUNTO INFORMADO PELO USUÁRIO
            if ( id_conjunto == posicao ){
                //VERIFICA SE O CONJUNTO NÃO É VAZIO
                if ( atual -> tamanho_conjunto > 0 ){

                    //PREENCHE O VETOR_CONJUNTO NA MAIN PARA SER IMPRESSO
                    for ( int i = 0; i < tamanho; i++){
                        vetor_conjunto[i] = atual -> valores[i];
                    }
                    //Retorna 1  - Informando a Main que o vetor_conjunto já possui o conjunto desejado
                    return 1;
                
                } else {
                    //Retorna 0 - Quando o Conjunto for Vazio
                    return 0;
                }

            }
            posicao++;
            atual = atual -> proximo;
        }
        //Retorna -1 - Quando o conjunto informado não foi encontrado
        return -1;

    } else {
        //Retorna -2 - Quando a lista de conjuntos não existi
        return -2;
    }
}

// 14) - EXTRA - IMPRIME TODOS OS CONJUNTOS
void mostrarTodosConjuntos(tipo_conjunto* inicio){
    int posicao = 0;
    tipo_conjunto *atual = inicio;
    
    if(inicio != NULL){
        
        printf("\n    Lista de Conjuntos:\n\n");
        while(atual != NULL){

            printf("      Posicao: [%d]\n", posicao);
            printf("      Valores do Conjunto:");
            //VERIFICA SE O CONJUNTO É VAZIO
            if(atual -> tamanho_conjunto > 0){

                for(int i = 0; i < tamanho; i++){

                    if(atual -> valores[i] == 1){
                        printf("[ %d ]", i);

                    }
                }
            }else{
                printf("[ Conjunto Vazio ]");
            }

            printf("\n      Tamanho: %d\n\n", atual -> tamanho_conjunto);  

            atual = atual -> proximo;
            posicao++;
        }
        printf("\n\n");

    }else{
        printf("\n    Nao e possivel imprimir, pois nao existe nenhum conjunto!\n\n");
    }
}