!! Programa para concatenar cadenas

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
lugar(10,10);
escribir('Introduce una cadena inicial: ');
leer_cadena(cadena);

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

!! Despedida final
borrar_pantalla;
lugar(10,10);
escribir('El programa ha concluido. \n');
escribir('Cadena final: ');
escribir(cadena);
