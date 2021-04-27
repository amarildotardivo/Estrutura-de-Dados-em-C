#include <stdio.h>
#include<time.h>
#include <stdlib.h>

#define tamanho_vetor 1000
#define range 10000

void insereOrdenado(int vetor[], int valor, int posicao){
    int aux = 0, i = 0;
    
    //Insere o primeiro elemento no vetor
    if(posicao == 0){
        vetor[posicao] = valor;

    }else{
       //verifica a posição onde o valor vai ser inserido no vetor 
       while( ( i < posicao) && (vetor[i] < valor)){
           aux = i;
           i++;
       }

       //Insere quando o valor é menor que a primeira posição 
       if( aux == 0){
           for(int j = posicao; j > i; j--){
               vetor[j] = vetor[j - 1];
           }
           vetor[i] = valor;
       
       //Insere no vetor quanto está na última posição
       }else if(i == posicao){
           vetor[i] = valor;

       //Insere no vetor quando está no meio 
       }else{
           for(int j = posicao; j > i; j--){
               vetor[j] = vetor[j - 1];
           }
           vetor[i] = valor;
       }
    }
}

int verificaIguais(int vetor[], int valor, int posicao){

    for(int i = 0; i < posicao; i++){
        if(vetor[i] == valor){
            //Retorna 0 - Quando os valores se repetem
            return 0;
        }
    }
    //Retorna 1 - Quando os valores não se repetem
    return 1;
}

void aleatoriosDistintos(int vetor[]){
    int valor;

    //Semente aleatória criada;
    srand(time(NULL));

    //Preenchendo o vetor
    for(int i = 0; i < tamanho_vetor; i++){
        valor = rand() % range;
        
        //Verificando se o valor atual é igual a algum valor do vetor
        while( verificaIguais(vetor, valor, i) != 1 ){
            valor = rand() % range;
        }
        
        //Insere ordenadamente os valores no vetor
        insereOrdenado(vetor, valor, i);
    }
}

int buscaBinaria(int vetor[], int esq, int dir, int valor, int comparacoes){
    int i;
    
    if(dir >= esq){
        i = (esq + dir) / 2;
        
        comparacoes++;
        printf("\n  Comparacao: %d", comparacoes);

        if(vetor[i] == valor){
            return i;
        }

        if(vetor[i] > valor){
            return buscaBinaria(vetor, esq, i - 1, valor, comparacoes);

        }else{
            return buscaBinaria(vetor, i + 1, dir, valor, comparacoes);
        }
    }

    return -1;
    
}

int main(){
    int vetor[tamanho_vetor], valor, esq = 0, dir = tamanho_vetor, comparacoes = 0, resultado;

    aleatoriosDistintos(vetor);

    //Mostrando as 1000 posições do vetor
    printf("******************************* VETOR *******************************\n");
    for(int i = 0; i < tamanho_vetor; i++){
        printf(" %d ", vetor[i]);
    }
    printf("\n\n");
    
    printf("\n  Entre com o valor para busca: ");
    scanf("%d", &valor);

    resultado = buscaBinaria(vetor, esq, dir, valor, comparacoes);

    printf("\n  Posicao encontrada foi: %d\n\n", resultado);

    return 0;
}