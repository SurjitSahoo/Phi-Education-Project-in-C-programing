#include <stdio.h>
void primefactor(unsigned int x);
int main()
{
  unsigned int n;
  printf("Enter a positive integer\n");
  scanf("%d", &n);
  printf("Prime factors of %d are : ", n);
  primefactor(n);
  return 0;
}
void primefactor(unsigned int x)
{
  int i, j, c = 0;
  for(i = 1; i <= x; i++) {
    c = 0;
    if((x % i) == 0) {
      for( j= 1; j <= i; j++) {
        if((i % j) == 0)
          c++;
      }
        if(c == 2)
          printf(" %d ", i);
    }
  }
}
