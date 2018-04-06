#include <stdio.h>
int main()
{
  float inch, cm;
  printf("Enter the length in Inches\n");
  scanf("%f", &inch);
  cm = inch * 2.54;
  printf("%.2f Inches=%.2f Centimeters\n", inch, cm);
  return 0;
}
