/* Write a program in C to create a singly linked list of n nodes and display it in reverse order.*/
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
struct Node* createLinkedList(int n) {
    struct Node* head = NULL;
    struct Node* temp;
    int i, data;
    for (i = 0; i < n; i++) {
        printf("Enter data for node %d: ", i + 1);
        scanf("%d", &data);
        temp = newNode(data);
        temp->next = head;
        head = temp;
    }
    return head;
}
void displayReverse(struct Node* head) {
    if (head == NULL) {
        return;
    }
    displayReverse(head->next);
    printf("%d ", head->data);  
}
int main() {
    int n;
    struct Node* head;
    printf("Enter the number of nodes: ");
    scanf("%d", &n);
    head = createLinkedList(n);
    printf("Linked list in reverse order: ");
    displayReverse(head);
    printf("\n");
    return 0;
}