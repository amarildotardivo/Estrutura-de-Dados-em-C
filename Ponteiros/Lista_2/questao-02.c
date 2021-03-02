#include <stdio.h>
#include <stdlib.h>

int* somatorio(int n, int* v){
    int *w;

    w = (int *) malloc(n * sizeof (int));

    w[0] = v[0];
    printf("Ponteiro W[0]: %d\n\n", w[0]);

     for(int i = 0; i < n; i++){
         if(i > 0){
            w[i] = v[i] + w[i - 1];
         }
     }

    return w;
}

int main (){
    int n = 4;
    int v[4] = {1, 2, 3, 4};
    int *w;

    printf("Vetor V:\n");
    for (int i = 0; i < n; i++)
    {
        printf(" %d ", v[i]);
    }
    printf("\n\n");
    
    w = somatorio(n, v);

    printf("Ponteiro W:\n");
    for(int i = 0; i < n; i++){
        printf(" %d ", w[i]);

    }
    printf("\n\n");

    return 0;
}