#include <stdio.h>

#define MAX_SIZE 101

// Global Variables
int stack[MAX_SIZE];
int top = -1;

void push(int x) {
  // Handle stack overflow:
  if (top == MAX_SIZE - 1) {
    printf("Error: Stack Overflow \n");
    return;
  }
  //   Pre-increment Method: Increment will happen before assignment
  stack[++top] = x;

  // This is also same:
  //   top++;
  //   stack[top] = x;
}
void pop() {
  if (top == -1) {
    printf("Stack is already empty");
    return;
  }
  top--;
}

int get_top() { return stack[top]; }

int main() {
  push(5);
  push(3);
  push(2);
  push(1);
  pop();
  int top_item = get_top();
  printf("%d\n", top_item);
  return 0;
}
/*
 * ALGORITHM FOR PUSHING IN STACK *
begin
 if stack is full
    return
 endif
else
 increment top
 stack[top] assign value
end else
end procedure
*/
/*
 * ALGORITHM FOR POPING ITEM FROM STACK
 begin
 if stack is empty
    return
 endif
else
 store value of stack[top]
 decrement top
 return value
end else
end procedure
*/