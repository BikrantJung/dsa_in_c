
/*
Appending data to end of linked list
Time Complexity: O(n), n = number of nodes in liset
*/
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
  int number;
  struct node *next;
} node;

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

  // Print whole list
  node *ptr = list;
  while (ptr != NULL) {
    printf("%d\t", ptr->number);
    ptr = ptr->next;
  }

  return 0;
}