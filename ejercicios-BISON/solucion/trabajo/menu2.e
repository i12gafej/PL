!! Bienvenida

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

    !! Opciones disponibles

    borrar_pantalla;
    lugar(10,10);
    escribir(' Factorial de un número --> 1 ');
    lugar(11,10);
    escribir(' Máximo común divisor ----> 2 ');
    lugar(12,10);
    escribir(' Cuadrado de un número ----> 3 ');
    lugar(13,10);
    escribir(' Convertir Celsius a Fahrenheit --> 4 ');
    lugar(14,10);
    escribir(' Determinar si un número es primo --> 5 ');
    lugar(15,10);
    escribir(' Finalizar ---------------> 0 ');

    lugar(18,10);
    escribir(' Elige una opcion ');

    leer(opcion);

    borrar_pantalla;

    si (opcion = 0)       		
        entonces  
            lugar(10,10);
            escribir(nombre);
            escribir('Gracias por usar el intérprete ipe.exe ');
    si_no 					
        !! Factorial de un número
        si (opcion = 1)
            entonces
                lugar(10,10);
                escribir(' Factorial de un número  ');

                lugar(11,10);
                escribir(' Introduce un número entero ');
                leer(N);

                factorial := 1;

                para i desde 2 hasta N paso 1 hacer
                    factorial := factorial * i;
                fin_para;

                !! Resultado
                lugar(15,10);
                escribir(' El factorial de ');
                escribir(N);
                escribir(' es ');
                escribir(factorial);

        si_no 
            !! Máximo común divisor
            si (opcion = 2)
                entonces
                    lugar(10,10);
                    escribir(' Máximo común divisor de dos números ');

                    lugar(11,10);
                    escribir(' Algoritmo de Euclides ');

                    lugar(12,10);
                    escribir(' Escribe el primer número ');
                    leer(a);

                    lugar(14,10);
                    escribir(' Escribe el segundo número ');
                    leer(b);

                    !! Se ordenan los números
                    si (a < b)
                        entonces 
                            auxiliar := a;
                            a := b;
                            b := auxiliar;
                    fin_si;

                    !! Se guardan los valores originales
                        A1 := a;
                        B1 := b;

                    !! Se aplica el método de Euclides	
                    resto  := a % b;

                    mientras (resto <> 0) hacer
                        a :=  b;
                        b := resto;
                        resto := a % b;
                    fin_mientras;
            
                    !! Se muestra el resultado
                    lugar(15,10);
                    escribir(' Máximo común divisor de ');
                    escribir(A1);
                    escribir(' y ');
                    escribir(B1);
                    escribir(' es ---> ');
                    escribir(b);

                !! Cuadrado de un número
                si_no
                    si (opcion = 3)
                        entonces
                            lugar(10,10);
                            escribir(' Cuadrado de un número ');

                            lugar(11,10);
                            escribir(' Introduce un número entero ');
                            leer(N);

                            cuadrado := N * N;

                            lugar(15,10);
                            escribir(' El cuadrado de ');
                            escribir(N);
                            escribir(' es ');
                            escribir(cuadrado);

                    !! Convertir Celsius a Fahrenheit
                    si_no
                        si (opcion = 4)
                            entonces
                                lugar(10,10);
                                escribir(' Convertir Celsius a Fahrenheit ');

                                lugar(11,10);
                                escribir(' Introduce la temperatura en Celsius ');
                                leer(celsius);

                                fahrenheit := (celsius * 9/5) + 32;

                                lugar(15,10);
                                escribir(celsius);
                                escribir(' grados Celsius son ');
                                escribir(fahrenheit);
                                escribir(' grados Fahrenheit');

                        !! Determinar si un número es primo
                        si_no
                            <<si (opcion = 5)
                                entonces
                                    lugar(10,10);
                                    escribir(' Determinar si un número es primo ');

                                    lugar(11,10);
                                    escribir(' Introduce un número entero ');
                                    leer(N);

                                    es_primo := 1;
                                    si (N <= 1)
                                        entonces
                                            es_primo := 0;
                                    fin_si;

                                    para i desde 2 hasta N-1 paso 1 hacer
                                        si (N % i = 0)
                                            entonces
                                                es_primo := 0;
                                                salir_para;
                                        fin_si;
                                    fin_para;

                                    lugar(15,10);
                                    si (es_primo = 1)
                                        entonces
                                            escribir(N);
                                            escribir(' es un número primo');
                                    si_no
                                        escribir(N);
                                        escribir(' no es un número primo');
                                    fin_si;

                            !! Opcion incorrecta
                            si_no  
                                lugar(15,10);
                                escribir(' Opcion incorrecta ');
                            fin_si; >>
                        fin_si;
                    fin_si;
                fin_si;
            fin_si;  
        fin_si;                 
    fin_si;                          

    lugar(40,10); 
    escribir('\n Pulse una tecla para continuar --> ');
    leer_cadena(pausa);
 
hasta (opcion = 0);             

!! Despedida final
borrar_pantalla;
lugar(10,10);
escribir('El programa ha concluido. \n');
