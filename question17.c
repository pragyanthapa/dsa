// WAP for insertion and deletion of elements in a stack.
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
  top = push(top, 10);
  top = push(top, 20);
  top = push(top, 30);
  printf("Stack: ");
  display(top);
  top = pop(top);
  printf("Stack after popping: ");
  display(top);
  return 0;
}