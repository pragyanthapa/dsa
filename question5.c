/* A student will not be allowed to sit in exam if his/her attendance is less than 75%. Take 
following input from user Number of classes held. Number of classes attended. Print Output --
percentage of classs attended is student is allowed to sit in exam or not.
*/
#include <stdio.h>

int main() {
    int classesHeld, classesAttended;
    printf("Enter the number of classes held: ");
    scanf("%d", &classesHeld);
    printf("Enter the number of classes attended: ");
    scanf("%d", &classesAttended);

    if (classesHeld == 0) {
        printf("Invalid input: Classes held cannot be zero.\n");
        return 1; 
    }
    float attendancePercentage = (float) classesAttended / classesHeld * 100;
    printf("Attendance percentage: %.2f%%\n", attendancePercentage);
    if (attendancePercentage >= 75) {
        printf("The student is allowed to sit in the exam.\n");
    } else {
        printf("The student is not allowed to sit in the exam.\n");
    }
    return 0;
}