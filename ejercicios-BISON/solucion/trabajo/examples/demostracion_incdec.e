!! Programa de demostración de preincremento, postincremento, predecremento y postdecremento

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
    escribir(' Menú de opciones ');
    lugar(12,10);
    escribir(' 1. Incremento ');
    lugar(13,10);
    escribir(' 2. Decremento ');
    lugar(14,10);
    escribir(' 0. Salir ');

    lugar(16,10);
    escribir(' Elige una opción: ');
    leer(opcion);

    borrar_pantalla;

    si (opcion = 1)
        entonces
            !! Inicializar variables
            var1 := 2;
            var2 := 2;

            lugar(10,10);
            escribir('Valores iniciales: ');
            lugar(11,10);
            escribir('var1: ');
            lugar(11,20);
            escribir(var1);
            lugar(12,10);
            escribir('var2: ');
            lugar(12,20);
            escribir(var2);

            !! Preincremento
            var1 := ++var2;
            lugar(14,10);
            escribir('Después de asignación con preincremento (var1 := ++var2): ');
            lugar(15,10);
            escribir('var1: ');
            lugar(15,20);
            escribir(var1);
            lugar(16,10);
            escribir('var2: ');
            lugar(16,20);
            escribir(var2);

            !! Postincremento
            var1 := var2++;
            lugar(18,10);
            escribir('Después de asignación con postincremento (var1 := var2++): ');
            lugar(19,10);
            escribir('var1: ');
            lugar(19,20);
            escribir(var1);
            lugar(20,10);
            escribir('var2: ');
            lugar(20,20);
            escribir(var2);

    si_no
        si (opcion = 2)
            entonces
                !! Inicializar variables
                var1 := 2;
                var2 := 2;

                lugar(10,10);
                escribir('Valores iniciales: ');
                lugar(11,10);
                escribir('var1: ');
                lugar(11,20);
                escribir(var1);
                lugar(12,10);
                escribir('var2: ');
                lugar(12,20);
                escribir(var2);

                !! Predecremento
                var1:= --var2;
                lugar(14,10);
                escribir('Después de asignación con predecremento (var1 := --var2): ');
                lugar(15,10);
                escribir('var1: ');
                lugar(15,20);
                escribir(var1);
                lugar(16,10);
                escribir('var2: ');
                lugar(16,20);
                escribir(var2);

                !! Postdecremento
                var1 := var2--;
                lugar(18,10);
                escribir('Después de asignación con postdecremento (var1 := var2--):  ');
                lugar(19,10);
                escribir('var1: ');
                lugar(19,20);
                escribir(var1);
                lugar(20,10);
                escribir('var2: ');
                lugar(20,20);
                escribir(var2);
        si_no
            si (opcion = 0)
                entonces
                    lugar(22,10);
                    escribir('Gracias por usar el intérprete ipe.exe');
            si_no
                lugar(22,10);
                escribir('Opción incorrecta');
            fin_si;
        fin_si;
    fin_si;

    lugar(25,10);
    escribir('Pulsa una tecla para continuar --> ');
    leer_cadena(pausa);

hasta (opcion = 0);

!! Despedida final
borrar_pantalla;
lugar(10,10);
escribir('El programa ha concluido. \n');
