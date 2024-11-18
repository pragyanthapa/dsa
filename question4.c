/* Write a program that asks the user to enter two numbers. The numbers should be added and the
sum displayed. The loop should ask the user whether he or she wishes to perform the operation 
again. If so, the loop should repeat, otherwise it should terminate. 
*/ 
#include <stdio.h>

int main() {
    char choice;

    do {
        int num1, num2, sum;

        printf("Enter two numbers: ");
        scanf("%d %d", &num1, &num2);

        sum = num1 + num2;
        printf("Sum: %d\n", sum);

        printf("Do you want to perform the operation again? (y/n): ");
        scanf(" %c", &choice);

    } while (choice == 'y' || choice == 'Y');

    printf("Exiting program.\n");

    return 0;
}
