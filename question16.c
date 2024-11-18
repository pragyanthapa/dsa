// WAP to reverse from middle of a linked list
#include <stdio.h>
#include <stdlib.h>
struct Node {
  int data;
  struct Node *next;
};
struct Node* reverseFromMiddle(struct Node* head) {
struct Node *slow = head, *fast = head;
  while (fast != NULL && fast->next != NULL) {
    slow = slow->next;
    fast = fast->next->next;
  }
  struct Node *prev = NULL, *current = slow->next, *next;
  while (current != NULL) {
    next = current->next;
    current->next = prev;
    prev = current;
    current = next;
  }
    slow->next = prev;
  return head;
}
struct Node* insertAtBeginning(struct Node* head, int data) {
  struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
  newNode->data = data;
  newNode->next = head;
  head = newNode;
  return head;
}
void printList(struct Node *head) {
  while (head != NULL) {
    printf("%d ", head->data);
    head = head->next;
  }
  printf("\n");
}

int main() {
   struct Node *head = NULL;
  head = insertAtBeginning(head, 5);
  head = insertAtBeginning(head, 4);
  head = insertAtBeginning(head, 3);
  head = insertAtBeginning(head, 2);
  head = insertAtBeginning(head, 1);
  printf("Original list: ");
  printList(head);
  head = reverseFromMiddle(head);
  printf("Reversed list: ");
  printList(head);
  return 0;
}