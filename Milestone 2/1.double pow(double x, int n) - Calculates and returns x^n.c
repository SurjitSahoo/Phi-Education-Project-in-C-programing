#include <stdio.h>
double power(double x, int n);
int main()
{
  int exp;
  double base;
  printf("Enter a base number: ");
  scanf("%lf", &base);
  printf("Enter an exponent: ");
  scanf("%d", &exp);
  printf("Answer = %lf", power(base, exp));
  return 0;
}
double power(double base, int exp)
{
  double ans = 1;
  while (exp != 0){
    ans *= base;
    --exp;
  }
  return ans;
}
