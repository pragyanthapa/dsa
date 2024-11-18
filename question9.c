/*  Create a structure called "Student" with members name, age, and 
total marks. Write a C program to input data for two students, 
display their information, and find the average of total marks.
*/
#include <stdio.h>
struct Student {
    char name[50];
    int age;
    float totalMarks;
};
int main() {
    struct Student students[2]; 
    int i;
    float totalMarksSum = 0;
    for (i = 0; i < 2; i++) {
        printf("Enter details for student %d:\n", i + 1);
        printf("Name: ");
        scanf("%s", students[i].name);
        printf("Age: ");
        scanf("%d", &students[i].age);
        printf("Total Marks: ");
        scanf("%f", &students[i].totalMarks);
        totalMarksSum += students[i].totalMarks;
    }
    printf("\nStudent Information:\n");
    for (i = 0; i < 2; i++) {
        printf("\nStudent %d:\n", i + 1);
        printf("Name: %s\n", students[i].name);
        printf("Age: %d\n", students[i].age);
        printf("Total Marks: %.2f\n", students[i].totalMarks);
    }
    float averageMarks = totalMarksSum / 2;
    printf("\nAverage Total Marks: %.2f\n", averageMarks);
    return 0;
}