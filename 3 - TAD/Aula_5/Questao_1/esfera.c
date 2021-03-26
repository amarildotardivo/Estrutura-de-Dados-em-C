#include <math.h>

#define PI 3.14

struct esfera
{
    float diametro, raio, area, volume;
};

typedef struct esfera tipo_esfera;

float calculaRaio(float diametro){
    tipo_esfera novo;

    novo.raio = diametro / 2; 

    return novo.raio;
}

float calculaArea(float raio){
    tipo_esfera novo;

    novo.area =  4 * PI * pow(raio, 2);

    return novo.area;
}

float calculaVolume(float raio){
    tipo_esfera novo;

    novo.volume = 4 * PI * pow(raio, 3)/ 3;

    return novo.volume;
}
