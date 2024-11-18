// Write a program to count total number of notes in a given amount
#include <stdio.h>
int main() {
    int amount, i, count, total_notes = 0;
    int denominations[] = {1000, 500, 100, 50, 20, 10, 5, 1};
    int num_denominations = sizeof(denominations) / sizeof(denominations[0]);

    printf("Enter the amount: ");
    scanf("%d", &amount);

    printf("Notes required:\n");
    for (i = 0; i < num_denominations; i++) {
        count = amount / denominations[i];
        if (count > 0) {
            printf("%d notes of %d\n", count, denominations[i]);
            total_notes += count;
            amount %= denominations[i]; 
        }
    }
    printf("Total number of notes: %d\n", total_notes);
    return 0;
}