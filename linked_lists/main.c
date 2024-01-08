#include <stdio.h>
#include <stdlib.h>

struct ListNode {
  int data;
  struct ListNode *next;
};
void printLinkedlist(struct ListNode *p) {
  while (p != NULL) {
    printf("%d ", p->data);
    p = p->next;
  }
}
int main() {
  struct ListNode *head;
  // Allocate list node
  struct ListNode *one;
  struct ListNode *two;
  struct ListNode *three;

  // Allocate memory
  one = malloc(sizeof(struct ListNode));
  two = malloc(sizeof(struct ListNode));
  three = malloc(sizeof(struct ListNode));

  // Assign data
  one->data = 1;
  two->data = 2;
  three->data = 3;

  //   Connect nodes
  one->next = two;
  two->next = three;
  three->next = NULL;

  head = one;
  printLinkedlist(head);
  free(one);
  free(two);
  free(three);

  return 0;
}