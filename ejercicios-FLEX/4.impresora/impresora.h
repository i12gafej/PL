#ifndef IMPRESORA_H
#define IMPRESORA_H

#include <stdio.h>
#include <stdlib.h>

/*DECLARACION DE VARIABLES GLOBALES*/
int *vector = NULL; /*Vector de Dias*/
int *aux = NULL; /*Variable auxiliar para almacenar los datos*/
int i = 0; /*numero de dias almacenados*/
int dias = 0; /*Numero de dias*/
int codigo_error; /*Cuando sea antes de entrar en Q1 se guarda como 0, si no 1*/

int calcular_media(){
    return i/dias;
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
        if(vector[j] == dia){
            return j;
        }
    }
    return -1;
}

#endif