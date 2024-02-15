/**Reversing a string using stack array implementation
 */
#include <stdio.h>
#include <string.h>

#define MAX_SIZE 101

char stack[MAX_SIZE];
int top = -1;

void push(int x) {

  if (top == MAX_SIZE - 1) {
    printf("Error: Stack Overflow \n");
    return;
  }

  stack[++top] = x;
}

void pop() {
  if (top == -1) {
    printf("Stack is already empty");
    return;
  }
  top--;
}

char get_top() { return stack[top]; }

void reverse(char string[], int length) {
  // Original String = H E L L O
  // Push each characters in string into stack
  // String in Stack = O L L E H
  for (int i = 0; i < length; i++) {
    push(string[i]);
  }
  // Replace first character of original word by top character of stack
  for (int i = 0; i < length; i++) {
    string[i] = get_top();
    pop();
  }
}

int main() {
  char string[51];
  printf("Enter a string: ");
  scanf("%s", string);

  printf("\nOriginal String: %s\n", string);
  reverse(string, strlen(string));
  printf("Reversed String: %s\n", string);
  return 0;
}