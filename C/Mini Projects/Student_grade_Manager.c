#include <stdio.h>

#define NUM_STUDENTS 5

// Function declarations
void inputGrades(char names[][20], int grades[], int n);
void printGrades(char names[][20], int grades[], int n);
double averageGrade(int grades[], int n);
void findMinMax(int grades[], int n, int *min, int *max);

int main(void) {
    char names[NUM_STUDENTS][20];
    int grades[NUM_STUDENTS];
    int minGrade, maxGrade;
    double avg;

    printf("Enter names and grades of %d students:\n", NUM_STUDENTS);
    inputGrades(names, grades, NUM_STUDENTS);

    printf("\nStudent Grades:\n");
    printGrades(names, grades, NUM_STUDENTS);

    avg = averageGrade(grades, NUM_STUDENTS);
    findMinMax(grades, NUM_STUDENTS, &minGrade, &maxGrade);

    printf("\nAverage grade: %.1f\n", avg);
    printf("Minimum grade: %d\n", minGrade);
    printf("Maximum grade: %d\n", maxGrade);
    return 0;
}

void inputGrades(char names[][20], int grades[], int n) {
    int i;
    for(i=0;i<n; i++){
        printf("Enter student name: ", i+1); //as it stops prior to the given number 
        //now i is the student name, we'll store it in the 'names' array
        scanf("%19s", names[i]); //here we added only 19 characters to avoid overflow

        printf("Enter student grade: ", i+1); //as it stops prior to the given number 
        //now i is the student grade, we'll store it in the 'grades' array
        scanf("%d", &grades[i]);

    }
}

void printGrades(char names[][20], int grades[], int n) {
    int i;
    for(i=0; i<n;i++){
        printf("Here is the student info Name: %s, Grade: %d\n", names[i], grades[i]);

    }
}

double averageGrade(int grades[], int n) {
    int i;
    int sum = 0;
    for (i = 0; i < n; i++) {
        sum += grades[i];
    }
    return (double)sum / n;
}

void findMinMax(int grades[], int n, int *min, int *max) {
    int i;
    *min = grades[0];
    *max = grades[0];

    for (i = 1; i < n; i++) {
        if (grades[i] > *max) {
            *max = grades[i];
        }
        if (grades[i] < *min) {
            *min = grades[i];
        }
    }
}