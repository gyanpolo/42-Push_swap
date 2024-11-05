# Push Swap

**Push Swap** es un proyecto de la Escuela 42 que tiene como objetivo implementar un programa en C capaz de ordenar una pila de números enteros utilizando un conjunto mínimo de operaciones. Este proyecto permite aplicar conocimientos de algoritmos y estructuras de datos, especialmente pilas y algoritmos de ordenación, y exige eficiencia tanto en el número de operaciones como en el uso de memoria.

## Objetivo

El objetivo de **Push Swap** es ordenar una pila de números enteros en orden ascendente con la ayuda de una pila auxiliar y utilizando únicamente un conjunto de operaciones específicas. El programa debe calcular la secuencia de operaciones más eficiente para minimizar el número de pasos necesarios para completar la ordenación.

## Descripción de Operaciones

El proyecto permite las siguientes operaciones para manipular las pilas `A` y `B`:

- **swap**: `sa` y `sb` intercambian los dos primeros elementos de la pila `A` o `B`.
- **push**: `pa` y `pb` mueven el elemento superior de `A` a `B` o viceversa.
- **rotate**: `ra` y `rb` rotan todos los elementos de `A` o `B` hacia arriba.
- **reverse rotate**: `rra` y `rrb` rotan todos los elementos de `A` o `B` hacia abajo.
- **dobles**: `ss`, `rr`, `rrr` son operaciones dobles que aplican `sa` y `sb`, `ra` y `rb`, o `rra` y `rrb` simultáneamente.

El programa debe utilizar estas operaciones para ordenar eficientemente los elementos de la pila `A`.

## Compilación

Para compilar el proyecto, utiliza el siguiente comando desde la terminal en el directorio raíz del proyecto:

```bash
make
