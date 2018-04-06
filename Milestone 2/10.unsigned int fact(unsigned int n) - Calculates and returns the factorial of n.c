#include <stdio.h>
unsigned int factorial(unsigned int n);
int main()
{
  unsigned int n;
  printf("Enter a positive integer: ");
  scanf("%d", &n);
  printf("Factorial of %d = %d", n, factorial(n));
  return 0;
}
unsigned int factorial(unsigned int n)
{
  unsigned int i,f = 1;
  for(i = 1; i <= n; i++){
    f *= i;      // factorial : 5!=5*4*3*2*1
  }
  return f;
}
