# C Programming Notes

_By Deepansh Sabharwal_

## Part 4 — Scope and Pointers (Basic to Advanced)

---

## Variable Scope

  Variables in C have specific visibility ranges, called scope.

## There are two main kinds: local and global.

Global variables are declared outside all functions, making them accessible throughout the program.
Local variables are declared inside a function and exist only within that function.

Example:

    int global_count = 5;
    
    void display() {
        int local_count = 10;
        printf("%d\n", global_count + local_count);
    }


  If both a global and a local variable share the same name, the local variable overrides the global one within that function.

### Fact: Global variables are stored in memory for the program’s entire lifetime, whereas local variables exist only during the function’s execution.

### Important: Use global variables sparingly. They make debugging difficult and reduce modularity.

Reference: scope_global_local.c

---

## Pointers — Introduction

In modern systems, main memory is divided into bytes. Each byte has a unique numeric address, allowing direct memory access.
A pointer is a variable that stores the memory address of another variable.

Example declaration:

    int *p;
    float *q;
    char *r;


This means: p points to an integer, q points to a float, and r points to a character.

### You can assign a pointer to the address of a variable using the address operator &.

Example:
    
    int i = 5;
    int *p = &i;

  Here, p holds the address of i.

### Fact: Pointers allow indirect access to variables, letting you read or modify values stored elsewhere in memory.


## The Indirection Operator *

Once a pointer is assigned to a variable’s address, you can access or change its value using the indirection operator *.

Example:

    int i = 42;
    int *p = &i;
    printf("%d\n", *p);


 ###This prints the value of i, not its address.

### If we later write *p = 100;, the value of i changes to 100.

### Important: Never apply * to an uninitialized pointer. Dereferencing an undefined pointer leads to undefined behavior, which can crash the program or cause data corruption.

Example of wrong usage:

    int *p;
    printf("%d", *p); /* WRONG — p not initialized */

---

## Pointer Assignment

### Pointer assignment copies addresses, not values.

Example:

    int i = 10;
    int *p = &i;
    int *q;
    q = p;


Now both p and q point to the same variable i.
If *p is modified, *q reflects the same change because they share the same address.

### Fact: Pointer variables can be assigned to one another only if they point to the same data type.

---

## Pointers as Function Arguments

  Pointers allow functions to modify variables defined outside their scope.
  This is useful when returning multiple results from a single function.

  Example — Finding maximum and minimum values:

      void max_min(int x, int y, int *max, int *min)
      {
          if (x > y) {
              *max = x;
              *min = y;
          } else {
              *max = y;
              *min = x;
          }
      }


Function call:

    int a = 5, b = 8, high, low;
    max_min(a, b, &high, &low);
    

### Important: Always pass addresses (&variable) when expecting pointer parameters in a function.
Dereference inside the function using *pointer to modify the original variable.

Reference: min_max_pointers.c

Example — Swapping Two Variables Using Pointers

    void swap(int *x, int *y)
    {
        int temp = *x;
        *x = *y;
        *y = temp;
    }
    
    int main(void)
    {
        int a = 3, b = 7;
        swap(&a, &b);
        printf("%d %d", a, b);
    }

###Fact: This approach swaps the original variables, not just local copies, because the function directly accesses their memory locations.

Reference: swap_2_variables.c

---

## Pointer Arithmetic

  C supports limited arithmetic operations on pointers.
  When a pointer moves, it advances by the size of the data type it points to, not by one byte.
  
  Valid pointer arithmetic operations include:
  
  Adding an integer to a pointer,
  
  Subtracting an integer from a pointer,
  
  Subtracting one pointer from another.

Example:

    int a[10];
    int *p = &a[5];
    int *q = &a[1];
    int i = p - q;  // i = 4


  Here, p - q gives the number of elements between them, not the byte distance.

## Note:Comparisons like p < q or p > q are valid only if both pointers refer to elements within the same array.

---

## Pointer and Arrays

A pointer can refer to array elements, and pointer arithmetic allows traversal of the array.

Example:

    #define N 10
    int a[N], sum = 0;
    int *p;
    
    for (p = &a[0]; p < &a[N]; p++)
        sum += *p;


**Each iteration increments p to the next element.
*p gives access to the current value stored in that array location.**

### Fact: Array names in C act as constant pointers to their first elements, meaning a is equivalent to &a[0].
  
## Pointers to Compound Literals
  
  Compound literals allow you to create unnamed arrays directly within expressions.

Example:

    int *p = (int []){3, 0, 3, 4, 1};


Here, p points to the first element of a temporary array containing {3, 0, 3, 4, 1}.

Equivalent code without compound literal:
    
    int a[] = {3, 0, 3, 4, 1};
    int *p = &a[0];

###Important: Compound literals are especially useful in function arguments, avoiding separate array declarations.

Summary
    
    Scope defines where variables are visible and how long they exist.
    
    Pointers store addresses, enabling direct memory manipulation.
    
    Dereferencing * accesses the value stored at a memory address.
    
    Pointer arithmetic enables array traversal efficiently.
    
    Passing pointers to functions allows modification of original variables.
    
    Understanding scope and pointers is essential for mastering data structures, memory management, and modular programming in C.
