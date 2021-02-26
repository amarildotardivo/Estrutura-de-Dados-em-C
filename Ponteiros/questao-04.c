#include <stdio.h>
#include <stdlib.h>


int* somatorio(int n, int *v){
    int *w;

    w = (int *) malloc(n * sizeof (int));

    w[0] = v[0];
    printf("teste inicial: %d\n", w[0]);

     for(int i = 0; i < n; i++){
         if(i > 0){
            w[i] = v[i] + w[i - 1];
         }
     }

    for(int i = 0; i < n; i++){
        printf("%d ", w[i]);

    }

    return 0;
}

int main (){
    int  n = 4, v[n];

    for(int i = 0; i < n; i++){
        printf("Entre com o %d valor: ", i + 1);
        scanf("%d", &v[i]);
    }

    somatorio(n, v);

    return 0;
}