#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 101
typedef struct node {
  int number;
  struct node *next;
} node;

typedef struct {
  int maxSize;
  int top;
  node **array;
} stack;

stack *createStack() {

  // Create a stk struct in memory
  stack *stk = malloc(sizeof(stack));
  stk->maxSize = MAX_SIZE;
  stk->top = -1;

  /*
  Allocate space for array of pointers to the node inside the stk struct in
  memory.
  The (node **) means each element in array is the pointer to the struct node
  the (node *) inside the sizeof() operator means the sizeof single pointer
  data-type
  */
  stk->array = (node **)malloc(MAX_SIZE * sizeof(node *));

  return stk;
}
// Function to check if the stack is empty
int isEmpty(stack *stk) {
  if (stk->top == -1) {
    return 1;
  }
  return 0;
}
// Function to check if the stack is full
int isFull(stack *stk) { return stk->top == stk->maxSize - 1; }

// Function to push a pointer to the node at top of stack
void push(stack *stk, node *node) {
  if (isFull(stk)) {
    printf("Stack Overflow\n");
    return;
  }
  //   Pre-increment Method: Increment will happen before assignment
  stk->array[++stk->top] = node;
  // Above is similar to below
  // stk->top++;
  // stk->array[stk->top] = node;
}

// Function to remove the top item from stack's array and return that item
// i.e. return the pointer to the node
node *pop(stack *stk) {

  if (isEmpty(stk)) {
    printf("Stack is empty");
    return NULL;
  }

  node *topNode = stk->array[stk->top];
  stk->top--;
  return topNode;
}

void reverse(node **headRef) {
  stack *stk = createStack();
  node *current = *headRef;

  // Push each node into the stack
  while (current != NULL) {
    push(stk, current);
    current = current->next;
  }
  // Pop nodes from stack and update the linked list;
  current = pop(stk);
  *headRef = current;
  while (!isEmpty((stk))) {
    current->next = pop(stk);
    current = current->next;
  }
  current->next = NULL;
}
int main(int argc, char *argv[]) {

  node *list = NULL;

  for (int i = 1; i < argc; i++) {
    int number = atoi(argv[i]);

    node *n = malloc(sizeof(node));
    if (n == NULL) {
      // Free memory thus far.
      return 1;
    }
    n->number = number;
    n->next = NULL;

    // If the list is empty
    if (list == NULL) {
      list = n;
    } else {
      // If list already has nodes
      node *ptr = list;

      // Loop through the nodes,
      while (ptr != NULL) {
        // Reach at the end of the list
        if (ptr->next == NULL) {
          // Set the next value of end node to newly created node
          ptr->next = n;
          break;
        }
        ptr = ptr->next;
      }
    }
  }

  printf("Original Linked List:\n");
  node *ptr = list;

  while (ptr != NULL) {
    printf("%d\t", ptr->number);
    ptr = ptr->next;
  }

  reverse(&list);
  printf("\nReversed Linked List:\n");
  ptr = list;

  while (ptr != NULL) {
    printf("%d\t", ptr->number);
    ptr = ptr->next;
  }
  return 0;
}
