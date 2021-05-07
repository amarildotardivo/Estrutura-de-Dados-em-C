#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define tamanho 10
#define range 201

int main(){
    int elemento[tamanho];

    srand(280);

    for(int i = 0; i < tamanho; i++){
        elemento[i] = rand() % range + 1;
    }

    //NUMEROS GERADOS
    //149 5 55 12 25 87 146 91 142 190
    printf("\n\n");
    printf("\nAmarildo: 201621200280\n\n");
    for(int i = 0; i < tamanho; i++){
        printf(" %d - %p\n\n", elemento[i], &elemento[i]);
    }
    printf("\n\n");

    /* 
    
    149 - 0061FEF0

    5 - 0061FEF4

    55 - 0061FEF8

    12 - 0061FEFC

    87 - 0061FF00

    190 - 0061FF04

    146 - 0061FF08

    91 - 0061FF0C

    142 - 0061FF10

    25 - 0061FF14
    
    */
    

    return 0;
}