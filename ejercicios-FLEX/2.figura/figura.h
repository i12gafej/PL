#ifndef FIGURA_H
#define FIGURA_H


#include <math.h>
#define PI 3.1416
typedef struct {
    float x;
    float y;
} Punto;

int triangulos = 0; 
int cuadrados = 0;
int circulos = 0;

float distancia(Punto p1, Punto p2) {
    return sqrt(pow(p2.x - p1.x, 2) + pow(p2.y - p1.y, 2));
}


float calcularAreaTriangulo(Punto p1, Punto p2, Punto p3) {
    float lado1 = distancia(p1, p2);
    float lado2 = distancia(p2, p3);
    float lado3 = distancia(p3, p1);
    float s = (lado1 + lado2 + lado3) / 2; 
    return sqrt(s * (s - lado1) * (s - lado2) * (s - lado3));
}


float calcularPerimetroTriangulo(Punto p1, Punto p2, Punto p3) {
    float lado1 = distancia(p1, p2);
    float lado2 = distancia(p2, p3);
    float lado3 = distancia(p3, p1);
    return lado1 + lado2 + lado3;
}

#endif