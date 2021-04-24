#include <stdio.h>
#define tamanho_vetor 1000
#define range 10000

int verificaIguais(int vetor[], int valor){

    for(int i = 0; i < tamanho_vetor; i++){
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

    //Preenchendo o vetor com 1000 numeros aleatórios
    for(int i = 0; i < tamanho_vetor; i++){
        valor = rand() % range;

        while( verificaIguais(vetor, valor) != 1 ){
            valor = rand() % range;
        }

        vetor[i] = valor;
    }
}

int main(){
    int vetor[tamanho_vetor];

    aleatoriosDistintos(vetor);

    //Mostrando as 1000 posições do vetor
    printf("******************************* VETOR *******************************\n");
    for(int i = 0; i < tamanho_vetor; i++){
        printf(" %d ", vetor[i]);
    }
    printf("\n\n");
    
    return 0;
}