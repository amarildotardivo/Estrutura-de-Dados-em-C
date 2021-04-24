#include <stdio.h>

int fibonacci(int n){
    int resultado, resultado_esq, resultado_dir;

    if( n <= 2){
        return 1;
    
    }else{
        resultado_esq = fibonacci(n - 1);
        resultado_dir = fibonacci(n - 2);
        resultado = resultado_esq + resultado_dir;
    }
    
    return resultado;
}

int main(){
    int n, resultado;

    printf("\n  Entre com o termo a ser buscado: ");
    scanf("%d", &n);

    resultado = fibonacci(n);

    printf("\n  O %d elemento e: %d\n\n", n, resultado);
    
    return 0;
}