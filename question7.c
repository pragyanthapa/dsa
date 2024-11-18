// Write a Program to shift an array from nth position.
#include <stdio.h>
void shiftArray(int arr[], int n, int size) {
    if (n < 0 || n >= size) {
        printf("Invalid shift position.\n");
        return;
    }
    for (int i = size - 1; i > n; i--) {
        arr[i] = arr[i - 1];
    }
    arr[n] = 0; 
}
int main() {
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int size = sizeof(arr) / sizeof(arr[0]);
    int n;
    printf("Enter the position to shift from (0 to %d): ", size - 1);
    scanf("%d", &n);
    shiftArray(arr, n, size);
    printf("Array after shifting:\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}