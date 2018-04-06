#include <stdio.h>
#include "stringlib.h"
int main()
{
  char string[20];
  printf("\n Enter any stringing: ");
  scanf("%s", string);
  printf("the length of the stringing  = %d", str_length(string));
  return 0;
}
