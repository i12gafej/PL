%{
#include <stdio.h>
#include "token.h"

char* imprimir_cadena_sin_comillas(char *yytext, int yyleng){
    int i;
    char* cadena = (char*)malloc(yyleng-1);
    for(i=1; i<yyleng-1; i++){
        cadena[i-1] = yytext[i];
    }
    cadena[yyleng-2] = '\0';
    return cadena;
}
%}
letra               [a-zA-Z]
ln                  [a-zA-Z0-9]
numero              -?[0-9]+(\.[0-9]+)?([eE][-+]?[0-9]+)?
numero_erroneo      -?[0-9]+(([a-df-zA-DFZ]|((\.\.+)[0-9]|(\.[0-9])(\.[0-9])+))|\.|[eE])
identificador       {letra}({ln}|(_)({ln}))*
error_identificador "_ "|"_\n"|_({ln}|_)*|({ln}*__+{ln}*)|({ln}+_)
espacio             [ \n]
espacios            {espacio}+
cadena              '([^'\\]|\\.)*'
asignacion          :=
asignacionsuma      \+=
asignacionresta     -=
asignacionproducto  \*=
asignaciondivision  \/=
suma                \+
resta               -
producto            \*
division            \/
divisionentera      \/\/
modulo              %
potencia            \*\*
incremento          \+\+
decremento          --
concatenacion       \|\|
menor               <
menorigual          <=
mayor               >
mayorigual          >=
igual               ==
distinto            <>
disyuncion          #o
conjuncion          #y
negacion            #no
comentario_corto    !!.*\n
comentario_largo    ^<<(.*(\n)*)*>>\n
fin_sentencia       ;
parentesis_abierto  \(
parentesis_cerrado  \)
%option case-insensitive

%x C1 C2


