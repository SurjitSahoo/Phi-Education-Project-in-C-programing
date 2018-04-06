#include <stdio.h>
int str_length(char *str);
int main()
{
  char string[20];
  printf("\n Enter any stringing: ");
  scanf("%s", string);
  printf("the length of the stringing  = %d", str_length(string));
  return 0;
}

/** Returns the length of a given string **/
int str_length(char *str)
{
  if(str == NULL)
    return -1;
  int count = 0;
  while(*str != '\0') {
    count += 1;
    str++;
  }
  if(count > 0)
    return count;
  else
    return -1;
}
