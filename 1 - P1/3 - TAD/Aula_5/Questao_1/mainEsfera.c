#include "esfera.h"

int main(){
    float diametro, raio, area, volume;

    printf("Entre com o Diametro da Esfera: ");
    scanf("%f", &diametro);

    raio = calculaRaio(diametro);
    printf("\n    O Raio da Esfera e: %.2f\n\n", raio);
    
    area = calculaArea(raio);
    printf("    A Area da Esfera e: %.2f\n\n", area);
    
    volume = calculaVolume(raio);
    printf("    O Volume da Esfera e: %.2f\n\n", volume);

    return 0;
}
