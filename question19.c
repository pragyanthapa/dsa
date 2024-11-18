// Reverse First k elements of a Queue.
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
struct Node* enqueue(struct Node* rear, int data) {
  struct Node *node = newNode(data);
  if (rear == NULL) {
    return node;
  }
  rear->next = node;
  rear = node;
  return rear;
}
struct Node* dequeue(struct Node** front) {
  if (*front == NULL) {
    printf("Queue is empty!\n");
    return NULL;
  }
  struct Node *temp = *front;
  *front = (*front)->next;
  free(temp);
  return *front;
}
struct Node* reverseFirstK(struct Node** front, struct Node* rear, int k) {
  if (k <= 0 || k > 10 || *front == NULL) {
    return *front;
  }
  struct Node *temp = *front;
  struct Node *newFront = *front;
  struct Node *newRear = *front;
  int count = 0;
  while (count < k && temp != NULL) {
    temp = temp->next;
    count++;
  }
  if (count < k) {
    return *front;
  }
  while (count > 0) {
    struct Node *next = (*front)->next;
    (*front)->next = newRear;
    newRear = *front;
    *front = next;
    count--;
  }
  newRear->next = temp;
  return newFront;
}
void display(struct Node* front) {
  if (front == NULL) {
    printf("Queue is empty!\n");
    return;
  }
  struct Node *temp = front;
  while (temp != NULL) {
    printf("%d ", temp->data);
    temp = temp->next;
  }
  printf("\n");
}
int main() {
  struct Node *front = NULL, *rear = NULL;
  rear = enqueue(rear, 10);
  rear = enqueue(rear, 20);
  rear = enqueue(rear, 30);
  rear = enqueue(rear, 40);
  rear = enqueue(rear, 50);
  printf("Original queue: ");
  display(front);
  int k = 3;
  front = reverseFirstK(&front, rear, k);
  printf("Queue after reversing first %d elements: ", k);
  display(front);
  return 0;
}