!! Programa principal con menús unificados

borrar_pantalla;
lugar(10,10);
escribir('Introduce tu nombre --> ');
leer_cadena(nombre);

borrar_pantalla;
lugar(10,10);
escribir('  Intérprete de pseudocódigo: \'ipe.exe\'.');
escribir('\n Bienvenido/a \t ');
escribir(nombre);

lugar(40,10);
escribir('Pulsa una tecla para continuar');
leer_cadena(pausa);

borrar_pantalla;

repetir
    borrar_pantalla;
    lugar(10,10);
    escribir('Introduce el valor inicial del bucle: ');
    leer(valor_inicial);

    lugar(11,10);
    escribir('Introduce el valor final del bucle: ');
    leer(valor_final);

    lugar(12,10);
    escribir('¿Desea especificar un incremento? (si/no): ');
    leer_cadena(incremento);

    posicion := 15;

    si (incremento = 'si') entonces
        lugar(13,10);
        escribir('Introduce el valor de incremento: ');
        leer(valor_incremento);

        si (((valor_inicial < valor_final) #y (valor_incremento < 0)) #o ((valor_inicial > valor_final) #y (valor_incremento > 0))) entonces
            lugar(15,10);
            escribir('Error: El incremento genera un bucle infinito.');
        si_no
            i := valor_inicial;
            hacer
                lugar(posicion, 4);
                escribir('Valor de i: ');
                lugar(posicion, 17);
                posicion++;
                escribir(i);
                i := i + valor_incremento;
            mientras (((valor_inicial < valor_final) #y (i <= valor_final)) #o ((valor_inicial > valor_final) #y (i >= valor_final)));
        fin_si;
    si_no
        si (valor_inicial < valor_final) entonces
            i := valor_inicial;
            hacer
                lugar(posicion, 4);
                escribir('Valor de i: ');
                lugar(posicion, 17);
                posicion++;
                escribir(i);
                i := i + 1;
            mientras (i <= valor_final);
        si_no
            si (valor_inicial > valor_final) entonces
                i := valor_inicial;
                hacer
                    lugar(posicion, 4);
                    escribir('Valor de i: ');
                    lugar(posicion, 17);
                    posicion++;
                    escribir(i);
                    i := i - 1;
                mientras (i >= valor_final);
            fin_si;
        fin_si;
    fin_si;

    lugar(25,10);
    escribir('Pulsa una tecla para continuar --> ');
    leer_cadena(pausa);
hasta (opcion_hacer = 0);

lugar(30,10);
escribir('Pulsa una tecla para continuar --> ');
leer_cadena(pausa);

!! Despedida final
borrar_pantalla;
lugar(10,10);
escribir('El programa ha concluido. \n');
