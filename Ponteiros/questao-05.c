#include <stdio.h>
#include <stdlib.h>

int** ordenar(int n, int *vetorInteiro){
    int *w, *aux;

    w = (int *) malloc(n * sizeof (int));

    for(int i = 0; i < n; i++){
        w[i] = &vetorInteiro[i];
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n - 1; j++){
            
            if(w[j] > w[j + 1]){
                aux = w[j];
                w[j] = w[j + 1];
                w[j + 1] = aux;
            }
        }
    }

    return w;
}

int main(){
    int n = 4;
    int *vetorInteiro[4] = {4, 3, 2, 1};
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

    w = ordenar(n, vetorInteiro);

    printf("Ponteiro W (enderecos):\n");
    for (int i = 0; i < n; i++)
    {
        printf("%p ", w[i]);
    }
    printf("\n\n");
    
}