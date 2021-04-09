#include <stdio.h>
#include <stdlib.h>

int maiorValor(int *ponteiro1, int *ponteiro2){
     
     if(ponteiro1 > ponteiro2){
        printf("num1 e maior que num2!");
    }else{
        printf("num2 e maior que num1!");
    }
}

int main (){
    int num1 = 100, num2 = 105;

    maiorValor(num1, num2);

    return 0;
}