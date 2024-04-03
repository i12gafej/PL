%{
    #include "impresora.h"
%}
dia [0-2][0-9]|3[0-1]
mes 0[1-9]|1[0-2]
anio [0-9]{4}
hora [0-1][0-9]|2[0-3]
minuto [0-5][0-9]
nombre [a-zA-Z0-9]+\.[a-z]+
%x Q1 Q2 BASURA
%%


{dia}"-"{mes}"-"{anio} {
    int fecha = atoi(eliminar_caracter(yytext, '-', 0));
    int dia = fecha/1000000;
    int mes = (fecha/10000)%100;
    int anio = fecha%10000;
    yymore();
    if((es_bisiesto(anio) == 1 && mes == 2 && dia > 29) || (es_bisiesto(anio) == 0 && mes == 2 && dia > 28)){
        fprintf(yyout, "(X)\tError --> <%s", yytext);
        BEGIN(BASURA);
    }else{
        if(existe_dia(fecha) == -1){ 
            aux = (int*)malloc(sizeof(int));/*Creamos dia auxiliar*/
            *aux = fecha;
        }

        BEGIN(Q1);
    }    
}
. {fprintf(yyout, "(X)\tError --> <%s", yytext);
    codigo_error = 0;
    BEGIN(BASURA);}
<Q1>" "{hora}":"{minuto} {
    yymore();
    BEGIN(Q2);
    
}
<Q1>" "*[^{hora}]":"*[^{minuto}] {
    codigo_error = 1;
    fprintf(yyout, "(X)\tError --> <%s", yytext);
    BEGIN(BASURA);
}
<Q2>" "{nombre} {
    fprintf(yyout, "Nueva impresion aceptada <%s>\n", yytext);
    if(existe_dia(*aux) == -1){
        vector = (int*)realloc(vector, sizeof(int)*(i+1));/*Todo bien, añadimos el ultimo al vector*/
        vector[i] = *aux;
        dias++;
    }
    i++;
    
    BEGIN(INITIAL);
}
<Q2>" "*[^{nombre}] {
    dias--;
    codigo_error = 1;
    fprintf(yyout, "(X)\tError --> <%s", yytext);
    BEGIN(BASURA);
}
<BASURA>.* {
    if(codigo_error == 1){
        free(aux);
    }
    fprintf(yyout, "%s> \n", yytext);
    BEGIN(INITIAL);
}
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
    fprintf(yyout, "\n------------------------------------\n");
    fprintf(yyout, "\nNumero de documentos enviados a la impresora: %d\n\n", i);
    fprintf(yyout, "Numero medio de documentos enviados al dia: %d\n", calcular_media());
    fprintf(yyout, "\n------------------------------------\n");

  return 0;
}
