#include <stdio.h>
void evenOrOdd(int x);
int main()
{
  int a;
  printf("Enter a number : ");
  scanf("%d", &a);
  evenOrOdd(a);
  return 0;
}
void evenOrOdd(int x)
{
  if((x % 2) == 0)
    printf("\nEVEN");
  else
    printf("\nODD");
}
