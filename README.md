# 0x19. C - Stacks, Queues - LIFO, FIFO
> **Holberton Proyect - Week 17**
***

### What do LIFO and FIFO mean?

* FIFO (“First In, First Out”)`: significa “primero en entrar, primero en salir”. Por ejemplo, este sistema es ideal para el almacenamiento de productor perecederos, que además de su colocación por gamas o familias, deberán ser colocados de tal forma que los primeros en salir sean los más próximos a su fecha de caducidad. Tambien estan los LILO (“Last In, Last Out").

* LIFO (“Last In, First Out”)`: significa “último en entrar, primero en salir”. Por ejemplo, este es el Sistema perfecto para aquellos productos no perecederos y que no tienen fecha de caducidad. Tambien estan los FILO (“First In, Last Out").
### What is a stack, and when to use it?
* Un stack una estructura donde almacenamos datos y lo usamos de 2 formas FILO(First-in Last-out) y LIFO(Last-in First-out) donde primero es acumulando una pila y se retiran los datos desde el ultimo ingresado. Use una pila cuando quiera sacar las cosas en el orden inverso al que las puso.

### What is a queue, and when to use it?
* Un Queue una estructura de datos y lo usamos de 2 formas FIFO(First-in First-out) y LILO(Last-in Last-out) donde primero es acumulando en queue y se retiran los datos desde el primer ingresado. Usa una cola cuando quieras sacar las cosas en el orden en que las pusiste.
        
### What are the common implementations of stacks and queues?
> More information:
        [Stack and Queue](https://es.slideshare.net/nieves1988/estructura-datos-pilas-y-colas)

`STACKS`: Arithmetic Expressions, Operations (Power, Multiplication, Divide, Addition, Subtraction, Infix Notation, Prefix Notation, Postfix Notation), Recursive Functions, Program Sequence Control (A subprogram runs completely before returning to the point where it was called).

`QUEUES`: There are 4 types of Queues:

  * `Simple Tail`: Linear structure where the elements leave in the same order in which they arrive.
  * `Circular Tail`: Logical Representation of a Simple Queue in an Array
  * `Priority Queue`: Linear structure in which the elements are inserted in any position of the queue and are removed only from the front.
  * `Double Tail`: Linear structure in which elements can be added or removed at either end of the tail.

  **Queue Implementation:**
    Arrangement, Linked Lists. 
                
### What are the most common use cases of stacks and queues?
 * `STACKS`: Expresiones Aritmeticas, Operaciones, Funciones Recursivas, Control de secuencia de Programas.
 * `QUEUES`: Arreglo, Listas Ligadas.

### What is the proper way to use global variables?
Global variables should be used when multiple functions need to access the data or write to an object. For example, if you had to pass data or a reference to multiple functions such as a single log file, a connection pool, or a hardware reference that needs to be accessed across the application. This prevents very long function declarations and large allocations of duplicated data.

You should typically not use global variables unless absolutely necessary because global variables are only cleaned up when explicitly told to do so or your program ends. If you are running a multi-threaded application, multiple functions can write to the variable at the same time. If you have a bug, tracking that bug down can be more difficult because you don't know which function is changing the variable. You also run into the problem of naming conflicts unless you use a naming convention that explicitly gives global variables a unique name.
***
