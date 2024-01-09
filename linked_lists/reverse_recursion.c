#include <stdio.h>
#include <stdlib.h>

struct Node {
  int data;
  struct Node *next;
};

struct Node *head;

void display(struct Node *head);
void display_reverse(struct Node *head);
void insert(int data);

int main() {
  head = NULL;
  insert(1);
  insert(2);
  insert(3);
  insert(4);
  display(head);
  printf("\n\n");
  display_reverse(head);
  return 0;
};

void insert(int data) {
  struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));

  new_node->data = data;
  new_node->next = NULL;

  // If head is null, we are adding node first time, set head pointer to first
  // node;
  if (head == NULL) {
    head = new_node;
    return;
  }

  struct Node *prev = head;
  while (prev->next != NULL) {
    prev = prev->next;
  }
  prev->next = new_node;
}

// Print with recursion
void display(struct Node *p) {

  if (p == NULL) {
    return; // Edit condition
  };

  printf("----%d----\n", p->data);
  display(p->next);
}
void display_reverse(struct Node *p) {

  if (p == NULL) {
    return; // Edit condition
  };

  display_reverse(p->next);
  printf("----%d----\n", p->data);
}