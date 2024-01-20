/*
WAP to print numbers from 1 to 10 in such a way that
when number is odd, add 1 and when number is even
subtract 1.
Output: 2 1 4 3 6 5 8 7 10 9
*/

#include <stdio.h>

void odd(int);
void even(int);
int main() {
  int n = 1;
  odd(n);
  return 0;
}

void odd(int n) {
  if (n <= 10) {
    printf("%d\t", n + 1);
    n++;
    even(n);
  }
  return;
}
void even(int n) {
  if (n <= 10) {
    printf("%d\t", n - 1);
    n++;
    odd(n);
  }
  return;
}