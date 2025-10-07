#include <stdio.h>

int main(void)
{
    int num1, result;
    printf("Enter a number: ");
    scanf("%d", &num1);

    int last_digit = num1 % 10;
    int first_digit = num1 / 10;

    result = last_digit * 10 + first_digit;

    printf("The reversed number is: %d\n", result);

    return 0;
}
