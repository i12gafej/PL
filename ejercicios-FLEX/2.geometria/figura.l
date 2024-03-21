%{
#include <stdio.h>
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




%}

numero  (0|[1-9][0-9]*)\.(0|[0-9]*[1-9])
coord   \({numero}" "{numero}\)
trian   tri(á|a)ngulo" "{coord}" "{coord}" "{coord}
cuad    cuadrado" "{coord}" "{coord}
circulo c(i|í)rculo" "{coord}" "{numero}
/**triangulo (0.0 0.0) (4.0 0.0) (0.0 3.0)*/
%%

{trian} { 
            Punto p1, p2, p3;
            if(yytext[3] == 'á'){yytext[3] = 'a';}
            sscanf(yytext, "triangulo (%f %f) (%f %f) (%f %f)", &p1.x, &p1.y, &p2.x, &p2.y, &p3.x, &p3.y);
            float area = calcularAreaTriangulo(p1, p2, p3);
            float perimetro = calcularPerimetroTriangulo(p1, p2, p3);
            printf("Triángulo: Área = %.2f\n", area);
            printf("Triángulo: Perímetro = %.2f\n", perimetro);
            triangulos++;
        }
{cuad} { 
            Punto p1, p2;
            sscanf(yytext, "cuadrado (%f %f) (%f %f)", &p1.x, &p1.y, &p2.x, &p2.y);
            float area = distancia(p1, p2) * distancia(p1, p2);
            float perimetro = 4 * distancia(p1, p2);
            printf("Cuadrado: Área = %.2f\n", area);
            printf("Cuadrado: Perímetro = %.2f\n", perimetro);
            cuadrados++;
        }
{circulo} { 
            Punto centro;
            float radio;
            if(yytext[1] == 'í'){yytext[1] = 'i';}
            sscanf(yytext, "circulo (%f %f) %f", &centro.x, &centro.y, &radio);
            float area = PI * radio * radio;
            float perimetro = 2 * PI * radio;
            printf("Círculo: Área = %.2f\n", area);
            printf("Círculo: Perímetro = %.2f\n", perimetro);
            circulos++;
        }
        
# {return 0;}
.* { printf("Error\n");}




%%

extern FILE *yyin, *yyout;

int main(int argc, char *argv[])
{
 
    switch(argc)/*Comprobar que el fichero de entrada existe*/
    {
    case 2:  yyin=fopen(argv[1],"r"); 
                break;
    case 3:  yyin=fopen(argv[1],"r"); 
                yyout=fopen(argv[2],"w"); 
    }

    yylex();

    printf("Número de triángulos: %d\n", triangulos);
    printf("Número de cuadrados: %d\n", cuadrados);
    printf("Número de círculos: %d\n", circulos);

  

  return 0;
}