#include <stdio.h>
#include <stdlib.h>

int** ordenar(int n, int* vetorInteiro){
    int *w, *aux, menor, maior = 0;

    w = (int *) malloc(n * sizeof (int));

    for (int i = 0; i < n; i++){

            if(vetorInteiro[i] < menor){
                menor = vetorInteiro[i];

            }
            if( vetorInteiro[i] > maior){
                maior = vetorInteiro[i];
            }
    }
    
    printf("O menor e: %d\n", menor);
    printf("O maior e: %d\n", maior);
    
   /* for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            
            if(vetorInteiro[i] > vetorInteiro[j]){
                w[j] = &vetorInteiro[i];

            }else if(vetorInteiro[i] < vetorInteiro[j]){
                w[j] = &vetorInteiro[i];
            }
        }
    }*/

    return w;
}

int main(){
    int n = 4;
    int *vetorInteiro[4] = {0, 3, 2, 1};
    int **w;
    
    printf("VetorInteiro (valores):\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", vetorInteiro[i]);
    }
    printf("\n\n");

    printf("VetorInteiro (enderecos):\n");
    for (int i = 0; i < n; i++)
    {
        printf("%p ", &vetorInteiro[i]);
    }
    printf("\n\n");

    w = ordenar(n, &vetorInteiro);

    printf("Ponteiro W (enderecos):\n");
    for (int i = 0; i < n; i++)
    {
        printf("%p ", w[i]);
    }
    printf("\n\n");
    
}