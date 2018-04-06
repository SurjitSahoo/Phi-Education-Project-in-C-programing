#include <stdio.h>
#include "mathlib.h"
int main()
{
  int n, r;
  printf("Enter the Value of n and r, (n>r) :\n");
  scanf("%d%d", &n, &r);
  printf("nCr = %ld\n", nCr(n, r));
  return 0;
}

