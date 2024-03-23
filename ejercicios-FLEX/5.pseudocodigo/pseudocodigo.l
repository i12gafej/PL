%{
#include <stdio.h>
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
letra          [a-zA-Z]
ln             [a-zA-Z0-9]
numero         -?[0-9]+(\.[0-9]+)?([eE][-+]?[0-9]+)?
numero_erroneo -?[0-9]+(([a-df-zA-DFZ]|((\.\.+)[0-9]|(\.[0-9])(\.[0-9])+))|\.|[eE])
identificador  {letra}({ln}|(_)({ln}))*
espacio        [ \n]
espacios       {espacio}+
cadena         '([^'\\]|\\.)*'
asignacion         =
asignacionsuma     \+=
asignacionresta    -=
asignacionproducto \*=
asignaciondivision \/=
suma            \+
resta           -
producto        \*
division        \/
divisionentera  \/\/
modulo          %
potencia        \*\*
incremento      \+\+
decremento      --
concatenacion   \|\|
menor           <
menorigual      <=
mayor           >
mayorigual      >=
igual           ==
distinto        <>
disyuncion      #o
conjuncion      #y
negacion        #no
comentario_corto      !!.*\n
comentario_largo      ^<<(.*(\n)*)*>>\n
fin_sentencia  ;
parentesis_abierto  \(
parentesis_cerrado  \)
%option case-insensitive

%x LB C1 C2


%%
\t                          { fprintf(yyout, "\t");}
{espacios}      { /* No hacer nada */ ;}
{comentario_corto}            { fprintf(yyout, "Comentario corto: %s\n", yytext); }
"<<"                    { yymore(); BEGIN(C1);}
<C1>[^>]                { yymore();}
<C1>">"                 { yymore(); BEGIN(C2);}
<C2>[^>]                { yymore();BEGIN(C1);}
<C2>">"                 { fprintf(yyout, "Comentario largo: \"%s\"\n", yytext);yymore(); BEGIN(0);}
{cadena}                { fprintf(yyout, "Cadena: <%s>\n",imprimir_cadena_sin_comillas(yytext, yyleng)); }
{asignacion}            { fprintf(yyout, "Asignacion: %s\n", yytext); }
{asignacionsuma}        { fprintf(yyout, "Asignacion suma: %s\n", yytext); }
{asignacionresta}       { fprintf(yyout, "Asignacion resta: %s\n", yytext); }
{asignacionproducto}    { fprintf(yyout, "Asignacion producto: %s\n", yytext); }
{asignaciondivision}    { fprintf(yyout, "Asignacion division: %s\n", yytext); }
{suma}            {fprintf(yyout, "Suma\n");}
{resta}           {fprintf(yyout, "Resta\n");}
{producto}        {fprintf(yyout, "Producto\n");}
{division}        {fprintf(yyout, "División\n");}
{divisionentera}  {fprintf(yyout, "División entera\n");}
{modulo}          {fprintf(yyout, "Módulo\n");}
{potencia}        {fprintf(yyout, "Potencia\n");}
{incremento}      {fprintf(yyout, "Incremento\n");}
{decremento}      {fprintf(yyout, "Decremento\n");}
{concatenacion}   {fprintf(yyout, "Concatenación\n");}
{menor}           {fprintf(yyout, "Menor\n");}
{menorigual}      {fprintf(yyout, "Menor o igual\n");}
{mayor}           {fprintf(yyout, "Mayor\n");}
{mayorigual}      {fprintf(yyout, "Mayor o igual\n");}
{igual}           {fprintf(yyout, "Igual\n");}
{distinto}        {fprintf(yyout, "Distinto\n");}
{disyuncion}      {fprintf(yyout, "Disyunción\n");}
{conjuncion}      {fprintf(yyout, "Conjunción\n");}
{negacion}        {fprintf(yyout, "Negación\n");}
{fin_sentencia}         { fprintf(yyout, "Fin de sentencia\n"); }
{parentesis_abierto}    { fprintf(yyout, "Parentesis abierto\n"); }
{parentesis_cerrado}    { fprintf(yyout, "Parentesis cerrado\n"); }
inicio          { fprintf(yyout, "Palabra reservada: inicio\n"); }
fin             { fprintf(yyout, "Palabra reservada: fin\n"); }
leer            { fprintf(yyout, "Palabra reservada: leer\n"); }
escribir        { fprintf(yyout, "Palabra reservada: escribir\n"); }
si              { fprintf(yyout, "Palabra reservada: si\n"); }
entonces        { fprintf(yyout, "Palabra reservada: entonces\n"); }
si_no           { fprintf(yyout, "Palabra reservada: si_no\n"); }
fin_si          { fprintf(yyout, "Palabra reservada: fin_si\n"); }
mientras        { fprintf(yyout, "Palabra reservada: mientras\n"); }
hacer           { fprintf(yyout, "Palabra reservada: hacer\n"); }
fin_mientras    { fprintf(yyout, "Palabra reservada: fin_mientras\n"); }
repetir         { fprintf(yyout, "Palabra reservada: repetir\n"); }
hasta_que       { fprintf(yyout, "Palabra reservada: hasta_que\n"); }
para            { fprintf(yyout, "Palabra reservada: para\n"); }
desde           { fprintf(yyout, "Palabra reservada: desde\n"); }
hasta           { fprintf(yyout, "Palabra reservada: hasta\n"); }
paso            { fprintf(yyout, "Palabra reservada: paso\n"); }
fin_para        { fprintf(yyout, "Palabra reservada: fin_para\n"); }
{numero}            { fprintf(yyout, "Numero: <%s>\n", yytext);}
{numero_erroneo}    {fprintf(yyout, "Numero erroneo\n");}
{letra}({ln}|(_)({ln}))*    { fprintf(yyout, "Identificador: %s\n", yytext);}
[_]                         { yymore(); BEGIN(LB);}
<LB>({ln}|_)*               { fprintf(yyout, "Error de identificador: %s\n", yytext);BEGIN(0);}
.                           { fprintf(yyout, "Caracter no reconocido: %s\n", yytext); }
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