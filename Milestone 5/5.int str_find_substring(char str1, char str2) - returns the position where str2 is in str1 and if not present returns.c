#include <stdio.h>
#include <assert.h>
int str_find_substring(char *str1, char *str2) ;
int main()
{
  char str1[80], str2[10];
  int x;
  printf("Enter a string:");
  scanf("%s", str1);
  printf("Enter search substring:");
  scanf("%s", str2);
  x = str_find_substring(str1, str2);
  if(x != -1)
    printf("SEARCH SUCCESSFUL!\n%s is present at position %d", str2, x);
  else
    printf("SEARCH UNSUCCESSFUL!");
  return 0;
}
int str_find_substring(char *str1, char *str2)
{
  assert((str1 != NULL) && (str2 != NULL));  
  int count1 = 0, count2 = 0, i, j, flag, c;
  while (str1[count1] != '\0')
    count1++;
  while (str2[count2] != '\0')
    count2++;
  for(i = 0; i <= count1 - count2; i++){
    for(j = i; j < i + count2; j++){
      flag = 1;
      if(str1[j] != str2[j - i]){
        flag = 0;
        break;
      }
    }
    if(flag == 1){
      c = i;
      break;
    }
  }
  if(flag == 0)
    return -1;
  else
    return c;
}
