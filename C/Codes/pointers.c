//We'll see how to create a pointer and its various methods
   //For better understanding/revision, refer notes on C


#include <stdio.h>

// Function declaration: receives 3 numbers and two pointers
// It finds the max and min among x, y, z and stores them via pointers
void max_min(int x, int y, int z, int *max, int *min);

int main(void)
{
    int a, b, c;        // variables to store user input
    int big, small;     // variables to store max and min

    // Prompt the user to enter 3 numbers
    printf("Enter 3 numbers: ");
    scanf("%d %d %d", &a, &b, &c);   // Read the 3 numbers

    // Call the function, passing input values and addresses of big and small
    max_min(a, b, c, &big, &small);

    // Print the results returned via pointer arguments
    printf("Largest: %d\n", big);
    printf("Smallest: %d\n", small);

    return 0;
}

// Function definition
void max_min(int x, int y, int z, int *max, int *min)
{
    // Start by assuming x is both the max and min
    *max = *min = x;

    // Compare y with current max and min
    if (y > *max)
        *max = y;
    if (y < *min)
        *min = y;

    // Compare z with current max and min
    if (z > *max)
        *max = z;
    if (z < *min)
        *min = z;
}
