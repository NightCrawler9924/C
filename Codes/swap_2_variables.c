#include <stdio.h>

void swap2var(int *a, int *b)
{
    //swapping
    int swap;
    swap = *a;
    *a = *b;
    *b = swap;
}

int main(void)
{
    int x = 5; int y = 99;

    printf("The original value for x is: %d and y is: %d\n", x,y);

    swap2var(&x,&y);

    printf("The new value for x is: %d and y is: %d\n", x,y);
}