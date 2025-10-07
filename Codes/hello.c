#include <stdio.h> 
int main(void)
{
    float length = 8.5f; float width = 8.1f; int height = 9;
    float volume;
    volume = length * width * height;
    printf("The volume is: %f " ,volume);

    //taking input
    int age;
    scanf("%d", &age);
    printf("the age is %d" , age);
    return 0;
}

