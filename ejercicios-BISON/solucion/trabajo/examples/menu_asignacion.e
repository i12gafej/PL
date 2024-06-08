!! Programa para probar sentencias de operación-asignación

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
    leer(opcion);

    borrar_pantalla;

    si (opcion = 0)
        entonces  
            lugar(10,10);
            escribir(nombre);
            escribir(' Gracias por usar el intérprete ipe.exe ');
    si_no
        si (opcion >= 1 #y opcion <= 7)
            entonces

                lugar(11,10);
                escribir('Introduce el valor a asignar: ');
                leer(valor_asignar);

                !! Procesar la opción seleccionada
                si (opcion = 1)
                    entonces
                        lugar(13,10);
                        variable +:= valor_asignar;
                        lugar(17,10);
                        escribir('Resultado de +:= ');
                        lugar(17, 30);
                        escribir(variable);
                si_no 
                    si (opcion = 2)
                        entonces
                            lugar(13,10);
                            variable -:= valor_asignar;
                            lugar(17,10);
                            escribir('Resultado de -:= ');
                            lugar(17, 30);
                            escribir(variable);
                    si_no 
                        si (opcion = 3)
                            entonces
                                lugar(13,10);
                                variable *:= valor_asignar;
                                lugar(17,10);
                                escribir('Resultado de *:= ');
                                lugar(17, 30);
                                escribir(variable);
                        si_no 
                            si (opcion = 4)
                                entonces
                                    lugar(13,10);
                                    variable /:= valor_asignar;
                                    lugar(17,10);
                                    escribir('Resultado de /:= ');
                                    lugar(17, 30);
                                    escribir(variable);
                            si_no 
                                si (opcion = 5)
                                    entonces
                                        lugar(13,10);
                                        variable //:= valor_asignar;
                                        lugar(17,10);
                                        escribir('Resultado de //:= ');
                                        lugar(17, 30);
                                        escribir(variable);
                                si_no 
                                    si (opcion = 6)
                                        entonces
                                            lugar(13,10);
                                            variable %:= valor_asignar;
                                            lugar(17,10);
                                            escribir('Resultado de %:= ');
                                            lugar(17, 30);
                                            escribir(variable);
                                    si_no 
                                        si (opcion = 7)
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

hasta (opcion = 0);

!! Despedida final
borrar_pantalla;
lugar(10,10);
escribir('El programa ha concluido. \n');
