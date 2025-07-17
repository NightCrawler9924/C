#include <stdio.h> 
int main(void)
{
    int num1, num2, denom1, denom2, resultnum, resultdem, result;
    printf("Enter first fraction: \n");
    scanf("%d/%d" , &num1 , &denom1);

    printf("Enter second fraction: \n");
    scanf("%d/%d" , &num2 , &denom2);

    resultnum = num1*denom2 + num2*denom1;
    resultdem = denom1*denom2;
    printf("The result is: %d/%d" , resultnum, resultdem);

}