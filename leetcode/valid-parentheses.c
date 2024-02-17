/*
Given a string with parentheses, checked for balanced and valid parentheses
Input: {(A+B)}
Output: True

Input: {(a + b} ) or [2 * 3 + (A + B) or )(
Output: False

Input: ({[]})
Output: True

The parentheses must be in order

NOTE: Last Opened Parentheses Should be Closed First E.g. [(]). '(' should've
been closed first

Solution: Scan from left to right,
If opening symbol, add it to stack
If closing symbol, it should be equal to the last element in the stack.
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct {
  int maxSize;
  int top;
  char *array;
} stack;

void push_to_stack(stack *stk, char string) {
  if (stk->top == stk->maxSize - 1) {
    printf("Stack Overflow\n");
    return;
  }
  stk->array[++stk->top] = string;
}
char pop_from_stack(stack *stk) {
  if (stk->top == -1) {
    printf("Stack is empty\n");
    return ' ';
  }
  char topChar = stk->array[stk->top];
  stk->top--;
  return topChar;
}

// Function to check if a string includes a character or not.
int includes(char *string, int stringLength, char character) {
  for (int i = 0; i < stringLength; i++) {
    if (string[i] == character) {
      return 1;
    }
  }
  return 0;
}

int main() {
  char string[] = "(}{}]";
  stack *stk = malloc(sizeof(stack));
  stk->maxSize = 20;
  stk->top = -1;
  stk->array = (char *)malloc(stk->maxSize * sizeof(char));

  for (int i = 0; i < strlen(string); i++) {
    //  If first character is closing, and stack is empty, early return;
    if (includes("]})", 3, string[i])) {
      if (stk->top == -1) {
        printf("Parantheses are not balanced\n");
        return -1;
      } else {
        // Pop the last char from stack
        char lastChar = pop_from_stack(stk);
        if (lastChar == '[' && string[i] == ']' ||
            lastChar == '(' && string[i] == ')' ||
            lastChar == '{' && string[i] == '}') {
          // Keep looping...
        } else {

          printf("Parantheses are not balanced\n");
          return -1;
        }
      }
    } else {
      // It is a opening symbol, push to stack
      push_to_stack(stk, string[i]);
    }
  }

  if (stk->top == -1) {
    // Everything is removed from stack, all parentheses are balanced
    printf("Parantheses are balanced\n");
    return 0;
  } else {
    printf("Parantheses are not balanced\n");
    return 0;
  }

  return 0;
}
