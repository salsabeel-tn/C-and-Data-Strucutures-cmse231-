#include <stdio.h>

int fun1(int x);

int main() {
  int x = fun1(12);
  printf("Result: %d\n", x);
  return 0;
}

int fun1(int x) {
  if(x < 5)
    return 3 * x;
  else
    return 2 * fun1(x-5) + 7;
}
// algorithm fun1(x)
// if(x < 5) return (3 * x)
// else return (2 * fun1(x - 5)+ 7)
// end if
// end fun1
