#include <stdio.h>
int * function();

int main()
{
  auto int *x;
  x = (&function)();
  printf("Output : %d\n", *x);

  return 0;
}

int *function()
{
  static int a = 10;
  return &a;
}
