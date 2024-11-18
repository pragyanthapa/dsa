/*Write a program in C to create a singly linked list of n nodes and count the number of nodes.*/
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
int countNodes(struct Node* head) {
    int count = 0;
    struct Node* current = head;
    while (current != NULL) {
        count++;
        current = current->next;
    }
    return count;
}
int main() {
    int n, count;
    struct Node* head;
    printf("Enter the number of nodes: ");
    scanf("%d", &n);
    head = createLinkedList(n);
    count = countNodes(head);
    printf("Number of nodes in the linked list: %d\n", count);
    return 0;
}