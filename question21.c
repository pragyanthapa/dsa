#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node *next;
};
struct Node* createNode(int data) {
    struct Node *node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->next = node;
    return node;
}
struct Node* insertAtPos(struct Node *head, int data, int pos) {
    struct Node *new_node = createNode(data);
    if (head == NULL) {
        if (pos == 1) {
            return new_node;
        } else {
            printf("Invalid position!\n");
            free(new_node);
            return NULL;
        }
    }
    if (pos == 1) { 
        struct Node *last = head;
        while (last->next != head) {
            last = last->next;
        }
        last->next = new_node;
        new_node->next = head;
        head = new_node; 
        return head;
    } else {
        struct Node *temp = head;
        int count = 1;
        while (count < pos - 1 && temp->next != head) {
            temp = temp->next;
            count++;
        }
        if (count < pos - 1) {
            printf("Invalid position!\n");
            free(new_node);
            return head;
        }
        new_node->next = temp->next;
        temp->next = new_node;
        return head;
    }
}
void display(struct Node *head) {
    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }
    struct Node *temp = head;
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("\n");
}
int main() {
    struct Node *head = createNode(10);
    head = insertAtPos(head, 20, 1); 
    head = insertAtPos(head, 30, 2); 
    head = insertAtPos(head, 40, 4);
    printf("Circular linked list: ");
    display(head);
    return 0;
}
