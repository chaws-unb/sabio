#include <stdio.h>
#include <stdlib.h>

int main()
{

  char test[5];
  char *symtest = test;
  int i = 0;
  char c;
  for(i = 0; i < 5; i++)
  {
    test[i] = (c = getc(stdin));
    if(c == 'x') break;
  } 
  while(c = symtest++) 
  {
    printf("%s", c);
  }

  return 0;
}
