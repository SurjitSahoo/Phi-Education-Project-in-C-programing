#include <stdio.h>
int lcm(int a, int b, int c);
int main()
{
  int a, b, c;
  printf("Enter three positive numbers: \n");
  scanf("%d%d%d", &a, &b, &c);
  printf("\nLCM: %d", lcm(a, b, c));
  return 0;
}
int lcm(int a, int b, int c)
{
  int i = 1, x, l;
  x = a * b * c;
  while(c <= x){
    if((i % a) == 0 && (i % b) == 0 && (i % c) == 0){
      l = i;
      break;
    }
    i++;
  }
  return l;
}
