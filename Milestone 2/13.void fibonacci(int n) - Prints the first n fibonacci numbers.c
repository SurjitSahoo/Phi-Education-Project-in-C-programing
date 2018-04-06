#include <stdio.h>
void fibonacci(int n);
int main()
{
  int n;
  printf("Enter the number of terms: ");
  scanf("%d", &n);
  fibonacci(n);
  return 0;
}
void fibonacci(int n)
{
  int i, t1 = 0, t2 = 1, t3 = 0;
  printf("Fibonacci Series: ");
  printf("\n %d", t1);
  printf("\n %d", t2);
  for(i = 1; i <= (n - 2); ++i){
    t3 = t1 + t2;
    t1 = t2;
    t2 = t3;
    printf("\n %d", t3);
  }
}
