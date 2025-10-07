#include <stdio.h>

//Explanation for global variable
int x = 10;  // Global variable

void show() {
    printf("Inside function: %d\n", x);
}

int main() {
    show();
    printf("In main: %d\n", x);
    return 0;
}


//Explanation for local variable
void myFunc() {
    int y = 5;  // Local variable
    printf("Inside function: %d\n", y);
}

int main() {
    myFunc();
    printf("In main: %d\n", y);  // ❌ Error: y not declared here
    return 0;
}

//What happens when names clash?

int num = 100;  // Global variable

void test() {
    int num = 50;  // Local variable shadows global
    printf("Inside function: %d\n", num);
}

int main() {
    test();
    printf("In main: %d\n", num);
    return 0;
}
