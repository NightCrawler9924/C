//1 strcpy(dest, src) — Copy a string

#include <stdio.h>
#include <string.h>

int main() {
    char src[] = "Hello, World!";
    char dest[50];  // Make sure dest is large enough

    strcpy(dest, src);

    printf("Copied string: %s\n", dest);

    return 0;
}

//2 strlen(s) — Get the length of a string

#include <stdio.h>
#include <string.h>

int main() {
    char s[] = "Hello";

    printf("Length of string '%s' is %lu\n", s, strlen(s));

    return 0;
}


//3 strcat(dest, src) — Concatenate strings

#include <stdio.h>
#include <string.h>

int main() {
    char s1[50] = "Hello";
    char s2[] = ", World!";

    strcat(s1, s2);

    printf("Concatenated string: %s\n", s1);

    return 0;
}


//4 strcmp(s1, s2) — Compare two strings

#include <stdio.h>
#include <string.h>

int main() {
    char s1[] = "Apple";
    char s2[] = "Banana";

    int result = strcmp(s1, s2);

    if (result == 0) {
        printf("Strings are equal.\n");
    } else if (result < 0) {
        printf("'%s' comes before '%s'\n", s1, s2);
    } else {
        printf("'%s' comes after '%s'\n", s1, s2);
    }

    return 0;
}
