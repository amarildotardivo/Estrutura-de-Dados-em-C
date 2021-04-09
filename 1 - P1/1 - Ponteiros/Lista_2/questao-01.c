#include <stdio.h>
#include <stdlib.h>

void trocarValores(int* var_inteira1, int* var_inteira2){
    int aux;

    aux = *var_inteira1;
    *var_inteira1 = *var_inteira2;
    *var_inteira2 = aux;

}

int main(){
    int v1 = 1, v2 = 2;
    
    printf("ANTES DA TROCA:\n");
    printf("Variavel 1: %d\n", v1);
    printf("Variavel 2: %d\n\n", v2);

    trocarValores(&v1, &v2);

    printf("DEPOIS DA TROCA:\n");
    printf("Variavel 1: %d\n", v1);
    printf("Variavel 2: %d\n\n", v2);

    return 0;
}