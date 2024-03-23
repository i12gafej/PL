%{
    #include <stdio.h>

    typedef struct{
        int dia;
        int veces;
        int hora;
    } Stat;   


    /*DECLARACION DE VARIABLES GLOBALES*/
    Stat *vector = NULL; /*Vector de Dias*/
    Stat *aux = NULL; /*Variable auxiliar para almacenar los datos*/
    int i = 0; /*numero de dias almacenados*/
    int dias = 0; /*Numero de dias*/
    int codigo_error; /*Cuando sea antes de entrar en Q1 se guarda como 0, si no 1*/

    int calcular_media(){
        int media = 0;
        int t=0;
        for(; t < dias; t++){
            media += vector[t].veces;
        }
        return media/dias;
    }

    int es_bisiesto(int year) {
        if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
            return 1;
        else
            return 0;
    }
    char* eliminar_caracter(char* cadena, char caracter, int posicion) {
        char* nueva_cadena = (char*)malloc(sizeof(char));
        int it = posicion;
        int j = 0;
        while (cadena[it] != '\0') {
            if (cadena[it] != caracter) {
                nueva_cadena[j] = cadena[it];
                j++;
                nueva_cadena = (char*)realloc(nueva_cadena, sizeof(char) * (j + 1));
            }
            it++;
        }
        nueva_cadena[j] = '\0';
        return nueva_cadena;
    } 
    int existe_dia(int dia){
        int j = 0;
        for(j = 0; j < i; j++){
            if(vector[j].dia == dia){
                return j;
            }
        }
        return -1;
    }
    int comprobar_hora(Stat auxiliar){
        int t;
        for(t = 0; t < i; t++){
            if(vector[t].dia == auxiliar.dia){
                if(auxiliar.hora >= vector[t].hora){
                    vector[t].hora = auxiliar.hora;
                    return 1;
                }
            }
        }
        return -1;
    }
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
    if(es_bisiesto(anio) == 1 && mes == 2 && dia > 29){
        printf("Error de fecha\n");
        BEGIN(BASURA);
    }else if(es_bisiesto(anio) == 0 && mes == 2 && dia > 28){
        printf("Error de fecha\n");
        BEGIN(BASURA);
    }else{
        if(existe_dia(fecha) == -1){ 
            aux = (Stat*)malloc(sizeof(Stat));/*Creamos dia auxiliar*/
            aux->dia = fecha;
            aux->veces = 1;/*Guardamos valores*/
        }
        yymore();
        BEGIN(Q1);
    }    
}
. {printf("Error\n");
    codigo_error = 0;
    BEGIN(BASURA);}
<Q1>" "{hora}":"{minuto} {
    if(existe_dia(aux->dia) == -1){
        /*Si no existe el dia, solo lo guardamos*/
        aux->hora = atoi(eliminar_caracter(yytext, ':', 11));
        yymore();
        BEGIN(Q2);
    }else{
        /*Si existe el dia, lo comprobamos*/
        aux->hora = atoi(eliminar_caracter(yytext, ':', 11));
        if(comprobar_hora(*aux) == -1){
            printf("Error de hora\n");
            BEGIN(BASURA);
        }else{
            yymore();
            BEGIN(Q2);
        }
    }
    
}
<Q1>" "*[^{hora}]":"*[^{minuto}] {
    codigo_error = 1;
    printf("Error de hora\n");
    BEGIN(BASURA);
}
<Q2>" "{nombre} {
    printf("Nueva impresion aceptada <%s>\n", yytext);
    if(existe_dia(aux->dia) == -1){
        vector = (Stat*)realloc(vector, sizeof(Stat)*(i+1));/*Todo bien, añadimos el ultimo al vector*/
        vector[i] = *aux;
        dias++;
        
    }else{
        vector[existe_dia(aux->dia)].veces++;
    }
    i++;
    
    BEGIN(INITIAL);
}
<Q2>" "*[^{nombre}] {
    dias--;
    codigo_error = 1;
    printf("Error de nombre\n");
    BEGIN(BASURA);
}
<BASURA>.* {
    if(codigo_error == 1){
        free(aux);
    }
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
    printf("\n------------------------------------\n");
    printf("               IMPRESORA\n");
    printf("------------------------------------\n\n");
    yylex();
    printf("\n------------------------------------\n");
    printf("\nNumero de documentos enviados a la impresora: %d\n\n", i);
    printf("Numero medio de documentos enviados al dia: %d\n", calcular_media());
    printf("\n------------------------------------\n");

  return 0;
}