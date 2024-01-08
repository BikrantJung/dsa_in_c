#include <stdio.h>
#include <stdlib.h>

void insert(int data);
void reverse();
void print();

struct Node {
  int data;
  struct Node *next;
};

struct Node *head;

int main() {
  head = NULL;
  printf("Running main\n");
  insert(2);
  insert(3);
  insert(4);
  insert(5);
  print();
  reverse();
  printf("Reversed List:\n");
  print();
  return 0;
}

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

void print() {
  struct Node *current = head;
  while (current != NULL) {
    printf("Data: %d\n", current->data);
    current = current->next;
  }
}

void reverse() {
  struct Node *current, *prev, *next;
  current = head;
  prev = NULL;
  while (current != NULL) {
    next = current->next;

    current->next = prev;
    prev = current;

    current = next;
  }
  head = prev;
}