#include <stdio.h>
#include <assert.h>
void *mem_copy(void *dest, const void *src, unsigned int n);
int main()
{
  char a[50];
  char b[50] = ""; //without initializing it gives me error
  int n;
  printf("Enter the String : ");
  scanf("%s", a);
  printf("How many bytes you want to copy? ");
  scanf("%d", &n);
  mem_copy(b, a, n);
  printf("The copied string is : %s \n", b);
  return 0;
}

/** copies n bytes from src to dest **/
void *mem_copy(void *dest, const void *src, unsigned int n)
{
  assert(src != NULL);  
  int i;
  char* newsrc = (char*)src;
  char* newdest = (char*)dest;
  if(newdest < newsrc)
    for(i = 0; i < n; i++)
      newdest[i] = newsrc[i];
  else
    /* Copy backwards so that memory won't overlap */
    for(i = (n - 1); i >= 0; i--)
      newdest[i] = newsrc[i];
  return dest;  
}
