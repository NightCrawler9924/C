# C Programming Notes  
_By Deepansh Sabharwal_  

---

## Introduction  

C requires that each statement end with a semicolon `;`  
  
  Even the simplest C programs rely on three key language features: **directives**, **functions**, and **statements**.  
  Directives are editing commands that modify the program prior to compilation,  
  functions are named blocks of executable code, of which `main` is an example,  
  and statements are the commands executed when the program runs.  

### Fact C remains the foundation for many modern languages, providing the direct connection between software logic and machine-level operations.  

---

## Directives (`#`)  

Before a C program can be compiled, it must be edited by a **preprocessor**.  
Commands intended for the preprocessor are called **directives**.  

To compile a C program, the first line that should be present is  

    #include <stdio.h>
    C, unlike many higher-level languages, has no built-in Read or Write commands,
    so this inclusion provides input and output functionality.
    #Important All preprocessor directives begin with the # character and end without a semicolon.

Example:

    #include <stdio.h>   // standard input-output header
    #define PI 3.14159   // symbolic constant definition
    #define introduces constants or macros processed before compilation.

## Functions
Functions in C differ slightly from those in many other programming languages.
They fall into two categories: those written by the programmer, and those provided as part of the C implementation.
A function is a series of statements grouped together and given a name.
Among all, main is the most important function.

If main is a function, does it return a value? Yes — it returns a status code to the operating system when the program terminates.

Example:

    int main(void) {
        // statements go here
    }
    
  int before main indicates that the function returns an integer value,
  void inside parentheses indicates that main has no parameters.
  At the end of main, we write return 0;

  This causes the function to terminate and signals successful execution.
  If omitted, the program still ends, but some compilers issue a warning.

### Fact In hosted environments, return 0 and return EXIT_SUCCESS (from <stdlib.h>) both indicate normal termination.

## Printing and Comments
C uses the printf function for output.
  printf("Hello World\n");
  printf comes from <stdio.h> and supports format specifiers like %d, %f, %s.
  Always use \n to move to the next line when printing.
  Comments
  Single-line comments use //,
  Multi-line comments use /* ... */.
  
Example:

    printf("My ");
    /* forgot to close this comment
    printf("cat ");
    printf("has "); */ printf("fleas");
    This prints My fleas because the compiler ignores everything between /* and */.
    
### Important Never forget to close multi-line comments — unclosed comments cause the compiler to skip code unintentionally.

## Incorrect printf Usage

    printf("%d\n", i, j); /* WRONG */
    
Only the first argument after the format string (i) is printed. Extra arguments are ignored.

## Alternative Printing Methods
    Later in advanced libraries, functions like get_string() and printf() can combine for dynamic I/O:
    string answer = get_string("What is your name? ");
    printf("Hello %s\n", answer);
    
  %s is used for strings, just as %d and %f are used for integers and floats respectively.
  #Fact C’s I/O model is function-based, not syntax-based — no built-in read or write statements exist as in Python or Java.

## Variables and Assignments
  A variable is a named memory location used to store data.
  The type of the variable determines the size and kind of value it can hold.
  
Example declarations:
    
    int height;
    float marks;
    Correct assignment order:
    int height;
    height = 8;
    Incorrect order:
    height = 9;
    int height;
    For floating-point literals, append f:
    float profit = 2150.48f;


### Important The order of declaration and assignment matters — a variable must exist before it can store data.

## Constants
Numbers like 8 and 9 are constants.
Use #define to create named constants processed before compilation:

    #define PI 3.14159
    No semicolon is used after #define statements.
    Variable Types
    int → integer values,
    float → real numbers with decimals,
    char → single characters,
    double → extended precision floating-point values.
    
### Fact Arithmetic on float variables may be slower than on int variables due to hardware conversion overhead.

Example Program — Volume of a Cylinder
    Identify each variable, compute, and print the volume.
    #include <stdio.h>
    #define PI 3.14159
    
    int main(void) {
        float radius, height, volume;
        radius = 3.0f;
        height = 10.0f;
        volume = PI * radius * radius * height;
        printf("The volume is: %f\n", volume);
        return 0;
    }
    
### Important When printing numeric results, use placeholders: %d for integers, %f for floats.
Practical Example — Fahrenheit to Celsius Converter
Demonstrates user input, constants, and formatted output.

    #include <stdio.h>
    #define FREEZING_POINT 32.0
    #define SCALE_FACTOR (5.0/9.0)
    
    int main(void) {
        float fahrenheit, celsius;
        printf("Enter temperature in Fahrenheit: ");
        scanf("%f", &fahrenheit);
        celsius = (fahrenheit - FREEZING_POINT) * SCALE_FACTOR;
        printf("Temperature in Celsius: %.1f\n", celsius);
        return 0;
    }
### Fact This exercise highlights user input handling, constant definition, and control over numeric precision.

