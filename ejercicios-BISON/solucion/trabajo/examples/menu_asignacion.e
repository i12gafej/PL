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

repetir 

    !! Menú de opciones

    borrar_pantalla;
    lugar(10,10);
    escribir(' Pruebas de operación-asignación ');
    lugar(12,10);
    escribir(' Sumar y asignar (+:=) --------------> 1 ');
    lugar(13,10);
    escribir(' Restar y asignar (-:=) -------------> 2 ');
    lugar(14,10);
    escribir(' Multiplicar y asignar (*:=) ---------> 3 ');
    lugar(15,10);
    escribir(' Dividir y asignar (/:=) -------------> 4 ');
    lugar(16,10);
    escribir(' División entera y asignar (//:=) ----> 5 ');
    lugar(17,10);
    escribir(' Módulo y asignar (%:=) --------------> 6 ');
    lugar(18,10);
    escribir(' Potencia y asignar (**:=) -----------> 7 ');
    lugar(19,10);
    escribir(' Finalizar --------------------------> 0 ');

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
                lugar(10,10);
                escribir('Introduce un número inicial: ');
                leer(numero_inicial);

                lugar(11,10);
                escribir('Introduce el valor a asignar: ');
                leer(valor_asignar);

                !! Procesar la opción seleccionada
                si (opcion = 1)
                    entonces
                        lugar(13,10);
                        numero_inicial +:= valor_asignar;
                        lugar(17,10);
                        escribir('Resultado de +:= ');
                        escribir(numero_inicial);
                si_no 
                    si (opcion = 2)
                        entonces
                            lugar(13,10);
                            numero_inicial -:= valor_asignar;
                            lugar(17,10);
                            escribir('Resultado de -:= ');
                            escribir(numero_inicial);
                    si_no 
                        si (opcion = 3)
                            entonces
                                lugar(13,10);
                                numero_inicial *:= valor_asignar;
                                lugar(17,10);
                                escribir('Resultado de *:= ');
                                escribir(numero_inicial);
                        si_no 
                            si (opcion = 4)
                                entonces
                                    lugar(13,10);
                                    numero_inicial /:= valor_asignar;
                                    lugar(17,10);
                                    escribir('Resultado de /:= ');
                                    escribir(numero_inicial);
                            si_no 
                                si (opcion = 5)
                                    entonces
                                        lugar(13,10);
                                        numero_inicial //:= valor_asignar;
                                        lugar(17,10);
                                        escribir('Resultado de //:= ');
                                        escribir(numero_inicial);
                                si_no 
                                    si (opcion = 6)
                                        entonces
                                            lugar(13,10);
                                            numero_inicial %:= valor_asignar;
                                            lugar(14,10);
                                            escribir('Resultado de %:= ');
                                            escribir(numero_inicial);
                                    si_no 
                                        si (opcion = 7)
                                            entonces
                                                lugar(13,10);
                                                numero_inicial **:= valor_asignar;
                                                lugar(14,10);
                                                escribir('Resultado de **:= ');
                                                escribir(numero_inicial);
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
