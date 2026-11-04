*Este proyecto ha sido creado como parte del currículo de 42 por acornia y lesainz*

## Descripción

El proyecto **Push_swap** es un algoritmo de ordenación muy desafiante. Consiste en ordenar una pila de números enteros (`stack a`) utilizando una segunda pila auxiliar (`stack b`) y un conjunto limitado de operaciones, con el objetivo de utilizar el menor número de movimientos posibles.

## Instrucciones
El proyecto incluye un `Makefile` con las reglas estándar. Para compilar el programa principal, ejecuta:
Para compilar debes
| Comando | Descripción |
| :--- | :--- |
| `make` | Compila la parte obligatoria y genera un nuevo archivo llamado 'libft.a'. Todas las funciones programadas en (.c) generan un archivo objeto (.o) correspondiente.|
| `make clean` | Elimina todos los archivos objeto (.o) que generamos al ejecutar 'make'. |
| `make fclean` | Elimina todos los archivos objeto (.o) y la libreria estática(libft.a) que generamos al ejecutar 'make'.|
| `make re` | Hace una limpieza totall y vueve a compilar todo desde cero.|

## Recursos 
* **Recursos:** Para comprender la lógica de las operaciones, la gestión de pilas y los distintos algoritmos de ordenación aplicables a este proyecto, puedes consultar los siguientes recursos 
* **Uso de la IA:** Se usó la AI de forma moderada, como apoyo para programar las funciones, entender la lógica interna de cada función y comprobaciones de compilación. 

## Algoritmos
**simple:** Métodos simples de extracción del mínimo/máximo. Lo lleva al stack b mediante rotaciones y la instrucción pb de forma repetida hasta vaciar el stack a (o dejar los 3 elementos base). Luego en el stack b los devuelve al stack a ordenados mediante la instrucción pa. 

**medium:** Orden basado en chunks (dividiendo en √n chunks):
1. **División en bloques:** Se agrupan los números normalizados en $k$ rangos (o *chunks*) de tamaño fijo
2. **Envío a la pila B:** Se recorre la pila `a` buscando los elementos que pertenecen al bloque activo y se pasan a la pila `b` mediante la instrucción `pb` (optimizando las rotaciones con `ra` o `rra`). 
3. **Devolución ordenada a la pila A:** Una vez que todos los datos están en la pila `b`, se busca de forma iterativa el **valor máximo**, se lleva a la cima de la pila más rápido posible y se devuelve a la pila `a` con `pa` hasta dejarla completamente ordenada.

**complex:** Pensado para listas grandes o con un índice de desorden alto, implementa un enfoque optimizado basado en el **Turk Algorithm** o particionamiento avanzado:
* **Cálculo de Costes:** Evalúa de manera dinámica el coste en movimientos (rotaciones combinadas como `rr` o `rrr`) de cada elemento de la pila `A` para insertarlo en la posición óptima de la pila `B`.
* **Inserción y Retorno:** Minimiza drásticamente el número total de operaciones para asegurar una complejidad temporal de $O(n \log n)$.


**adaptative:** El programa calcula el **índice de desorden** de la pila de entrada *antes de realizar ningún movimiento* para seleccionar automáticamente la estrategia más eficiente:
* **Desorden Bajo (< 0.2):** Emplea movimientos directos y rápidos orientados a secuencias casi ordenadas.
* **Desorden Medio ($0.2 \le \text{desorden} < 0.5$):** Aplica el algoritmo intermedio basado en **chunks** ($O(n\sqrt{n})$).
* **Desorden Alto ($\ge 0.5$):** Activa de forma automática el **algoritmo complejo** ($O(n \log n)$) para garantizar el rendimiento óptimo ante conjuntos caóticos.
