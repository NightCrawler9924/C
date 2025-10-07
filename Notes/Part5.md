# C Programming Notes

_By Deepansh Sabharwal_

Part 5 — Strings and Libraries

--- 

## Introduction to Strings

In C, strings are arrays of characters terminated by a special null character '\0'.
A string can be defined using double quotes, for example "Hello".

When a C compiler encounters a string literal of length n, it allocates n + 1 bytes — one extra for the null terminator.

Example

    char name[] = "Deepansh";


This defines an array of characters containing 'D', 'e', 'e', 'p', 'a', 'n', 's', 'h', and '\0'.

## Fact: Strings in C are stored as contiguous arrays, not as standalone objects like in higher-level languages.

--- 

## String Initialization

A string variable can be initialized in two common ways:
    
    char date[] = "June 14";
    char *date_ptr = "June 14";


The first declares an array containing the characters, while the second creates a pointer to a string literal in memory.

### Important: String literals are typically stored in read-only memory. Attempting to modify them through a pointer causes undefined behavior.

Incorrect example:
    
    char *p;
    p[0] = 'a';  /* WRONG */
    p[1] = 'b';
    p[2] = 'c';
    p[3] = '\0';


Since p is uninitialized, its memory destination is unknown, leading to program crashes or data corruption.

--- 

## String Output and Formatting

C uses the %s format specifier in printf for printing strings.

Example:

    printf("Hello %s\n", name);

### Note: As with numbers, %s expects a null-terminated string. Without '\0', the output will continue reading memory until it hits a random zero byte.

Continuing a String Literal

Long strings in C can be split over multiple lines for readability.

Example using backslash continuation:

    printf("When you come to a fork in the road, take it. \
    --Yogi Berra");

### Fact: The backslash \ joins two lines into a single logical line at compile time.

A clearer alternative uses adjacent string literals:

    printf("When you come to a fork in the road, take it. "
    "--Yogi Berra");


Both strings are automatically concatenated by the compiler.

Reading Strings from Input

      Using scanf
      char word[20];
      scanf("%s", word);


### scanf("%s", ...) reads input until the first whitespace (space, tab, or newline). It cannot handle spaces within strings.

---

## Using fgets
char sentence[100];
fgets(sentence, sizeof(sentence), stdin);


fgets() reads input until a newline \n or until the buffer is full, including spaces, and stores the newline character as part of the string.

Example input:

    To C, or not to C: that is the question.


Results:

    scanf("%s", sentence); → stores "To"

fgets(sentence, sizeof(sentence), stdin); → stores "To C, or not to C: that is the question.\n"

### Important: fgets is safer for multi-word input because it prevents buffer overflow and preserves spacing.

---

## Accessing Characters in a String

Strings can be accessed character-by-character using indexing.

Example:

    char s[] = "Hello";
    printf("%c", s[1]);  // prints 'e'


You can loop through characters using:

    for (int i = 0; s[i] != '\0'; i++)
        printf("%c", s[i]);

### Fact: String indices start from 0, and iteration stops when '\0' is reached.

### Important: Always check array bounds when working with strings to avoid reading or writing outside valid memory.

---

## The <string.h> Library

C provides the <string.h> header with useful functions for string manipulation.

1. strcpy(dest, src) — Copy a String

  Copies the contents of src into dest, including the null terminator.
  
  Example:
    
    char src[] = "Welcome";
    char dest[20];
    strcpy(dest, src);

### Important: Ensure dest is large enough to hold src plus the '\0' character. Overflow leads to undefined behavior.

---

2. strlen(s) — Find String Length

  Returns the number of characters in the string s, excluding the null terminator.
  
  Example:
  
    printf("%zu\n", strlen("Deepansh"));  // Output: 8

### Fact: strlen performs a character-by-character scan until '\0' is found.

---

3. strcat(dest, src) — Concatenate Strings

  Appends the string src to the end of dest.
  
  Example:
  
    char a[30] = "Hello ";
    char b[] = "World";
    strcat(a, b);
  
  
  Result: a becomes "Hello World".

### Important: Like strcpy, ensure dest has enough space to hold both strings.

---

4. strcmp(s1, s2) — Compare Strings
  
  Compares two strings lexicographically.
  
  Return values:
  
  0 → strings are equal,
  
  Negative value → first string is smaller,
  
  Positive value → first string is greater.
  
  Example:
  
    if (strcmp("apple", "banana") < 0)
        printf("apple comes before banana");

### Note: String comparison is case-sensitive. "Apple" and "apple" are considered different.

---

# Summary

    Strings are arrays of characters terminated by '\0'.
    
    Always allocate sufficient space for string data plus one extra byte for the terminator.
    
    Use fgets instead of scanf for reading strings containing spaces.
    
    The <string.h> library provides standard operations for copying, concatenating, comparing, and measuring strings.

Improper pointer use or missing terminators can cause undefined behavior and program crashes.

---

# End of Notes
# C Programming Complete Guide by Deepansh Sabharwal
