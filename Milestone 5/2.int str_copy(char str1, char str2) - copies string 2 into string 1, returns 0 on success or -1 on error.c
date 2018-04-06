#include <stdio.h>
int str_copy(char *str1, char *str2);
int main()
{
  char s1[100], s2[100], s;
  printf("Enter string : ");
  scanf("%s",s2);
  s = str_copy(s1, s2);
  if(s == 0)
      printf("SUCCESS\n");
  else
      printf("FAILED\n");
  return 0;
}
/** Copies str1 to str2**/
int str_copy(char *str1, char *str2)
{
  if((str1 == NULL) && (str2 == NULL))
    return -1;
  int i;
  for(i = 0; str2[i] != '\0'; ++i) {
    str1[i] = str2[i];
  }
  str1[i] = '\0';
  if ((str1[i] == '\0') && (str2[i] == '\0'))
    return 0;
  else
    return -1;
}
