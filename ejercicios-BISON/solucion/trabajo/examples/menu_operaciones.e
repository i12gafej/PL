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
            escribir(nombre);
            escribir(' Gracias por usar el intérprete ipe.exe ');
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
    escribir('\nPulsa una tecla para continuar --> ');
    leer_cadena(pausa);

hasta (opcion_operac = 0);

!! Despedida final
borrar_pantalla;
lugar(10,10);
escribir('El programa ha concluido. \n');
