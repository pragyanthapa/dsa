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
  if (rear == NULL) return node;
  rear->next = node;
  return node;
}
struct Node* reverseHalf(struct Node* start) {
  struct Node *prev = NULL, *curr = start;
  while (curr != NULL) {
    struct Node *next = curr->next;
    curr->next = prev;
    prev = curr;
    curr = next;
  }
  return prev;
}

struct Node* reverseQueueHalves(struct Node* front) {
  if (!front || !front->next) return front;

  struct Node *slow = front, *fast = front, *prev = NULL;
  while (fast && fast->next) {
    fast = fast->next->next;
    prev = slow;
    slow = slow->next;
  }
  prev->next = NULL; 
  struct Node *firstHalf = reverseHalf(front);
  struct Node *secondHalf = reverseHalf(slow);
  struct Node *temp = firstHalf;
  while (temp->next) temp = temp->next; 
  temp->next = secondHalf; 
  return firstHalf;
}
void display(struct Node* front) {
  struct Node *temp = front;
  while (temp) {
    printf("%d ", temp->data);
    temp = temp->next;
  }
  printf("\n");
}
int main() {
  struct Node *front = NULL, *rear = NULL;
  front = rear = enqueue(rear, 10);
  rear = enqueue(rear, 20);
  rear = enqueue(rear, 30);
  rear = enqueue(rear, 40);
  rear = enqueue(rear, 50);
  printf("Original queue: ");
  display(front);
  front = reverseQueueHalves(front);
  printf("Queue after reversing halves: ");
  display(front);
  return 0;
}
