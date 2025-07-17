#include <stdio.h>
int add_c(int a, int b)
{
    return (a+b);
}
int sub_c(int a, int b)
{
    return (a-b);
}
int multi_c(int a, int b)
{
    return (a*b);
}
int div_c(int a, int b)
{
    if(b!=0)
    {
    return (a/b);
    }else{
        printf("Not defined");
        return 0;
    }
}

int main(void)
{
    int option, num1, num2, result;

    printf("Welcome! Please choose one of the following options:\n");
    printf("1 for Addition (+)\n");
    printf("2 for Subtraction (-)\n");
    printf("3 for Multiplication (x)\n");
    printf("4 for Division (/)\n");

    printf("Enter your choice: ");
    scanf("%d", &option);  

    printf("Enter the first number: ");
    scanf("%d", &num1);    

    printf("Enter the second number: ");
    scanf("%d", &num2);   

    if (option == 1) {
        result = add_c(num1,num2);
        printf("The result is: %d\n", result);
    } else if (option == 2) {
        result = sub_c(num1,num2);
        printf("The result is: %d\n", result);
    } else if (option == 3) {
        result = multi_c(num1,num2);
        printf("The result is: %d\n", result);
    } else if (option == 4) {
        result = div_c(num1,num2);
        printf("The result is: %d\n", result);
    } else {
        printf("Invalid option.\n");
    }

    return 0;
}
