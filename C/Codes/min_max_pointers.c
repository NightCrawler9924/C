#include <stdio.h>

// Function to find min and max among 4 numbers using pointers
void min_max_4(int x, int y, int z, int r, int *max, int *min);

int main(void)
{
    int a, b, c, d;
    int big, small;

    printf("Enter 4 numbers: ");
    scanf("%d %d %d %d", &a, &b, &c, &d);  // Removed \n

    min_max_4(a, b, c, d, &big, &small);

    printf("Largest number: %d\n", big);
    printf("Smallest number: %d\n", small);

    return 0;
}

void min_max_4(int x, int y, int z, int r, int *max, int *min)
{
    *max = *min = x;  // Start with x as both max and min

    // Compare y
    if (y > *max) *max = y;
    if (y < *min) *min = y;

    // Compare z
    if (z > *max) *max = z;
    if (z < *min) *min = z;

    // Compare r
    if (r > *max) *max = r;
    if (r < *min) *min = r;
}
