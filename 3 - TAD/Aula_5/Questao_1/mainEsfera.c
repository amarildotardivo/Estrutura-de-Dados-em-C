#include "esfera.h"

int main(){
    float diametro, raio, area, volume;

    printf("Entre com o Diametro da Esfera: ");
    scanf("%f", &diametro);

    raio = calculaRaio(diametro);
    printf("O Raio da Esfera e: %.2f", raio);

    return 0;
}