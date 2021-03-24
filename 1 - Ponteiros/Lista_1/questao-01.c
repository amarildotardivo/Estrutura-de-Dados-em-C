#include <stdio.h>
#include <stdlib.h>

int main (){
    int num, *ptrNum;

    num = 10;
    ptrNum = &num;

    printf("C - Valor de num com ponteiro e: %d \n", *ptrNum);

    printf("D - Endereco de num e: %p e endereco de ptrNum e: %p \n", &num, &ptrNum);

    //*ptrNum = *ptrNum + 1;

    (*ptrNum)++;

    printf("E - Valor de num incrementado por ptrNum: %d \n", *ptrNum);

    printf("F - Novo valor de num e: %d", num);

    return 0;
}