#include <stdio.h>
int main() 
{
  int len, breath, area;
  printf("\nEnter the Length of Rectangle : ");
  scanf("%d", &len);
  printf("\nEnter the Breadth of Rectangle : ");
  scanf("%d", &breath);
  area = len * breath;
  printf("\nArea of Rectangle : %d", area);
  return 0;
}
