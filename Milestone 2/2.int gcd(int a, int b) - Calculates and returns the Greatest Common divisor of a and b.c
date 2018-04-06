#include <stdio.h>
int gcd(int a, int b);
int main()
{
  int a, b;
  printf("Enter two integers: \n");
  scanf("%d %d", &a, &b);
  printf("G.C.D of %d and %d is %d", a, b, gcd(a, b));
  return 0;
}
int gcd(int a, int b)
{
  int i, ans;
  for(i = 1; i <= a && i <= b; ++i){
    if((a % i) == 0 && (b % i) == 0)
      ans = i;
  }
  return ans;
}
