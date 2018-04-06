#include <stdio.h>
long int factorial(int x);
long int nPr(int n, int r);
int main()
{
  int n, r;
  printf("Enter the Value of n and r, (n>r) :\n");
  scanf("%d%d", &n, &r);
  printf("nPr = %ld\n", nPr(n, r));
  return 0;
}
long int factorial(int x)
{
  long int f = 1;
  int i;
  for( i= 1; i <= x; i++){
    f = f * i;
  }
  return f;
}
long int nPr(int n, int r)
{
  long int a = factorial(n) / factorial(n - r);
  return a;
}
