#include <stdio.h>
int main()
{
  float lbs, kg;
  printf("Enter the weight in pound\n");
  scanf("%f", &lbs);
  kg = lbs * 0.453592;
  printf("%.2f pound = %.2f Killo Grams\n", lbs, kg);
  return 0;
}