%%
\t                          { ;}
{espacios}                  { /* No hacer nada */ ;}
{comentario_corto}          { fprintf(yyout, "\nComentario: %s              \n\t --> token: %d\n", yytext, COMENT); }
"<<"                        { yymore(); BEGIN(C1);}
<C1>[^>]                    { yymore();}
<C1>">"                     { yymore(); BEGIN(C2);}
<C2>[^>]                    { yymore();BEGIN(C1);}
<C2>">"                     { fprintf(yyout, "\nComentario : %s             \n\t --> token: %d\n", yytext, COMENT); BEGIN(0);}
{cadena}                    { fprintf(yyout, "\nCadena: %s                  \n\t --> token: %d\n",imprimir_cadena_sin_comillas(yytext, yyleng), CADENA); }
{asignacion}                { fprintf(yyout, "\nOperador de asignacion: %s  \n\t --> token: %d\n", yytext, ASIGNACION); }
{asignacionsuma}            { fprintf(yyout, "\nOperador de asignacion: %s  \n\t --> token: %d\n", yytext, ASIGNACION_SUMA); }
{asignacionresta}           { fprintf(yyout, "\nOperador de asignacion: %s  \n\t --> token: %d\n", yytext, ASIGNACION_RESTA); }
{asignacionproducto}        { fprintf(yyout, "\nOperador de asignacion: %s  \n\t --> token: %d\n", yytext, ASIGNACION_PRODUCTO); }
{asignaciondivision}        { fprintf(yyout, "\nOperador de asignacion: %s  \n\t --> token: %d\n", yytext, ASIGNACION_DIVISION); }
{suma}                      { fprintf(yyout, "\nOperador aritmetico: %s     \n\t --> token: %d\n", yytext, SUMA);} 
{resta}                     { fprintf(yyout, "\nOperador aritmetico: %s     \n\t --> token: %d\n", yytext, RESTA);}
{producto}                  { fprintf(yyout, "\nOperador aritmetico: %s     \n\t --> token: %d\n", yytext, PRODUCTO);}
{division}                  { fprintf(yyout, "\nOperador aritmetico: %s     \n\t --> token: %d\n", yytext, DIVISION);}
{divisionentera}            { fprintf(yyout, "\nOperador aritmetico: %s     \n\t --> token: %d\n", yytext, DIVISION_ENTERA);}
{modulo}                    { fprintf(yyout, "\nOperador aritmetico: %s     \n\t --> token: %d\n", yytext, MODULO);}
{potencia}                  { fprintf(yyout, "\nOperador aritmetico: %s     \n\t --> token: %d\n", yytext, POTENCIA);}
{incremento}                { fprintf(yyout, "\nOperador aritmetico: %s     \n\t --> token: %d\n", yytext, INCREMENTO);}
{decremento}                { fprintf(yyout, "\nOperador aritmetico: %s     \n\t --> token: %d\n", yytext, DECREMENTO);}
{concatenacion}             { fprintf(yyout, "\nOperador alfanumerico: %s   \n\t --> token: %d\n", yytext, CONCAT);}
{menor}                     { fprintf(yyout, "\nOperador relacional: %s     \n\t --> token: %d\n", yytext, MENOR);}
{menorigual}                { fprintf(yyout, "\nOperador relacional: %s     \n\t --> token: %d\n", yytext, MENORIGUAL);}
{mayor}                     { fprintf(yyout, "\nOperador relacional: %s     \n\t --> token: %d\n", yytext, MAYOR);}
{mayorigual}                { fprintf(yyout, "\nOperador relacional: %s     \n\t --> token: %d\n", yytext, MAYORIGUAL);}
{igual}                     { fprintf(yyout, "\nOperador relacional: %s     \n\t --> token: %d\n", yytext, IGUAL);}
{distinto}                  { fprintf(yyout, "\nOperador relacional: %s     \n\t --> token: %d\n", yytext, DISTINTO);}
{disyuncion}                { fprintf(yyout, "\nOperador logico: %s         \n\t --> token: %d\n", yytext, DISYUNCION);}
{conjuncion}                { fprintf(yyout, "\nOperador logico: %s         \n\t --> token: %d\n", yytext, CONJUNCION);}
{negacion}                  { fprintf(yyout, "\nOperador logico: %s         \n\t --> token: %d\n", yytext, NEGACION);}
{fin_sentencia}             { fprintf(yyout, "\nFIN DE SENTENCIA        \n\t --> token: %d\n", FIN_SENTENCIA); }
{parentesis_abierto}        { fprintf(yyout, "\nParentesis: %s              \n\t --> token: %d\n", yytext, PARENTESIS_ABIERTO); }
{parentesis_cerrado}        { fprintf(yyout, "\nParentesis: %s              \n\t --> token: %d\n", yytext, PARENTESIS_CERRADO); }
inicio                      { fprintf(yyout, "\n-------INICIO DEL PROGRAMA-------\n\t --> token: %d\n",INICIO); }
fin                         { fprintf(yyout, "\n---------FIN DEL PROGRAMA--------\n\t --> token: %d\n", FIN); }
leer                        { fprintf(yyout, "\nPalabra reservada: %s       \n\t --> token: %d\n", yytext, LEER); }
escribir                    { fprintf(yyout, "\nPalabra reservada: %s       \n\t --> token: %d\n", yytext, ESCRIBIR); }
si                          { fprintf(yyout, "\nPalabra reservada: %s       \n\t --> token: %d\n", yytext, SI); }
entonces                    { fprintf(yyout, "\nPalabra reservada: %s       \n\t --> token: %d\n", yytext, ENTONCES); }
si_no                       { fprintf(yyout, "\nPalabra reservada: %s       \n\t --> token: %d\n", yytext, SI_NO); }
fin_si                      { fprintf(yyout, "\nPalabra reservada: %s       \n\t --> token: %d\n", yytext, FIN_SI); }
mientras                    { fprintf(yyout, "\nPalabra reservada: %s       \n\t --> token: %d\n", yytext, MIENTRAS); }
hacer                       { fprintf(yyout, "\nPalabra reservada: %s       \n\t --> token: %d\n", yytext, HACER); }
fin_mientras                { fprintf(yyout, "\nPalabra reservada: %s       \n\t --> token: %d\n", yytext, FIN_MIENTRAS); }
repetir                     { fprintf(yyout, "\nPalabra reservada: %s       \n\t --> token: %d\n", yytext, REPETIR); }
hasta_que                   { fprintf(yyout, "\nPalabra reservada: %s       \n\t --> token: %d\n", yytext, HASTA_QUE); }
para                        { fprintf(yyout, "\nPalabra reservada: %s       \n\t --> token: %d\n", yytext, PARA); }
desde                       { fprintf(yyout, "\nPalabra reservada: %s       \n\t --> token: %d\n", yytext, DESDE); }
hasta                       { fprintf(yyout, "\nPalabra reservada: %s       \n\t --> token: %d\n", yytext, HASTA); }
paso                        { fprintf(yyout, "\nPalabra reservada: %s       \n\t --> token: %d\n", yytext, PASO); }
fin_para                    { fprintf(yyout, "\nPalabra reservada: %s       \n\t --> token: %d\n", yytext, FIN_PARA); }
{numero}                    { fprintf(yyout, "\nNumero: <%s>                \n\t --> token: %d\n", yytext, NUMERO);}
{numero_erroneo}            { fprintf(yyout, "\nNumero erroneo\n");}
{identificador}             { fprintf(yyout, "\nIdentificador: <%s>         \n\t --> token: %d\n", yytext, IDENTIFICADOR);}
{error_identificador}       { fprintf(yyout, "\nError de identificador: %s\n", yytext); }
.                           { fprintf(yyout, "\nCaracter no reconocido: %s\n", yytext); }
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

    return 0;
}