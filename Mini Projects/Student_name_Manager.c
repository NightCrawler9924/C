#include <stdio.h>
#include <string.h>

#define MAX 5     // Number of students
#define LEN 20    // Max name length

// Function declarations
void inputNames(char names[][LEN], int n);
void printNames(char names[][LEN], int n);
void sortNames(char names[][LEN], int n);
void findLongestName(char names[][LEN], int n, char longest[]);
int searchName(char names[][LEN], int n, char target[]);

int main(void) {
    char names[MAX][LEN];
    char longest[LEN];
    char target[LEN];
    int found;

    inputNames(names, MAX);

    printNames(names, MAX);

    findLongestName(names, MAX, longest);
    printf("Longest name is: %s\n", longest);

    return 0;
}

void inputNames(char names[][LEN], int n) {
    int i;
    for(i=0; i<n; i++)
    {
        printf("Enter the name here (%d): ", i+1);
        scanf("%19s", names[i]);
    }
}

void printNames(char names[][LEN], int n) {
    int i;
    printf("\nList of Names:\n");
    for(i = 0; i < n; i++) {
        printf("%s\n", names[i]);
    }

}


void findLongestName(char names[][LEN], int n, char longest[]) {
    int i;
    int max_len;
    max_len = 0;
    for(i=0;i<n;i++)
    {
        if (strlen(names[i])>max_len)
        {
            max_len = strlen(names[i]);
            strcpy(longest, names[i]);  // Save the longest name
        }
    }
}
