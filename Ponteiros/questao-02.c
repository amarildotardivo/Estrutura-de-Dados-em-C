#include <stdio.h>
#include <stdlib.h>

int main (){
    int num1 = 100, num2 = 15, *ptrNum1, *ptrNum2;

    ptrNum1 = &num1;
    ptrNum2 = &num2;

    if(*ptrNum2 > *ptrNum1){
        printf("num2 e maior que num1!");
    }else{
        printf("num1 e maior que num2!");
    }

    return 0;
}