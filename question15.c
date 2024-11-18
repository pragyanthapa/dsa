//  WAP to reverse a doubly linked list of n nodes.
#include <stdio.h>
#include <stdlib.h>
struct Node {
  int data;
  struct Node *prev;
  struct Node *next;
};
struct Node* reverseDLL(struct Node* head) {
  struct Node *temp = NULL, *current = head;
  while (current != NULL) {
    temp = current->prev;
    current->prev = current->next;
    current->next = temp;
    current = current->prev;
  }
    if (temp != NULL) {
    head = temp->prev;
  }
  return head;
}
struct Node* insertAtBeginning(struct Node* head, int data) {
  struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
  newNode->data = data;
  newNode->prev = NULL;
  newNode->next = head;
  if (head != NULL) {
    head->prev = newNode;
  }
  head = newNode;
  return head;
}
void printDLL(struct Node *head) {
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
  printDLL(head);
  head = reverseDLL(head);
  printf("Reversed list: ");
  printDLL(head);
  return 0;
}