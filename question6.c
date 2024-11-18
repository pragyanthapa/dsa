/* Modify the abopve question to allow students to sit if he/she has medical cause or not. Ask
user if he/she has medical cause or not('Y' 'N') and print accordingly.
*/
#include <stdio.h>
int main() {
    int classesHeld, classesAttended;
    char hasMedicalCause;
    printf("Enter the number of classes held: ");
    scanf("%d", &classesHeld);
    printf("Enter the number of classes attended: ");
    scanf("%d", &classesAttended);
    printf("Does the student have a medical cause? (Y/N): ");
    scanf(" %c", &hasMedicalCause);
    if (classesHeld == 0) {
        printf("Invalid input: Classes held cannot be zero.\n");
        return 1;
    }
    float attendancePercentage = (float) classesAttended / classesHeld * 100;
    printf("Attendance percentage: %.2f%%\n", attendancePercentage);
    if (attendancePercentage >= 75 || (hasMedicalCause == 'Y' || hasMedicalCause == 'y')) {
        printf("The student is allowed to sit in the exam.\n");
    } else {
        printf("The student is not allowed to sit in the exam.\n");
    }
    return 0;
}