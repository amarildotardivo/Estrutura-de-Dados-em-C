#include <stdio.h>
#define tamanho_vetor 5

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
    int vetor[tamanho_vetor] = {1, 2, 3, 4, 5}, valor, esq = 0, dir = tamanho_vetor, *comparacoes = 0, resultado;

    printf("\n  Entre com o valor para busca: ");
    scanf("%d", &valor);

    resultado = buscaBinaria(vetor, esq, dir, valor);

    printf("\n  Posicao encontrada foi: %d", resultado);
    
    return 0;
}