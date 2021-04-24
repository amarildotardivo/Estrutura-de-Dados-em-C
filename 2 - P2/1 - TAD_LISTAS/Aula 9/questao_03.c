#include <stdio.h>


int somaVetor(int vetor[], int tamanho_vetor){
    int soma;

    if(tamanho_vetor == 1){

        return vetor[0];

    }else{
        return vetor[tamanho_vetor - 1] + somaVetor(vetor, tamanho_vetor - 1);
    }

}

int main(){
    int tamanho_vetor = 5;
    int vetor[5] = {1, 2, 3, 4, 5}, soma;

    soma = somaVetor(vetor, tamanho_vetor);

    printf("\n  A soma foi: %d", soma);

    return 0;
}