*Este proyecto ha sido creado como parte del currículo de 42 por lesainz*

## Descripción
El proyecto Get Next Line tiene como objetivo programar una función en C capaz de leer y devolver una línea completa desde un descriptor de archivo (file descriptor o fd), llamada tras llamada.

Esta herramienta resuelve un problema fundamental en la programación de bajo nivel: leer información de un archivo o de la entrada estándar (stdin) línea por línea de manera eficiente, sin necesidad de cargar todo el archivo en memoria y gestionando dinámicamente los saltos de línea (\n).

El mayor reto del proyecto consiste en comprender y aplicar el concepto de las variables estáticas en C, asegurando que no existan fugas de memoria (memory leaks) bajo ninguna circunstancia.

## Instrucciones
El código está desarrollado en lenguaje C y debe compilarse utilizando cc junto con las flags estrictas de compilación -Wall -Werror -Wextra.

La función utiliza la macro BUFFER_SIZE para determinar cuántos bytes se leen con cada llamada a la función del sistema read(). Este parámetro puede definirse dinámicamente durante la compilación mediante la flag -D BUFFER_SIZE=n.

Compilación básica:

cc -Wall -Werror -Wextra get_next_line.c get_next_line_utils.c 


## Recursos 
* **Recursos:** Páginas de Manual de C ('man'), referencias de la biblioteca estandar y seguimento estricto de La Norma. 
* **Uso de la IA:**Se usó la AI de forma bastante intensa, como apoyo para programar las funciones, entender la lógica interna de cada función y comprobaciones de compilación. 

## Estrtuctura del proyecto
El proyecto se compone de los siguientes archivos principales y auxiliares (tanto para la parte obligatoria como para la versión **bonus**):

* **Parte Obligatoria:**
  * `get_next_line.h` — Archivo de cabecera con macros y prototipos.
  * `get_next_line.c` — Lógica principal de lectura y gestión de la línea.
  * `get_next_line_utils.c` — Funciones auxiliares de manipulación de cadenas y memoria.

* **Parte Bonus:**
  * `get_next_line_bonus.h` — Cabecera adaptada para múltiples descriptores.
  * `get_next_line_bonus.c` — Lógica principal con soporte multipantalla/multidescriptor. 
  * `get_next_utils_bonus.c` — Funciones auxiliares de soporte para el bonus.

## Esquema 

```text
               get_next_line(fd)
                       │
                       ▼
                 reader(fd, pack)
              ┌────────┴────────┐
              │ Bucle de lectura│
              │   read(fd...)   │
              └────────┬────────┘
                       │
                       ▼
          join(pack, read_now, bytes)
                       │
                       ├──────────────────────────┐
                       ▼                          ▼
               ft_strjoin()                going_free()
                       │                          │
                       └───────────┬──────────────┘
                                   │
      ┌────────────────────────────┴────────────────────────────┐
      │  ¿Hay '\n' en pack (usando ft_strchr) o llegó al EOF?   │
      └────────────────────────────┬────────────────────────────┘
                                   │
                       ┌───────────┴───────────┐
                       ▼                       ▼
                   gline(pack)            nline(pack)
                   (ft_substr)            (ft_substr)
                       │                       │
                       ▼                       ▼
              Devuelve la línea          Actualiza la variable
               para el usuario           estática (pack)