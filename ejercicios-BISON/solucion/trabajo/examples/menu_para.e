!! Programa para bucle con opciones de incremento

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

repetir

    borrar_pantalla;
    lugar(10,10);
    escribir('Introduce el valor inicial del bucle: ');
    leer(valor_inicial);

    lugar(11,10);
    escribir('Introduce el valor final del bucle: ');
    leer(valor_final);

    lugar(12,10);
    escribir('¿Desea incremento en el bucle? (si/no): ');
    leer_cadena(incremento);

    si (incremento = 'si')
        entonces
            lugar(13,10);
            escribir('Introduce el valor de incremento: ');
            leer(valor_incremento);
            posicion := 15;
            para i desde valor_inicial hasta valor_final paso valor_incremento hacer
                lugar(posicion, 4);
                escribir('Valor de i: ');
                lugar(posicion-2, 20);
                escribir(i);
                posicion+:=2;
            fin_para;
    si_no
        posicion := 15;
        para i desde valor_inicial hasta valor_final hacer
            lugar(posicion, 4);
            escribir('Valor de i: ');
            lugar(posicion-2, 20);
            escribir(i);
            posicion+:=2;
        fin_para;
    fin_si;

    lugar(17,10);
    escribir('¿Desea realizar otro bucle? (si/no): ');
    leer_cadena(respuesta);

hasta (respuesta = 'no');

!! Despedida final
borrar_pantalla;
lugar(10,10);
escribir('El programa ha concluido. \n');
