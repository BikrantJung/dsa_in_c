#include <stdio.h>
#include <stdlib.h>

struct Node {
  int data;
  struct Node *next;
};

struct Node *head;

void insert_at_beginning(int x);
void print_list();

int main() {
  head = NULL;
  printf("How many numbers?: ");
  int n, i, x;
  scanf("%d", &n);

  for (i = 0; i < n; i++) {
    printf("\nEnter the number: ");
    scanf("%d", &x);
    insert_at_beginning(x);
    print_list();
  }
  return 0;
}

void insert_at_beginning(int x) {
  struct Node *temp = (struct Node *)malloc(sizeof(struct Node));

  temp->data = x; //   (*temp).data = x;

  // The new node will now point where head was pointing previously.
  temp->next = head;

  // Now head will point to newly created node (it will be first element in
  // list)
  head = temp;
}

void print_list() {
  struct Node *temp = head;
  printf("\nList is: ");
  while (temp != NULL) {
    printf("%d\t", temp->data);
    temp = temp->next;
  }
}