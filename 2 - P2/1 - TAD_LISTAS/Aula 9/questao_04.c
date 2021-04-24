#include <stdio.h>

int somaN(int n){

    if(n == 1){
        return 1;

    }else{

        return n + somaN(n - 1);
    }
}

int main(){
    int n = 10, soma;

    soma = somaN(n);

    printf("\n  A soma do numero %d e: %d", n, soma);
    
    return 0;
}