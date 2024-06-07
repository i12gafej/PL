!! Programa para operar sobre una variable

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

    !! Menú de opcion_operaces

    borrar_pantalla;
    lugar(10,10);
    escribir(' Menú de opcion_operaces ');
    lugar(12,10);
    escribir(' Incrementar variable (++valor) ---------------------> 1 ');
    lugar(13,10);
    escribir(' Decrementar variable (--valor) ---------------------> 2 ');
    lugar(14,10);
    escribir(' Sumar y asignar (variable + número) -----------------> 3 ');
    lugar(15,10);
    escribir(' Restar y asignar (variable - número) ----------------> 4 ');
    lugar(16,10);
    escribir(' Multiplicar y asignar (variable * número) -----------> 5 ');
    lugar(17,10);
    escribir(' Dividir y asignar (variable / número) ---------------> 6 ');
    lugar(18,10);
    escribir(' División entera y asignar (variable // número) -------> 7 ');
    lugar(19,10);
    escribir(' Módulo y asignar (variable % número) ----------------> 8 ');
    lugar(20,10);
    escribir(' Potencia y asignar (variable ** número) -------------> 9 ');
    lugar(21,10);
    escribir(' Finalizar -------------------------------------------> 0 ');

    lugar(23,10);
    escribir(' Elige una opción: ');
    leer(opcion_operac);

    borrar_pantalla;

    si (opcion_operac = 0)
        entonces  
            lugar(10,10);
            escribir(nombre);
            escribir(' Gracias por usar el intérprete ipe.exe ');
    si_no
        si (opcion_operac = 1)
            entonces
                ++variable;
                lugar(10,10);
                escribir('Variable incrementada: ');
                escribir(variable);
        si_no 
            si (opcion_operac = 2)
                entonces
                    --variable;
                    lugar(10,10);
                    escribir('Variable decrementada: ');
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
                                escribir('Resultado de variable + ');
                                escribir(numero);
                                escribir(' = ');
                                escribir(variable);
                        si_no 
                            si (opcion_operac = 4)
                                entonces
                                    variable := variable - numero;
                                    lugar(11,10);
                                    escribir('Resultado de variable - ');
                                    escribir(numero);
                                    escribir(' = ');
                                    escribir(variable);
                            si_no 
                                si (opcion_operac = 5)
                                    entonces
                                        variable := variable * numero;
                                        lugar(11,10);
                                        escribir('Resultado de variable * ');
                                        escribir(numero);
                                        escribir(' = ');
                                        escribir(variable);
                                si_no 
                                    si (opcion_operac = 6)
                                        entonces
                                            variable := variable / numero;
                                            lugar(11,10);
                                            escribir('Resultado de variable / ');
                                            escribir(numero);
                                            escribir(' = ');
                                            escribir(variable);
                                    si_no 
                                        si (opcion_operac = 7)
                                            entonces
                                                variable := variable // numero;
                                                lugar(11,10);
                                                escribir('Resultado de variable // ');
                                                escribir(numero);
                                                escribir(' = ');
                                                escribir(variable);
                                        si_no 
                                            si (opcion_operac = 8)
                                                entonces
                                                    variable := variable % numero;
                                                    lugar(11,10);
                                                    escribir('Resultado de variable % ');
                                                    escribir(numero);
                                                    escribir(' = ');
                                                    escribir(variable);
                                            si_no 
                                                si (opcion_operac = 9)
                                                    entonces
                                                        variable := variable ** numero;
                                                        lugar(11,10);
                                                        escribir('Resultado de variable ** ');
                                                        escribir(numero);
                                                        escribir(' = ');
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
    escribir('\nPulsa una tecla para continuar --> ');
    leer_cadena(pausa);

hasta (opcion_operac = 0);

!! Despedida final
borrar_pantalla;
lugar(10,10);
escribir('El programa ha concluido. \n');
