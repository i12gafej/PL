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
    escribir(' 5. Menú incremento/decremento ');
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
        valor 4:
            !! Menú hacer
            repetir
                borrar_pantalla;
                lugar(10,10);
                escribir(' Menú hacer mientras ');
                lugar(12,10);
                escribir(' 1. Incremento ');
                lugar(13,10);
                escribir(' 2. Decremento ');
                lugar(14,10);
                escribir(' 0. Volver ');

                lugar(16,10);
                escribir(' Elige una opción: ');
                leer(opcion_hacer);

                borrar_pantalla;

                si (opcion_hacer = 1 #o opcion_hacer = 2) entonces
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
                si_no
                    si (opcion_hacer = 0) entonces
                        lugar(13,10);
                        escribir('Volviendo al menú principal...');
                    si_no
                        lugar(13,10);
                        escribir('Opción incorrecta');
                    fin_si;
                fin_si;

                lugar(25,10);
                escribir('Pulsa una tecla para continuar --> ');
                leer_cadena(pausa);
            hasta (opcion_hacer = 0);
    fin_casos

    lugar(30,10);
    escribir('Pulsa una tecla para continuar --> ');
    leer_cadena(pausa);

hasta (opcion = 0);

!! Despedida final
borrar_pantalla;
lugar(10,10);
escribir('El programa ha concluido. \n');
