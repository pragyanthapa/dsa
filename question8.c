/* Write a program in C to get the largest and second smallest element of an array using 
the function.
*/
#include <stdio.h>
void findLargestAndSecondSmallest(int arr[], int size, int *largest, int *secondSmallest) {
    if (size < 2) {
        printf("Array must have at least two elements.\n");
        return;
    }
    *largest = arr[0];
    *secondSmallest = arr[1];
    if (*largest < *secondSmallest) {
        int temp = *largest;
        *largest = *secondSmallest;
        *secondSmallest = temp;
    }
    for (int i = 2; i < size; i++) {
        if (arr[i] > *largest) {
            *secondSmallest = *largest;
            *largest = arr[i];
        } else if (arr[i] < *secondSmallest) {
            *secondSmallest = arr[i];
        }
    }
}
int main() {
    int arr[] = {5, 1, 4, 2, 8, 3, 7, 9, 6};
    int size = sizeof(arr) / sizeof(arr[0]);
    int largest, secondSmallest;
    findLargestAndSecondSmallest(arr, size, &largest, &secondSmallest);
    printf("Largest element: %d\n", largest);
    printf("Second smallest element: %d\n", secondSmallest);
    return 0;
}