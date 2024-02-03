
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 101

struct StackNode {
  int data;
  struct StackNode *next;
};
struct StackNode *top = NULL;
/**
 * In linked list implementation of stacks, instead of traversing through
 * all nodes and pushing new node at the end which will take time complexity
 * of O(n) we just push new node at beginning which will take time complexity
 * of O(1).
 */
void push(int x) {
  struct StackNode *temp =
      (struct StackNode *)malloc(sizeof(struct StackNode *));
  temp->data = x;
  temp->next = top;
  top = temp;
}

/** Pop method
 * Remove the node which the head is currently pointing, and
 * set the head to the node which we removed.
 */
void pop() {
  struct StackNode *temp;
  if (top == NULL)
    return;
  temp = top;
  top = top->next; // Only this line alone will work, but we need to free the
                   // memory also
  free(temp);
}

void print_list() {
  while (top != NULL) {
    printf("%d ", top->data);
    top = top->next;
  }
}

int peek() { return top->data; }

int main() {
  push(1);
  push(2);
  push(3);
  print_list();
  pop();
  pop();
  push(3);
  int top_data = peek();
  print_list();
  printf("%d\n", top_data);
  return 0;
}