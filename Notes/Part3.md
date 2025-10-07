# C Programming Notes

_By Deepansh Sabharwal_

## Part 3 — Selection Statements, Loops, and Functions (Advanced)

---

Selection Statements

## C programs often need to make decisions based on conditions. Logical and relational expressions form the foundation for control flow.

## Logical Expressions
    
    C supports three categories of comparison operators:
    
    Relational operators → >, <, <=, >=
    Equality operators → ==, !=
    Logical operators → ! (NOT), && (AND), || (OR)

Example:

    if (!(x > y && z != 0))
        printf("Condition is false\n");

### Fact: Logical operators combine or invert conditions. The expression above prints only when both subconditions are false.

---

## The if Statement

Syntax:
    
    if (expression)
        statement;


Example:

    if (line_num == MAX_LINES)
        line_num = 0;


## When more than one statement is to be executed, use braces for grouping.

    if (line_num == MAX_LINES) {
        line_num = 0;
        page_num++;
    }

### Important: Always use braces {} even for single statements. This makes the code readable and prevents accidental logic errors.

---

## The else Clause
If the condition is false, the else block runs.

Example:

    if (i > j)
        max = i;
    else
        max = j;

## Cascaded if–else Example

    if (n < 0)
        printf("n is less than 0\n");
    else if (n == 0)
        printf("n is equal to 0\n");
    else
        printf("n is greater than 0\n");

### Important: In a cascaded chain, once a condition evaluates true, the rest are skipped automatically.
Loops

---

## Loops allow execution of statements repeatedly while a condition remains true.

## The while Loop

    i = 1;
    while (i < n)
        i = i * 2;

### Fact: The condition is evaluated before each iteration. If it is false at the start, the body never executes.

## The do–while Loop

    i = 10;
    do {
        printf("T minus %d and counting\n", i);
        --i;
    } while (i > 0);

    //Note The do–while loop always executes at least once, because the condition is checked after the loop body.

## The for Loop

    for (i = 10; i > 0; i--)
        printf("T minus %d and counting\n", i);


### The for loop structure combines initialization, condition, and update into one line.

---

### Important: You may omit any of the three parts (initialization, condition, update), but semicolons must remain in place to preserve syntax.
Loop Control Keywords

    ### break terminates the loop entirely, while continue skips the rest of the loop body for the current iteration and moves to the next cycle.

Example:

    for (i = 1; i <= 10; i++) {
        if (i == 5)
            continue;
        if (i == 8)
            break;
        printf("%d ", i);
    }

### Important: The break statement exits only the innermost loop. Nested loops require multiple conditions for full termination.
Functions (Advanced)

## Functions in C are self-contained blocks of code designed to perform a specific task. They may accept parameters and may or may not return a value.

Syntax

    return_type function_name(parameters)
    {
        declarations;
        statements;
    }


Example:

    double average(double a, double b)
    {
        return (a + b) / 2;
    }


### Here, double before average indicates the return type. Both parameters a and b are of type double.

### Fact: Each parameter requires an explicit data type. You cannot declare double a, b in the parameter list unless both are intended as doubles.

---

## Void Functions

Functions that do not return values are declared with void.

Example:
    
    /* Prints a countdown */
    #include <stdio.h>

    void print_count(int n)
    {
        printf("T minus %d and counting\n", n);
    }
    
    int main(void)
    {
        int i;
        for (i = 10; i > 0; --i)
            print_count(i);
        return 0;
    }

// Note When a function is called, its arguments are copied into the parameter variables. The originals remain unchanged unless pointers are used.
Return and Exit

**In addition to return, C provides the exit() function (defined in <stdlib.h>) for program termination.**

Example:
    
    #include <stdlib.h>
    
    if (error)
        exit(EXIT_FAILURE);
    else
        exit(EXIT_SUCCESS);


EXIT_SUCCESS and EXIT_FAILURE are macros that typically expand to 0 and 1, indicating successful or failed execution.

### Important: return inside main() and exit(EXIT_SUCCESS) are functionally equivalent, but exit() can be used from any function for immediate termination.
Summary

Selection statements allow conditional control, loops handle repeated execution, and functions organize code for modularity and reuse. Mastery of these concepts provides the foundation for structured program design in C.
