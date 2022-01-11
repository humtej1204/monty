# 0x18. C - Dynamic libraries
> **Holberton Proyect - Week 17**
***

### What do LIFO and FIFO mean?
* FIFO (“First In, First Out”) `: means “first in, first out”. For example, this system is ideal for the storage of perishable producers, which in addition to their placement by ranges or families, must be placed in such a way that the first to come out are the closest to their expiration date. There are also the LILO ("Last In, Last Out").

* LIFO (“Last In, First Out”) `: means “last in, first out”. For example, this is the perfect system for non-perishable products that do not have an expiration date. There are also the FILO ("First In, Last Out").

### What is a stack, and when to use it?
* Stack is a structure where we store data and use it in 2 ways FILO (First-in Last-out) and LIFO (Last-in First-out) where a stack is first accumulated and the data is removed from the last input. Use a battery when you want to take things out in the reverse order you put them in.

### What is a queue, and when to use it?
* Queue is a data structure and we use it in 2 ways FIFO (First-in First-out) and LILO (Last-in Last-out) where first it is accumulating in the queue and the data is removed from the first input. Use a tail when you want to take things out in the order you put them in.
        
### What are the common implementations of stacks and queues?
> More information:
        [Stack and Queue](https://es.slideshare.net/nieves1988/estructura-datos-pilas-y-colas)

`STACKS`: Arithmetic Expressions, Operations (Power, Multiplication, Divide, Addition, Subtraction, Infix Notation, Prefix Notation, Postfix Notation), Recursive Functions, Program Sequence Control (A subprogram runs completely before returning to the point where it was called).


`QUEUES`: There are 4 types of Queues:

  * `Simple Tail`: Linear structure where the elements leave in the same order in which they arrive.

  * `Circular Tail`: Logical Representation of a Simple Queue in an Array

  * `Priority Queue`: Linear structure in which the elements are inserted in any position of the queue and are removed only from the front.
        
  * `Double Tail`: Linear structure in which elements can be added or removed at either end of the tail.

  **Queue Implementation**: Arrangement, Linked Lists.

### What are the most common use cases of stacks and queues?
 * `STACKS`: Arithmetic Expressions, Operations, Recursive Functions, Program Sequence Control.
 * `QUEUES`: Arrangement, Linked Lists.

### What is the proper way to use global variables?
Global variables should be used when multiple functions need to access the data or write to an object. For example, if you had to pass data or a reference to multiple functions such as a single log file, a connection pool, or a hardware reference that needs to be accessed across the application. This prevents very long function declarations and large allocations of duplicated data.

You should typically not use global variables unless absolutely necessary because global variables are only cleaned up when explicitly told to do so or your program ends. If you are running a multi-threaded application, multiple functions can write to the variable at the same time. If you have a bug, tracking that bug down can be more difficult because you don't know which function is changing the variable. You also run into the problem of naming conflicts unless you use a naming convention that explicitly gives global variables a unique name.
