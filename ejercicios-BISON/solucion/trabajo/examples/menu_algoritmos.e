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
    escribir(' 1. Algoritmo montecarlo para calcular PI ');
    lugar(13,10);
    escribir(' 2. Algoritmo de la moneda sesgada ');
    lugar(14,10);
    escribir(' 3. Calcula n-ésimo valor de Fibonacci ');
    lugar(15,10);
    escribir(' 4. Prueba de primalidad de Fermat ');
    lugar(16,10);
    escribir(' 5. Algoritmo de Euclides extendido (coef. Bézout)');
    lugar(17,10);
    escribir(' 6. Conversor de decimal a hexadecimal');
    !!lugar(18,10);
    !!escribir(' 7. Menú operaciones ');
    !!lugar(19,10);
    !!escribir(' 8. Menú para ');
    lugar(20,10);
    escribir(' 0. Salir ');

    lugar(22,10);
    escribir(' Elige una opción: ');
    leer(opcion);

    casos (opcion)
        valor 1:
            borrar_pantalla;

            lugar(10,10);
            escribir('Estimación del valor de π utilizando el método de Montecarlo');
            lugar(12,10);
            escribir('Introduce el número de puntos a generar: ');
            leer(puntos_totales);

            dentro_circulo := 0;
            contador := 0;
            borrar_pantalla;
            para contador desde 0 hasta puntos_totales hacer
                x := random();
                y := random();

                !! Convertir los números aleatorios a valores en el rango [0,1)
                x := (((x * 10)) % 3)-1;
                y := (((x * 10)) % 3)-1;

                !! Comprobar si el punto (x, y) está dentro del círculo unitario
                
                si ((x**2 + y**2) <= 1) entonces
                    dentro_circulo++;
                fin_si;
            fin_para

            !! Calcular la estimación de π
            pi_estimate := (4 * dentro_circulo) / puntos_totales;

           !! borrar_pantalla;
            lugar(9,10);
            escribir('Estimación de π después de generar ');
            lugar(11,10);
            escribir(puntos_totales);
            lugar(13,10);
            escribir('puntos: ');
            lugar(15,25);
            escribir(pi_estimate);
            lugar(20, 10);
            escribir('Pulsa una tecla para continuar --> ');
            leer_cadena(pausa);

        valor 2:
            borrar_pantalla;
            lugar(10,10);
            escribir('Estimación de la imparcialidad de una moneda');
            lugar(12,10);
            escribir('Introduce el número de lanzamientos a realizar: ');
            leer(n_lanzamientos);

            contador_cara := 0;
            contador_cruz := 0;
            contador := 1;

            repetir
                lanzamiento := random();

                !! Convertir el número aleatorio a cara o cruz
                si (lanzamiento < 0.5) entonces
                    contador_cara++;
                si_no
                    contador_cruz++;
                fin_si;

                contador := contador + 1;
            hasta (contador > n_lanzamientos);

            !! Calcular la probabilidad de cara y cruz
            probabilidad_cara := contador_cara / n_lanzamientos;
            probabilidad_cruz := contador_cruz / n_lanzamientos;

            borrar_pantalla;
            lugar(10,10);
            escribir('Resultados después de ');
            lugar(10,35);
            escribir(n_lanzamientos);
            lugar (10, 45);
            escribir(' lanzamientos:');
            lugar(12,10);
            escribir('Número de caras: ');
            lugar(12,30);
            escribir(contador_cara);
            lugar(13,10);
            escribir('Número de cruces: ');
            lugar(13, 30);
            escribir(contador_cruz);
            lugar(14,10);
            escribir('Probabilidad de cara: ');
            lugar(14,40);
            escribir(probabilidad_cara);
            lugar(15,10);
            escribir('Probabilidad de cruz: ');
            lugar(15,40);
            escribir(probabilidad_cruz);

            si (abs(probabilidad_cara - 0.5) < 0.1) entonces
                lugar(17,10);
                escribir('La moneda parece ser justa.');
            si_no
                lugar(17,10);
                escribir('La moneda parece estar sesgada.');
            fin_si;
            lugar(20,10);
            escribir('Pulsa una tecla para continuar --> ');
            leer_cadena(pausa);
        valor 3:
            borrar_pantalla;
            lugar(10,10);
            escribir('Calcular el n-ésimo valor de Fibonacci');
            lugar(12,10);
            escribir('Introduce el n-ésimo valor a calcular: ');
            leer(n_esimo);

            si (n_esimo = 0) entonces
                fibonacci := 0;
            si_no 
                si (n_esimo = 1) entonces
                    fibonacci := 1;
                si_no
                    a := 0;
                    b := 1;
                    contador := 2;

                    repetir
                        fibonacci := a + b;
                        a := b;
                        b := fibonacci;
                        contador := contador + 1;
                    hasta (contador > n_esimo);
                fin_si
            fin_si
            lugar(15,10);
            escribir('El valor para la posición ');
            lugar(15, 40);
            escribir(n_esimo);
            lugar(15, 45);
            escribir(' es: ');
            lugar(17, 25);
            escribir(fibonacci);
            lugar(20, 10);
            escribir('Pulsa una tecla para continuar --> ');
            leer_cadena(pausa);
        valor 4:
            borrar_pantalla;
            lugar(5,10);
            escribir('Prueba de primalidad de Fermat');
            lugar(7,10);
            escribir('Introduce el número a verificar: ');
            leer(n);
            lugar(9,10);
            escribir('Introduce el número de iteraciones: ');
            leer(k);

            es_probablemente_primo := verdadero;

            si (n <= 1) entonces
                es_probablemente_primo := falso;
            si_no 
                si (n = 2) entonces
                    es_probablemente_primo := verdadero;
                si_no
                    repetir
                        a := (random() * (n - 2)) + 1; !! Generar un número aleatorio en el rango [1, n-1]

                        !! Calcular a^(n-1) % n usando exponenciación rápida
                        resultado := 1;
                        base := a;
                        exponente := n - 1;
                        
                        repetir
                            si (exponente % 2 = 1) entonces
                                resultado := (resultado * base) % n;
                            fin_si;
                            exponente := exponente // 2;
                            base := (base * base) % n;
                        hasta (exponente = 0);

                        si (resultado <> 1) entonces
                            es_probablemente_primo := falso;
                            romper;
                        fin_si;

                        k := k - 1;
                    hasta (k = 0);
                fin_si
            fin_si

            borrar_pantalla;
            lugar(10,10);
            si (es_probablemente_primo) entonces
                escribir('El número ');
                lugar(10,20);
                escribir(n);
                lugar(12,10);
                escribir('es probablemente primo.');
            si_no
                escribir('El número ');
                lugar(10,20);
                escribir(n);
                lugar(12,10);
                escribir('no es primo.');
            fin_si;
            escribir('Pulsa una tecla para continuar --> ');
            leer_cadena(pausa);
        valor 5:
            borrar_pantalla;
            lugar(5,10);
            escribir('Algoritmo de Euclides Extendido para encontrar los coeficientes de Bézout');
            lugar(7,10);
            escribir('Introduce el primer número (a): ');
            leer(a);
            lugar(9,10);
            escribir('Introduce el segundo número (b): ');
            leer(b);

            !! Inicializar variables
            x0 := 1;
            x1 := 0;
            y0 := 0;
            y1 := 1;
            original_a := a;
            original_b := b;
            si (b = 0) entonces
                mcd := a;
                x := 1;
                y := 0;
            si_no
                mientras (b <> 0) hacer
                    q := a // b;  !! División entera de a entre b
                    r := a % b;   !! Resto de la división de a entre b

                    a := b;
                    b := r;

                    temp_x := x0 - q * x1;
                    temp_y := y0 - q * y1;

                    x0 := x1;
                    x1 := temp_x;
                    y0 := y1;
                    y1 := temp_y;
                fin_mientras;

                x := x0;
                y := y0;
                mcd := a;
            fin_si;
            borrar_pantalla;

            lugar(10, 10);
            escribir('Para los números ');
            lugar(11, 10);
            escribir(original_a);
            lugar(11, 15);
            escribir(' y ');
            lugar(11, 25);
            escribir(original_b);
            lugar(12,10);
            escribir('Los coeficientes de Bézout son:');
            lugar(13, 10);
            escribir('x = ');
            lugar(13, 15);
            escribir(x);
            lugar(13, 25); 
            escribir('y = ');
            lugar(13, 30);
            escribir(y);
            lugar(14,10);
            escribir('El máximo común divisor es: ');
            lugar(15, 20);
            escribir(mcd);
            escribir('Pulsa una tecla para continuar --> ');
            leer_cadena(pausa);
        valor 6:
            borrar_pantalla;
            lugar(10,10);
            escribir('Conversión de número decimal a hexadecimal');
            lugar(12,10);
            escribir('Introduce un número decimal: ');
            leer(decimal);
            si (decimal = 0) entonces
                hexadecimal := '0';
            si_no
                hexadecimal := '';
                n := decimal;
                repetir
                    resto := n % 16;
                    n := n // 16;
                    
                    si (resto = 0) entonces
                        digito := '0';
                    si_no 
                        si (resto = 1) entonces
                            digito := '1';
                        si_no 
                            si (resto = 2) entonces
                                digito := '2';
                            si_no 
                                si (resto = 3) entonces
                                    digito := '3';
                                si_no 
                                    si (resto = 4) entonces
                                        digito := '4';
                                    si_no 
                                        si (resto = 5) entonces
                                            digito := '5';
                                        si_no 
                                            si (resto = 6) entonces
                                                digito := '6';
                                            si_no 
                                                si (resto = 7) entonces
                                                    digito := '7';
                                                si_no 
                                                    si (resto = 8) entonces
                                                        digito := '8';
                                                    si_no 
                                                        si (resto = 9) entonces
                                                            digito := '9';
                                                        si_no 
                                                            si (resto = 10) entonces
                                                                digito := 'A';
                                                            si_no 
                                                                si (resto = 11) entonces
                                                                    digito := 'B';
                                                                si_no 
                                                                    si (resto = 12) entonces
                                                                        digito := 'C';
                                                                    si_no 
                                                                        si (resto = 13) entonces
                                                                            digito := 'D';
                                                                        si_no 
                                                                            si (resto = 14) entonces
                                                                                digito := 'E';
                                                                            si_no
                                                                                digito := 'F';
                                                                            fin_si
                                                                        fin_si
                                                                    fin_si
                                                                fin_si
                                                            fin_si
                                                        fin_si
                                                    fin_si
                                                fin_si
                                            fin_si
                                        fin_si
                                    fin_si
                                fin_si
                            fin_si
                        fin_si
                    fin_si;

                    hexadecimal := digito || hexadecimal;
                hasta (n = 0);
            fin_si;
            borrar_pantalla;
            lugar(10,10);
            escribir('El número ');
            lugar(10, 20);
            escribir(decimal);
            lugar(11, 10);
            escribir(' en hexadecimal es: ');
            lugar(13, 20);
            escribir(hexadecimal);
            escribir('Pulsa una tecla para continuar');
            leer_cadena(pausa);
        
    fin_casos

hasta (opcion = 0);