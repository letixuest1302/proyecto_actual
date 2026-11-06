*Este proyecto ha sido creado como parte del currículo de 42 por acornia y lesainz*

## Descripción
El proyecto **Push_swap** es un algoritmo de ordenación muy desafiante. Consiste en ordenar una pila de números enteros (`stack a`) utilizando una segunda pila auxiliar (`stack b`) y un conjunto limitado de operaciones, con el objetivo de utilizar el menor número de movimientos posibles.

## Instrucciones
El proyecto incluye un `Makefile` con las reglas estándar. Para compilar el programa principal, ejecuta:

Para compilar debes

| Comando | Descripción |
| :--- | :--- |
| `make` | Compila la parte obligatoria y genera un ejecutable llamado 'push_swap'. Todas las funciones programadas en (.c) generan un archivo objeto (.o) correspondiente.|
| `make clean` | Elimina todos los archivos objeto (.o) que generamos al ejecutar 'make'. |
| `make fclean` | Elimina todos los archivos objeto (.o) y el ejecutable (push_swap) que generamos al ejecutar 'make'.|
| `make re` | Hace una limpieza total y vueve a compilar todo desde cero.|

## Recursos 
* **Recursos:** Para comprender la lógica de las operaciones, la gestión de pilas y los distintos algoritmos de ordenación aplicables a este proyecto, puedes consultar los siguientes recursos 
* **Uso de la IA:** Se usó la AI de forma moderada, como apoyo para programar las funciones, entender la lógica interna de cada función y comprobaciones de compilación. 

## Contribuciones de cada estudiante
**Antonio:** Se encargo de los movimientos, bench utils, Makefile y algoritmos. 

**Leticia(Emily):** Se encargo del parser, readme y algoritmos.
## Operaciones 
| Operación | Efecto |
| :--- | :--- |
| `sa` / `sb` / `ss` | Intercambia los dos primeros elementos de `a`, de `b` o de ambas. |
| `pa` / `pb` | Pasa el primer elemento de `b` a `a` (`pa`) o de `a` a `b` (`pb`). |
| `ra` / `rb` / `rr` | Rotación hacia arriba: el primer elemento pasa a ser el último. |
| `rra` / `rrb` / `rrr` | Rotación hacia abajo: el último elemento pasa a ser el primero. |

## Algoritmos
**Simple:** Métodos simples de extracción del mínimo/máximo.
1. Se fija en el número con mayor índice.
2. Lo lleva al stack b mediante rotaciones y la instrucción pb de forma repetida hasta vaciar el stack a (o dejar los 3 elementos base).
3. Luego en el stack b los devuelve al stack a ordenados mediante la instrucción pa. 

**Medium:** Orden basado en chunks (dividiendo en √n chunks):
1. **División en bloques:** Se agrupan los números normalizados en $k$ rangos (o *chunks*) de tamaño fijo
2. **Envío a la pila B:** Se recorre la pila `a` buscando los elementos que pertenecen al bloque activo y se pasan a la pila `b` mediante la instrucción `pb` (optimizando las rotaciones con `ra` o `rra`). 
3. **Devolución ordenada a la pila A:** Una vez que todos los datos están en la pila `b`, se busca de forma iterativa el **valor máximo**, se lleva a la cima de la pila más rápido posible y se devuelve a la pila `a` con `pa` hasta dejarla completamente ordenada.

**Complex:** Pensado para listas grandes o con un índice de desorden alto, implementa un enfoque optimizado basado en el **Radix (LSD)**.
1. Calcula la cantidad de bits necesaria.
2. Realiza un bucle fijandose bit a bit agrupandolos si los bits son 1 o 0.
3. Repetimos el bucle hasta que este ordenado. 

**Adaptative:** Antes de mover nada se calcula el **índice de desorden** de la pila: la proporción de parejas de elementos que están en el orden equivocado respecto al total de parejas.
 
Va de `0.0` (ordenada) a `1.0` (completamente al revés). Según su valor se elige el algoritmo:
 
| Desorden | Algoritmo | Complejidad |
| :--- | :--- | :--- |
| `< 0.2` | Simple | O(n²) |
| `0.2 ≤ d < 0.5` | Medium (chunks) | O(n√n) |
| `≥ 0.5` | Complex (radix) | O(n log n) |

## Esquema del proyecto
```
├── Makefile
├── push_swap.h
├── main.c                  # Lectura de flags y flujo principal
├── moves/                  # Las 11 operaciones (sa, pb, ra, rrr...)
│   ├── swap.c
│   ├── Push.c
│   ├── Rotate.c
│   └── ReverseRotate.c
├── parser/                 # Validación y carga de la pila
│   ├── parse_args.c
│   ├── parse.c
│   ├── is_sorted.c         # is_sorted y disorder_index
│   └── error.c             # Error y liberación de memoria
├── sort_algorithms/        # Los algoritmos de ordenación
│   ├── adaptative_sort.c
│   ├── simple_sort.c
│   ├── medium_sort.c
│   ├── complex_sort.c
│   └── sort_utils.c
└── split/                  # ft_split y funciones auxiliares
    ├── split.c
    ├── split_utils.c
    └── split.h
```