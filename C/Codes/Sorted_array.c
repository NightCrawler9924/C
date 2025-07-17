#include <stdio.h>
#define N 5

void sort_array(int a[], int b[]);  

int main(void)
{
    int a[N] = {4, 5, 2, 1, 6};
    int b[N];

    sort_array(a, b);

    printf("Sorted array: ");
    for (int i = 0; i < N; i++)
        printf("%d ", b[i]);

    return 0;
}

void sort_array(int a[], int b[])
{
    int used[N] = {0}; // keeps track of which elements we've already added to b[]

    for (int i = 0; i < N; i++)
    {
        int min = 9999;
        int min_index = -1;

        for (int j = 0; j < N; j++)
        {
            if (!used[j] && a[j] < min)
            {
                min = a[j];
                min_index = j;
            }
        }

        b[i] = min;
        used[min_index] = 1; // mark this value as used
    }
}
