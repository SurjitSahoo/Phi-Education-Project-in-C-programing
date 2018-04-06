#include<stdio.h>
int main()
{
  nt number[50], ele, i, n, if_found=0;
  printf("Enter the size of the array : ");
  scanf("%d", &n);
  printf("Enter the numbers \n");
  for (i = 0; i < n; i++)
      scanf("%d", &number[i]);
  printf("Enter the number to be searched : ");
  scanf("%d", &ele);
  for(i=0; i<n; i++) {
    if(ele == number[i]) {
      if_found=1;
      printf("Match fouond\n%dth is the position of the element %d in the array", i+1, ele);
	  break;
	}
  }
  if(if_found == 0)
    printf("%d is not found in the array!", ele);
  return 0;
}
