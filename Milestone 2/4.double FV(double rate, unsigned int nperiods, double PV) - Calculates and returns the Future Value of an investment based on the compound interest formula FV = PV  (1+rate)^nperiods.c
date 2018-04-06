#include <stdio.h>
double FV(double rate, unsigned int nperiods, double PV);
int main()
{
  double PV;
  double rate;
  unsigned int nperiods;
  double result;
  printf("Present Value  : ");
  scanf("%lf", &PV);
  printf("\nAnnual Rate: ");
  scanf("%lf", &rate);
  printf("\nNo of Years: ");
  scanf("%d", &nperiods);
  result = FV(rate, nperiods, PV);
  printf("The future value is :  %.2lf \n", result);
  return 0;
}

double FV(double rate, unsigned int nperiods, double PV)
{
  int i;
  double value = (1 + rate) ;
  double x = 1, result;
  for(i = 0; i < nperiods; i++){
    x *= value;
  }
  result = PV * x;
  return result;
}
