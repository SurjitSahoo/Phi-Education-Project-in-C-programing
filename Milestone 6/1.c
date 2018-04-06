#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
char *str_copy(char *str);
int main()
{
  char s1[100];
  char* s;
  printf("Enter string : ");
  scanf("%s", s1);
  s = str_copy(s1);
  printf("The copied string is : %s", s);
  return 0;
}

/** Copies a string and returns the address of it **/
char *str_copy(char *str)
{
  assert(str != NULL);
  int i;
  char *copy =(char *)malloc(100*sizeof(char));
  for(i = 0; str[i] != '\0'; ++i)
    copy[i] = str[i];
  copy[i] = '\0';
  return copy;
}
