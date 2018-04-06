#include <stdio.h>
#include <assert.h>
int str_compare(char *str1, char *str2);

int main()
{
  int flag;
  char str1[30], str2[30];
  printf("Enter first string : ");
  scanf("%s", str1);
  printf("Enter second string : ");
  scanf("%s", str2);
  flag = str_compare(str1, str2);
  if(flag == -1)
    printf("String1 is less than string2 \n");
  if(flag == 1)
    printf("String1 is greater than string2 \n");
  if(flag == 0)
    printf("Both strings are equal \n");
  return 0;
}

/** Compare two strings **/
int str_compare(char *str1, char *str2)
{
  assert((str1 != NULL) && (str2 != NULL));
  int c1 = 0, c2 = 0, cmp = 0, i;
  while (str1[c1] != '\0')
    c1 += 1;
  while (str2[c2] != '\0')
    c2 += 1;
  i = 0;
  while ((i < c1) && (i < c2)) {
    if(str1[i] == str2[i]) {
      i++;
      continue;
    }
    if(str1[i] < str2[i]) {
      cmp = -1;
      break;
    }
    if(str1[i] > str2[i]) {
      cmp = 1;
      break;
    }
  }
  return cmp;
}
