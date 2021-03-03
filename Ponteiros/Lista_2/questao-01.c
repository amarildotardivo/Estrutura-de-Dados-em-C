#include <stdio.h>
#include <stdlib.h>

int** trocarValores(int* var_inteira1, int* var_inteira2){
    int **ponteiro, *aux;
    ponteiro = (int *) malloc(2 * sizeof(int*));

    ponteiro[0] = var_inteira1;
    ponteiro[1] = var_inteira2;

    var_inteira1 = *ponteiro[1];
    var_inteira2 = *ponteiro[0];
    
    /*aux = ponteiro[0];
    ponteiro[0] = ponteiro[1];
    ponteiro[1] = aux;*/

    printf("Dentro da funcao\n");
    printf("Variavel 1: %d\n", var_inteira1);
    printf("Variavel 2: %d\n\n", var_inteira2);

    return ponteiro;

}

int main(){
    int v1 = 1, v2 = 2, **p;
    
    p = trocarValores(&v1, &v2);

    printf("Variavel 1: %d\n", v1);
    printf("Variavel 2: %d\n\n", v2);

    for(int i = 0; i < 2; i++){
        printf("valor %d: %d\n", i + 1, *p[i]);
    }

    free(p);
    p = NULL;

    return 0;
}