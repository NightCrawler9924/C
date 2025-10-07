#include <stdio.h>

int main(void)
{
    int i, j, num;

    printf("Enter the number till where I should print prime numbers: ");
    scanf("%d", &num);

    for(i = 2; i <= num; i++)         // Loop over numbers from 2 to num
    {
        for(j = 2; j < i; j++)        // Check if i is divisible by any number from 2 to i-1
        {
            if(i % j == 0)            // If i is divisible by j, it's not prime
                break;                // Stop checking further
        }

        if(j == i)                    // If loop ran fully (no break), j will equal i
            printf("%d ", i);         // So i is prime, print it
    }

    return 0;
}
