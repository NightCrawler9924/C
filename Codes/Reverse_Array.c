#include <stdio.h>
#define N 5

void reverse_array(int a[], int b[]);  // Use array notation for clarity

int main(void)
{
    int a[N] = {1, 2, 3, 4, 5};
    int b[N];

    reverse_array(a, b);

    printf("Original array: ");
    for (int i = 0; i < N; i++)
        printf("%d ", a[i]);

    printf("\nReversed array: ");
    for (int i = 0; i < N; i++)
        printf("%d ", b[i]);

    return 0;
}

void reverse_array(int a[], int b[])
{
    for (int i = 0; i < N; i++)
        b[i] = a[N - 1 - i];  // Straightforward reversal using indices
}
