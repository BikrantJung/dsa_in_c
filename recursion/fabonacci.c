#include <stdio.h>

/*
 Input = 6;
 fabonacci =0 1 1 2 3 5 8  i.e. Fabonacci of 6 numbers ()
 This recursive algorithm will freeze for input value greater than 40.
 Use hash maps instead.
*/
int fabonacci(int num) {
  if (num == 0) {
    return 0;
  }
  if (num == 1) {
    return 1;
  }
  return fabonacci(num - 1) + fabonacci(num - 2);
}

int main() {
  int fab = fabonacci(6);
  printf("Fabonacci: %d\n", fab);
  return 0;
}