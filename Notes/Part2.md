# C Programming Notes  
_By Deepansh Sabharwal_  

---

## Part 2 — Input, Scanf, Expressions  

---

## Taking User Input  

### C provides the `scanf` function for formatted input.  

Syntax:
  scanf("format_string", &variable);
  In place of "format_string", we use %d for integers, %f for floats, %s for strings, etc.

Example:
    
    int age;
    float salary;
    scanf("%d%f", &age, &salary);

### Important The & operator before a variable passes its address, allowing the function to store the user’s input directly in that memory location.

### Fact In C, almost every input or output function uses pointers implicitly or explicitly.

Defining Default Values
Use #define to declare symbolic constants that don’t require semicolons.

Example:

    #define FREEZING_POINT 32.0
    #define SCALE_FACTOR (5.0/9.0)
    
### Important #define values are replaced by the preprocessor before compilation, so they occupy no memory at runtime.

Escape Sequences
Escape Sequence	Description

    \n	New line
    \t	Horizontal tab
    \b	Backspace
    
### Fact Escape sequences are processed at compile time, not runtime, meaning they alter literal string interpretation.

## scanf in Detail

Example:
    
    int i, j;
    float x, y;
    scanf("%d%d%f%f", &i, &j, &x, &y);
    If the user enters:
    1 -20 .3 -4.0e3
    Then the values assigned are:
    i = 1, j = -20, x = 0.3, y = -4000.0.
    
### Important “Tightly packed” format strings like "%d%d%f%f" are common in scanf, but in printf, format specifiers are usually separated by text or spacing.

## Incorrect Use
You cannot include text inside a scanf format string.

Example:
    
    scanf("Enter number: %d", &i); /* WRONG */
    The function expects input only in the specified format, not descriptive text.
    
### Fact Many professional C programmers avoid scanf, preferring to read data as strings and convert it manually for greater control.

## How scanf Parses Input
  If the first character is 1 and the second is - with format %d, the - is pushed back into the input stream, storing only 1.
  If input is -20.3 with %d, the .3 is ignored because integers can’t contain decimal points.
  If input is .3- with %f, the negative sign after digits is invalid and discarded.
  
### Important The scanf function stops reading when an invalid character for the format is found.

Example Reference: Adding2fractions.c

## Expressions
An expression in C combines variables, constants, and operators to compute a value.
  Arithmetic Operators
  +	Addition	Unary + emphasizes positivity
  -	Subtraction	Unary - negates the operand
  *	Multiplication	—
  /	Division	Integer division truncates
  %	Modulus	Works only with integers

### Important When both operands of / are integers, the result truncates — fractional parts are dropped.

    Example: 1 / 2 = 0
    
## The % operator requires integer operands.

Example:

    int r = 10 % 3; // r = 1
    #Fact In C99, division always truncates toward zero, and the remainder from % has the same sign as the dividend.

Example:
    
    -9 / 7 = -1
    -9 % 7 = -2
    
Assignment Operator
  Assignment is also an operator in C, not a statement keyword.
  This allows chaining of multiple assignments.
  i = j = k = 0;
  Right associative, equivalent to:
  i = (j = (k = 0));
  #Fact This executes right-to-left: k becomes 0, then j, then i.
  Compound Assignments
  i = i + 2;
  can be written as
  i += 2;
  
### Important Compound assignments are also right-associative.

Example:

    i += j += k;
    is equivalent to
    i += (j += k);
    
Increment and Decrement Operators
  C provides two unary operators for modifying variable values.
  Form	Meaning
  ++i	Pre-increment
  i++	Post-increment
  --i	Pre-decrement
  i--	Post-decrement
  
Example:

    i = 1;
    j = 2;
    k = ++i + j++;
    Step-by-step:
    i = i + 1;  // i becomes 2
    k = i + j;  // k = 2 + 2 = 4
    j = j + 1;  // j becomes 3
    Final values: i = 2, j = 3, k = 4.
    
### Fact Using increment and decrement multiple times in the same expression leads to undefined behavior due to sequencing rules.

Alternate Example

    i = 1;
    j = 2;
    k = i++ + j++;
    
After execution:
    i = 2, j = 3, k = 3.
    
### Important The pre-increment version updates before use, the post-increment version updates after use.

Precedence Table Reference
  Operators in C are evaluated based on precedence (priority) and associativity.
  High precedence first, same-level operators follow left to right, except assignment, which is right to left.

### Fact Understanding precedence prevents logic errors when combining arithmetic, logical, and assignment operations.

Example — Expression Evaluation

    a = 5;
    b = a + 2;
    a = 1;
    c = b - a;
    Final value of c will always be 6.
    
### Important Always trace sequential assignment carefully — the last written value overrides previous ones.
