#include <stdio.h>
double PV(double rate, unsigned int nperiods, double FV);
int main()
{
  double FV;
  double rate;
  unsigned int  nperiods;
  double result;
  printf("Final Value  : ");
  scanf("%lf", &FV);
  printf("\nAnnual Rate: ");
  scanf("%lf", &rate);
  printf("\nNo of Years: ");
  scanf("%d", &nperiods);
  result = PV(rate, nperiods, FV);
  printf("The Present value is :  %.2lf \n", result);
  return 0;
}

double PV(double rate, unsigned int nperiods, double FV)
{
  int i;
  double value = (1 + rate);
  double x = 1, result;
  for(i = 0; i < nperiods; i++){
    x *= value;
  }
  result = FV / x;
  return result;
}
