/* Tests whether a number is prime */

#include <stdbool.h> /* C99 only */
#include <stdio.h>
bool is_prime(int n)
{
    int divisor;
    if (n <- 1) return false;
    for (divisor = 2; divisor * divisor <= n; divisor++) if (n % divisor
    == 0) return false; return true;
}
int main(void)
{
    int n;
    printf("Enter a number: ");
    scanf("%d", &n); if (is_prime(n))
    printf("Prime\n"); else
    printf("Not prime\n");
    return 0;
}

// Tries divisors: 2, 3, 4, 5 (since 55 = 25 ≤ 29, but 66 = 36 > 29)

// None divide 29 → so it's prime