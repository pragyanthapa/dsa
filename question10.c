/*  Define a structure named Time with members hours, minutes, 
and seconds. Write a C program to input two 
display the result in proper time format.
*/
#include <stdio.h>
struct Time {
    int hours;
    int minutes;
    int seconds;
};
struct Time addTime(struct Time t1, struct Time t2) {
    struct Time sum;
    sum.seconds = t1.seconds + t2.seconds;
    if (sum.seconds >= 60) {
        sum.minutes += sum.seconds / 60;
        sum.seconds %= 60;
    }
    sum.minutes += t1.minutes + t2.minutes;
    if (sum.minutes >= 60) {
        sum.hours += sum.minutes / 60;
        sum.minutes %= 60;
    }
    sum.hours += t1.hours + t2.hours;
    return sum;
}
void displayTime(struct Time t) {
    printf("%02d:%02d:%02d\n", t.hours, t.minutes, t.seconds);
}
int main() {
    struct Time time1, time2, sum;
    printf("Enter time 1 (HH:MM:SS): ");
    scanf("%d:%d:%d", &time1.hours, &time1.minutes, &time1.seconds);
    printf("Enter time 2 (HH:MM:SS): ");
    scanf("%d:%d:%d", &time2.hours, &time2.minutes, &time2.seconds);
    sum = addTime(time1, time2);
    printf("\nTime 1: ");
    displayTime(time1);
    printf("Time 2: ");
    displayTime(time2);
    printf("Sum of Time: ");
    displayTime(sum);
    return 0;
}