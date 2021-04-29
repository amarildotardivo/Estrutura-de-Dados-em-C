#include <stdio.h>

#define tam 5

int forRecursivo(int n){

    if(n > tam){
        return 0;

    }else{
        return n + forRecursivo(n + 1);
    }

   
}

int main(){
    int n = 1, tamanho = tam;
    
    int resul = forRecursivo(n);

    printf("\n  Resultado: %d", resul);

    return 0;
}