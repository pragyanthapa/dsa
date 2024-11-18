// Write a C program to Sort a Stack Using Recursion
#include <stdio.h>
#include <stdlib.h>
struct Node {
  int data;
  struct Node *next;
};
struct Node* newNode(int data) {
  struct Node *node = (struct Node*)malloc(sizeof(struct Node));
  node->data = data;
  node->next = NULL;
  return node;
}
struct Node* push(struct Node* top, int data) {
  struct Node *node = newNode(data);
  node->next = top;
  top = node;
  return top;
}
struct Node* pop(struct Node* top) {
  if (top == NULL) {
    printf("Stack is empty!\n");
    return top;
  }
  struct Node *temp = top;
  top = top->next;
  free(temp);
  return top;
}
struct Node* insertAtBottom(struct Node* top, int data) {
  if (top == NULL) {
    return push(top, data);
  }
  int temp = pop(top)->data;
  top = insertAtBottom(top, data);
  top = push(top, temp);
  return top;
}
struct Node* sortStack(struct Node* top) {
  if (top == NULL) {
    return top;
  }
  int temp = pop(top)->data;
  top = sortStack(top);
  top = insertAtBottom(top, temp);
  return top;
}
void display(struct Node* top) {
  if (top == NULL) {
    printf("Stack is empty!\n");
    return;
  }
  struct Node *temp = top;
  while (temp != NULL) {
    printf("%d ", temp->data);
    temp = temp->next;
  }
  printf("\n");
}
int main() {
  struct Node *top = NULL;
  top = push(top, 3);
  top = push(top, 1);
  top = push(top, 4);
  top = push(top, 2);
  printf("Original stack: ");
  display(top);
  top = sortStack(top);
  printf("Sorted stack: ");
  display(top);
  return 0;
}