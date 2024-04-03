%{
#include <stdio.h>
#include <math.h>
#include "figura.h"
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
            fprintf(yyout, "Triángulo: Área = %.2f\n", area);
            fprintf(yyout, "Triángulo: Perímetro = %.2f\n", perimetro);
            triangulos++;
        }
{cuad} { 
            Punto p1, p2;
            sscanf(yytext, "cuadrado (%f %f) (%f %f)", &p1.x, &p1.y, &p2.x, &p2.y);
            float area = distancia(p1, p2) * distancia(p1, p2);
            float perimetro = 4 * distancia(p1, p2);
            fprintf(yyout, "Cuadrado: Área = %.2f\n", area);
            fprintf(yyout, "Cuadrado: Perímetro = %.2f\n", perimetro);
            cuadrados++;
        }
{circulo} { 
            Punto centro;
            float radio;
            if(yytext[1] == 'í'){yytext[1] = 'i';}
            sscanf(yytext, "circulo (%f %f) %f", &centro.x, &centro.y, &radio);
            float area = PI * radio * radio;
            float perimetro = 2 * PI * radio;
            fprintf(yyout, "Círculo: Área = %.2f\n", area);
            fprintf(yyout, "Círculo: Perímetro = %.2f\n", perimetro);
            circulos++;
        }
        
# {return 0;}
.* { fprintf(yyout, "Error de formato\n\n");}




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

    fprintf(yyout, "\n\nNúmero de triángulos: %d\n", triangulos);
    fprintf(yyout, "Número de cuadrados: %d\n", cuadrados);
    fprintf(yyout, "Número de círculos: %d\n", circulos);

  

  return 0;
}