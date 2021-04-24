#include <stdio.h>

int fatorial(int numero){
    int resultado_fatorial;

    if(numero == 0){
        return 1;
    
    }else{
        resultado_fatorial = numero * fatorial(numero - 1);
    }

    return resultado_fatorial;

}

int main(){
    int numero, resultado;

    printf("\n  Entre com um numero inteiro: ");
    scanf("%d", &numero);

    resultado = fatorial(numero);

    printf("\n  O Fatorial do %d e: %d\n\n", numero, resultado);

    return 0;
}