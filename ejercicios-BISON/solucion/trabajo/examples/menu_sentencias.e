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

repetir

    borrar_pantalla;
    lugar(10,10);
    escribir(' Menú principal ');
    lugar(12,10);
    escribir(' 1. Menú demostración alternativa ');
    lugar(13,10);
    escribir(' 2. Menú asignación ');
    lugar(14,10);
    escribir(' 3. Menú concatenar ');
    lugar(15,10);
    escribir(' 4. Menú hacer ');
    lugar(16,10);
    escribir(' 5. Menú demostración incremento/decremento ');
    lugar(17,10);
    escribir(' 6. Menú mientras ');
    lugar(18,10);
    escribir(' 7. Menú operaciones ');
    lugar(19,10);
    escribir(' 8. Menú para ');
    lugar(20,10);
    escribir(' 0. Salir ');

    lugar(22,10);
    escribir(' Elige una opción: ');
    leer(opcion);

    borrar_pantalla;

    casos (opcion)
        valor 1:
            !! Demostración con valores numéricos

            lugar(10,10);
            escribir('Demostración con valores numéricos');

            lugar(12,10);
            escribir('Operación: dato := (1 > 0) ? 3 : 4');
            dato := (1 > 0) ? 3 : 4;
            lugar(13,10);
            escribir('Resultado: ');
            lugar(13, 20);
            escribir(dato);

            lugar(15,10);
            escribir('Cambiando la condición: dato := (1 < 0) ? 3 : 4');
            dato := (1 < 0) ? 3 : 4;
            lugar(16,10);
            escribir('Resultado: ');
            lugar(16,20);
            escribir(dato);

            !! Pausa antes de la siguiente demostración
            lugar(18,10);
            escribir('Pulsa una tecla para continuar');
            leer_cadena(pausa);

            borrar_pantalla;

            !! Demostración con cadenas

            lugar(10,10);
            escribir('Demostración con cadenas');

            lugar(12,10);
            escribir('Operación: cadena := (1 > 0) ? \'verdadero\' : \'falso\'');
            cadena := (1 > 0) ? 'verdadero' : 'falso';
            lugar(13,10);
            escribir('Resultado: ');
            lugar(13, 20);
            escribir(cadena);

            lugar(15,10);
            escribir('Cambiando la condición: cadena := (1 < 0) ? \'verdadero\' : \'falso\'');
            cadena := (1 < 0) ? 'verdadero' : 'falso';
            lugar(16,10);
            escribir('Resultado: ');
            lugar(16,20);
            escribir(cadena);

            !! Pausa antes de la siguiente demostración
            lugar(18,10);
            escribir('Pulsa una tecla para continuar');
            leer_cadena(pausa);

            borrar_pantalla;

            !! Demostración con booleanos

            lugar(10,10);
            escribir('Demostración con booleanos');

            lugar(12,10);
            escribir('Operación: bool := (1 > 0) ? verdadero : falso');
            bool := (1 > 0) ? verdadero : falso;
            lugar(13,10);
            escribir('Resultado: ');
            lugar(13, 20);
            escribir(bool);

            lugar(15,10);
            escribir('Cambiando la condición: bool := (1 < 0) ? verdadero : falso');
            bool := (1 < 0) ? verdadero : falso;
            lugar(16,10);
            escribir('Resultado: ');
            lugar(16,20);
            escribir(bool);

            !! Pausa antes de la despedida final
            lugar(18,10);
            escribir('Pulsa una tecla para continuar');
            leer_cadena(pausa);


        valor 2:
            variable := 0;

            repetir 

                borrar_pantalla;
                !! Menú de opcion_operaces
                lugar(8, 10);
                escribir(' Valor de la variable: ');
                lugar(8, 35);
                escribir(variable);

                lugar(10,10);
                escribir(' Pruebas de operación-asignación ');
                lugar(12,10);
                escribir('1. Sumar y asignar (+:=)');
                lugar(13,10);
                escribir('2. Restar y asignar (-:=)');
                lugar(14,10);
                escribir('3. Multiplicar y asignar (*:=)');
                lugar(15,10);
                escribir('4. Dividir y asignar (/:=)');
                lugar(16,10);
                escribir('5. División entera y asignar (//:=)');
                lugar(17,10);
                escribir('6. Módulo y asignar (%:=)');
                lugar(18,10);
                escribir('7. Potencia y asignar (**:=)');
                lugar(19,10);
                escribir('0. Finalizar');

                lugar(21,10);
                escribir(' Elige una opción: ');
                leer(opcion_asg);

                borrar_pantalla;

                si (opcion_asg = 0)
                    entonces  
                        
                si_no
                    si (opcion_asg >= 1 #y opcion_asg <= 7)
                        entonces

                            lugar(11,10);
                            escribir('Introduce el valor a asignar: ');
                            leer(valor_asignar);

                            !! Procesar la opción seleccionada
                            si (opcion_asg = 1)
                                entonces
                                    lugar(13,10);
                                    variable +:= valor_asignar;
                                    lugar(17,10);
                                    escribir('Resultado de +:= ');
                                    lugar(17, 30);
                                    escribir(variable);
                            si_no 
                                si (opcion_asg = 2)
                                    entonces
                                        lugar(13,10);
                                        variable -:= valor_asignar;
                                        lugar(17,10);
                                        escribir('Resultado de -:= ');
                                        lugar(17, 30);
                                        escribir(variable);
                                si_no 
                                    si (opcion_asg = 3)
                                        entonces
                                            lugar(13,10);
                                            variable *:= valor_asignar;
                                            lugar(17,10);
                                            escribir('Resultado de *:= ');
                                            lugar(17, 30);
                                            escribir(variable);
                                    si_no 
                                        si (opcion_asg = 4)
                                            entonces
                                                lugar(13,10);
                                                variable /:= valor_asignar;
                                                lugar(17,10);
                                                escribir('Resultado de /:= ');
                                                lugar(17, 30);
                                                escribir(variable);
                                        si_no 
                                            si (opcion_asg = 5)
                                                entonces
                                                    lugar(13,10);
                                                    variable //:= valor_asignar;
                                                    lugar(17,10);
                                                    escribir('Resultado de //:= ');
                                                    lugar(17, 30);
                                                    escribir(variable);
                                            si_no 
                                                si (opcion_asg = 6)
                                                    entonces
                                                        lugar(13,10);
                                                        variable %:= valor_asignar;
                                                        lugar(17,10);
                                                        escribir('Resultado de %:= ');
                                                        lugar(17, 30);
                                                        escribir(variable);
                                                si_no 
                                                    si (opcion_asg = 7)
                                                        entonces
                                                            lugar(13,10);
                                                            variable **:= valor_asignar;
                                                            lugar(17,10);
                                                            escribir('Resultado de **:= ');
                                                            lugar(17, 30);
                                                            escribir(variable);
                                                    fin_si;
                                                fin_si;
                                            fin_si;
                                        fin_si;
                                    fin_si;
                                fin_si;
                            fin_si;
                    si_no
                        lugar(13,10);
                        escribir('Opción incorrecta');
                    fin_si;
                fin_si;

                lugar(40,10); 
                escribir('\nPulsa una tecla para continuar --> ');
                leer_cadena(pausa);

            hasta (opcion_asg = 0);

        valor 3:
            cadena := '';
            repetir
                lugar(12,10);
                escribir('Introduce una cadena para concatenar: ');
                leer_cadena(nueva_cadena);

                cadena := cadena || nueva_cadena;

                lugar(14,10);
                escribir('Cadena actual: ');
                escribir(cadena);

                lugar(16,10);
                escribir('¿Desea concatenar otra cadena? (s/n): ');
                leer_cadena(respuesta);

                borrar_pantalla;

            hasta (respuesta = 'n');

        valor 4:
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

                lugar(posicion,10);
                escribir('Desea realizar otro bucle? (si/no)? ');
                leer_cadena(opt);
                si (opt = 'no') entonces
                    opcion_hacer := 0;
                fin_si
            hasta (opcion_hacer = 0);
        valor 5:
            repetir

                borrar_pantalla;
                lugar(10,10);
                escribir(' Demostración de incremento/decremento ');
                lugar(12,10);
                escribir(' 1. Incremento ');
                lugar(13,10);
                escribir(' 2. Decremento ');
                lugar(14,10);
                escribir(' 0. Salir ');

                lugar(16,10);
                escribir(' Elige una opción: ');
                leer(opcion_inc);

                borrar_pantalla;

                si (opcion_inc = 1)
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
                    si (opcion_inc = 2)
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
                    fin_si;
                fin_si;

                lugar(25,10);
                escribir('Pulsa una tecla para continuar --> ');
                leer_cadena(pausa);

            hasta (opcion_inc = 0);
        valor 6:
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

                

                si (incremento = 'si')
                    entonces
                        lugar(13,10);
                        escribir('Introduce el valor de incremento: ');
                        leer(valor_incremento);

                        si (((valor_inicial < valor_final) #y (valor_incremento < 0)) #o ((valor_inicial > valor_final) #y (valor_incremento > 0)))
                            entonces
                                lugar(15,10);
                                escribir('Error: El incremento genera un bucle infinito.');
                        si_no
                            borrar_pantalla;
                            i := valor_inicial;
                            posicion := 15;
                            mientras (((valor_inicial < valor_final) #y (i <= valor_final)) #o ((valor_inicial > valor_final) #y (i >= valor_final))) hacer
                                lugar(posicion, 4);
                                escribir('Valor de i: ');
                                lugar(posicion, 20);
                                escribir(i);
                                posicion++;
                                i := i + valor_incremento;
                            fin_mientras;
                        fin_si;
                si_no
                    si (valor_inicial < valor_final)
                        entonces
                            i := valor_inicial;
                            posicion := 15;
                            mientras (i <= valor_final) hacer
                                lugar(posicion, 4);
                                escribir('Valor de i: ');
                                lugar(posicion, 20);
                                escribir(i);
                                posicion++;
                                i := i + 1;
                            fin_mientras;
                    si_no
                        si (valor_inicial > valor_final)
                            entonces
                                i := valor_inicial;
                                posicion := 15;
                                mientras (i >= valor_final) hacer
                                    lugar(posicion, 4);
                                    escribir('Valor de i: ');
                                    lugar(posicion, 20);
                                    posicion++;
                                    escribir(i);
                                    i := i - 1;
                                fin_mientras;
                        fin_si;
                    fin_si;
                fin_si;

                lugar(posicion,10);
                escribir('¿Desea realizar otro bucle? (si/no): ');
                leer_cadena(respuesta);
                

            hasta (respuesta = 'no');
        valor 7:
            variable := 0;

            repetir 
                borrar_pantalla;
                !! Menú de opcion_operaces
                lugar(8, 10);
                escribir(' Valor de la variable: ');
                lugar(8, 35);
                escribir(variable);
                
                lugar(10,10);
                escribir(' Menú de operaciones ');
                lugar(12,10);
                escribir('1. Incrementar variable (++valor) ');
                lugar(13,10);
                escribir('2. Decrementar variable (--valor) ');
                lugar(14,10);
                escribir('3. Sumar y asignar (variable + número) ');
                lugar(15,10);
                escribir('4. Restar y asignar (variable - número) ');
                lugar(16,10);
                escribir('5. Multiplicar y asignar (variable * número) ');
                lugar(17,10);
                escribir('6. Dividir y asignar (variable / número) ');
                lugar(18,10);
                escribir('7. División entera y asignar (variable // número) ');
                lugar(19,10);
                escribir('8. Módulo y asignar (variable % número) ');
                lugar(20,10);
                escribir('9. Potencia y asignar (variable ** número) ');
                lugar(21,10);
                escribir('0. Finalizar ');

                lugar(23,10);
                escribir(' Elige una opción: ');
                leer(opcion_operac);

                borrar_pantalla;

                si (opcion_operac = 0)
                    entonces  
                        lugar(10,10);
                        
                si_no
                    si (opcion_operac = 1)
                        entonces
                            ++variable;
                            lugar(10,10);
                            escribir('Variable incrementada: ');
                            lugar(10, 35);
                            escribir(variable);
                    si_no 
                        si (opcion_operac = 2)
                            entonces
                                --variable;
                                lugar(10,10);
                                escribir('Variable decrementada: ');
                                lugar(10, 35);
                                escribir(variable);
                        si_no
                            si (opcion_operac >= 3 #y opcion_operac <= 9)
                                entonces
                                    lugar(10,10);
                                    escribir('Introduce un número: ');
                                    leer(numero);

                                    si (opcion_operac = 3)
                                        entonces
                                            variable := variable + numero;
                                            lugar(11,10);
                                            escribir('Resultado de variable (+) ');
                                            lugar(11, 36);
                                            escribir(numero);
                                            lugar(11, 45);
                                            escribir(' --> ');
                                            lugar(11, 51);
                                            escribir(variable);
                                    si_no 
                                        si (opcion_operac = 4)
                                            entonces
                                                variable := variable - numero;
                                                lugar(11,10);
                                                escribir('Resultado de variable - ');
                                                lugar(11, 36);
                                                escribir(numero);
                                                lugar(11, 45);
                                                escribir(' --> ');
                                                lugar(11, 51);
                                                escribir(variable);
                                        si_no 
                                            si (opcion_operac = 5)
                                                entonces
                                                    variable := variable * numero;
                                                    lugar(11,10);
                                                    escribir('Resultado de variable * ');
                                                    lugar(11, 36);
                                                    escribir(numero);
                                                    lugar(11, 45);
                                                    escribir(' --> ');
                                                    lugar(11, 51);
                                                    escribir(variable);
                                            si_no 
                                                si (opcion_operac = 6)
                                                    entonces
                                                        variable := variable / numero;
                                                        lugar(11,10);
                                                        escribir('Resultado de variable / ');
                                                        lugar(11, 36);
                                                        escribir(numero);
                                                        lugar(11, 45);
                                                        escribir(' --> ');
                                                        lugar(11, 51);
                                                        escribir(variable);
                                                si_no 
                                                    si (opcion_operac = 7)
                                                        entonces
                                                            variable := variable // numero;
                                                            lugar(11,10);
                                                            escribir('Resultado de variable // ');
                                                            lugar(11, 36);
                                                            escribir(numero);
                                                            lugar(11, 45);
                                                            escribir(' --> ');
                                                            lugar(11, 51);
                                                            escribir(variable);
                                                    si_no 
                                                        si (opcion_operac = 8)
                                                            entonces
                                                                variable := variable % numero;
                                                                lugar(11,10);
                                                                escribir('Resultado de variable % ');
                                                                lugar(11, 36);
                                                                escribir(numero);
                                                                lugar(11, 45);
                                                                escribir(' --> ');
                                                                lugar(11, 51);
                                                                escribir(variable);
                                                        si_no 
                                                            si (opcion_operac = 9)
                                                                entonces
                                                                    variable := variable ** numero;
                                                                    lugar(11,10);
                                                                    escribir('Resultado de variable ** ');
                                                                    lugar(11, 36);
                                                                    escribir(numero);
                                                                    lugar(11, 45);
                                                                    escribir(' --> ');
                                                                    lugar(11, 51);
                                                                    escribir(variable);
                                                            fin_si;
                                                        fin_si;
                                                    fin_si;
                                                fin_si;
                                            fin_si;
                                        fin_si;
                                    fin_si;
                            si_no
                                lugar(13,10);
                                escribir('Opción incorrecta');
                            fin_si;
                        fin_si;
                    fin_si;
                fin_si;

                lugar(25,10);

            hasta (opcion_operac = 0);

        valor 8:
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
                        lugar(posicion, 20);
                        escribir(i);
                        posicion++;
                    fin_para;
            si_no
                posicion := 15;
                para i desde valor_inicial hasta valor_final hacer
                    lugar(posicion, 4);
                    escribir('Valor de i: ');
                    lugar(posicion, 20);
                    escribir(i);
                    posicion++;
                fin_para;
            fin_si;

            lugar(posicion,10);
            escribir('¿Desea realizar otro bucle? (si/no): ');
            leer_cadena(respuesta);

        hasta (respuesta = 'no');

    fin_casos

    borrar_pantalla;

hasta (opcion = 0);

!! Despedida final
borrar_pantalla;
lugar(10,10);
escribir(nombre);
escribir('Gracias por utilizar el intérprete.');
escribir('El programa ha concluido. \n');
