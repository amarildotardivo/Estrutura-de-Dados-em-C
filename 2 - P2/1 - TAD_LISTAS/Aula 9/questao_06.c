#include <stdio.h>
#define tamanho_vetor 5
#define range 5

void insereOrdenado(int vetor[], int valor, int posicao){
    int aux;
    
    if(posicao == 0){
        vetor[posicao] = valor;

    }else{
        for(int i = 1; i < posicao; i++){
            
            if(vetor[i] > valor){
                
                for(int j = posicao; j > i; j--){
                    vetor[j] = vetor[j-1];
                }
                
                vetor[i] = valor;
            }

        }
    }
}

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
        printf(" %d ", valor);
        insereOrdenado(vetor, valor, i);
        //vetor[i] = valor;
    }
}

int buscaBinaria(int vetor[], int esq, int dir, int valor){
    int i;
    
    if(dir >= esq){
        i = esq + (dir - esq) / 2;

        if(vetor[i] == valor){
            return i;
        }

        if(vetor[i] > valor){
            return buscaBinaria(vetor, esq, i - 1, valor);

        }else{
            return buscaBinaria(vetor, i + 1, dir, valor);
        }
    }

    return -1;
    
}

int main(){
    int vetor[tamanho_vetor], valor, esq = 0, dir = tamanho_vetor, *comparacoes = 0, resultado;

    aleatoriosDistintos(vetor);

    //Mostrando as 1000 posições do vetor
    printf("******************************* VETOR *******************************\n");
    for(int i = 0; i < tamanho_vetor; i++){
        printf(" %d ", vetor[i]);
    }
    printf("\n\n");
    
    printf("\n  Entre com o valor para busca: ");
    scanf("%d", &valor);

    resultado = buscaBinaria(vetor, esq, dir, valor);

    printf("\n  Posicao encontrada foi: %d", resultado);

    return 0;
}