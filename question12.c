/* Write a program in C to create and display a Singly Linked List.*/
#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node *next;
};
struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->next = NULL;
    return node;
}
struct Node* insertAtBeginning(struct Node* head, int data) {
    struct Node* new_node = newNode(data);
    new_node->next = head;
    return new_node;
}
void displayList(struct Node* head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}
int main() {
    struct Node* head = NULL;
    head = insertAtBeginning(head, 3);
    head = insertAtBeginning(head, 2);
    head = insertAtBeginning(head, 1);
    printf("Created Linked List: ");
    displayList(head);
    return 0;
}