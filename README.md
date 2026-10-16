*Este proyecto ha sido creado como parte del currículo de 42 por lesainz*

## Descripción
Este proyecto consiste en crear la funcion **printf** que contendrá una serie de funciones de propósito general que tus programas podrán utilizar. 

## Instrucciones
Para compilar debes
| Comando | Descripción |
| :--- | :--- |
| `make` | Compila la parte obligatoria y genera un nuevo archivo llamado 'libftprintf.a'. Todas las funciones programadas en (.c) generan un archivo objeto (.o) correspondiente.|
| `make clean` | Elimina todos los archivos objeto (.o) que generamos al ejecutar 'make'. |
| `make fclean` | Elimina todos los archivos objeto (.o) y la libreria estática(libftprintf.a) que generamos al ejecutar 'make'.|
| `make re` | Hace una limpieza totall y vueve a compilar todo desde cero.|


## Recursos 
* **Recursos:** Páginas de Manual de C ('man'), referencias de la biblioteca estandar y seguimento estricto de La Norma. 
* **Uso de la IA:**Se usó la AI de forma bastante intensa, como apoyo para programar las funciones, entender la lógica interna de cada función y comprobaciones de compilación. 

## Descripción del proyecto
> **Nota:** Todas las funciones siguen estrictamente los estándares de la Norminette de 42.

| Función | Descripción clave y detalles para la defensa |
| :--- | :--- |
| `ft_hexadez` | funciones relacionadas con hexadecimal. |
| `ft_isalpha` | comprueba si un carácter es alfabético. |
| `ft_loweryuppercase` | funciones relacionadas con mayúsculas y minúsculas. |
| `ft_putchar_fd` | escribe un carácter en un descriptor de archivo. |
| `ft_putnbr_fd` | escribe un número entero. |
| `ft_putstr_fd` | escribe una cadena. |
| `ft_putthing` | función auxiliar para la salida de datos. |
| `ft_strlen` |  calcula la longitud de una cadena. |
| `ft_tolower` | convierte un carácter a minúscula.|
| `ft_toupper`| convierte un carácter a mayúscula. |
| `Makefile`| automatiza la compilación del proyecto. |