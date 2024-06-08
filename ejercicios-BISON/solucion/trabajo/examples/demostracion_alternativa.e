!! Programa de demostración del operador ternario (alternativa ? :)

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

borrar_pantalla;

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

!! Despedida final
borrar_pantalla;
lugar(10,10);
escribir('El programa ha concluido. \n');
