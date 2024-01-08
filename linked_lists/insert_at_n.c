#include <stdio.h>
#include <stdlib.h>
struct Node {
  int data;
  struct Node *next;
};

void insert_at_n(int data, int pos);
void print_list();
struct Node *head;
int main() {
  head = NULL;
  insert_at_n(2, 1);
  insert_at_n(3, 2);
  insert_at_n(4, 1);

  print_list();
  return 0;
}

void insert_at_n(int data, int pos) {
  struct Node *temp1 = (struct Node *)malloc(sizeof(struct Node));

  temp1->data = data;
  temp1->next = NULL;

  //  * Special Case: Inserting at first position
  if (pos == 1) {
    temp1->next = head;
    head = temp1;
    return;
  }
  struct Node *temp2 = head;
  for (int i = 0; i < pos - 2; i++) {
    temp2 = temp2->next;
  }
  temp1->next = temp2->next;
  temp2->next = temp1;
}
void print_list() {
  struct Node *temp = head;

  while (temp != NULL) {
    printf("%d", temp->data);
    temp = temp->next;
  };

  printf("\n");
}