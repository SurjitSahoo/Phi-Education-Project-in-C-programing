#include <stdio.h>
void factors(int x);
int main()
{
  int number;
  printf("Enter a positive integer: ");
  scanf("%d", &number);
  printf("Factors of %d are: ", number);
  factors(number);
  return 0;
}
void factors(int x)
{
  int i;
  for(i = 1; i <= x; i++) {
    if(x % i == 0) {
      printf("%d ", i);
    }
  }
}
