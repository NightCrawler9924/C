//1. To join the first and last name
#include <stdio.h>
#include <string.h>

int main() {
    char first_name[20];
    char last_name[20];
    char full_name[50];

    printf("Enter first name: ");
    scanf("%s", first_name);  // or use fgets for full names with spaces

    printf("Enter last name: ");
    scanf("%s", last_name);

    // Create full name in "Last, First" format
    strcpy(full_name, last_name);     // Copy last name
    strcat(full_name, ", ");          // Add comma and space
    strcat(full_name, first_name);    // Add first name

    // Output
    printf("Hello There: %s\n", full_name);

    return 0;
}

//2. To seperate the full name into 2 parts using string functions

int main() {
    char first_name[20];
    char last_name[20];
    char full_name[50];
    
    printf("Enter full name: ");
    scanf("%s", full_name);


    
}