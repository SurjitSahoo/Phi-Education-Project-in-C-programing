#include <stdio.h> 
int main()
{
  float c, f;
  printf("Please Enter the temperature in farenhiet: \n");
  scanf("%f", &f);
  c = (f - 32) * 5 / 9;
  printf("\n %.2f f = %.2f c", f, c);
  return 0;
}
