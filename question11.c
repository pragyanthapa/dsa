/* Create a structure named Book to store book details like title, 
author, and price. Write a C program to input details for three 
books, find the most expensive and the 
display their information.
*/
#include <stdio.h>
#include <string.h>
struct Book {
    char title[100];
    char author[50];
    float price;
    };
int main() {
    struct Book books[3]; 
    int i, mostExpensiveIndex = 0;
    for (i = 0; i < 3; i++) {
        printf("Enter details for book %d:\n", i + 1);
        printf("Title: ");
        scanf(" %[^\n]", books[i].title); 
        printf("Author: ");
        scanf(" %[^\n]", books[i].author); 
        printf("Price: ");
        scanf("%f", &books[i].price);}
    for (i = 1; i < 3; i++) {
        if (books[i].price > books[mostExpensiveIndex].price) {
            mostExpensiveIndex = i;
        }}
    printf("\nMost Expensive Book:\n");
    printf("Title: %s\n", books[mostExpensiveIndex].title);
    printf("Author: %s\n", books[mostExpensiveIndex].author);
    printf("Price: %.2f\n", books[mostExpensiveIndex].price);
    return 0;
}