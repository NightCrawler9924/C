#include <stdio.h>

int main() {
    char s[] = "Hello";
    int i;

    for (i = 0; s[i] != '\0'; i++) {
        printf("Character at index %d is %c\n", i, s[i]);
    }

    return 0;
}
