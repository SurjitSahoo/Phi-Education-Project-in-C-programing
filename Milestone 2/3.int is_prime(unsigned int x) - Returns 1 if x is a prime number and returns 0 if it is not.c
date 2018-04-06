#include <stdio.h>
int is_prime(unsigned int x);
int main()
{
  unsigned int n, result;
  printf("Enter a positive integer\n");
  scanf("%d", &n);
  result = is_prime(n);
  if(result == 1)
    printf("PRIME\n");
  else
    printf("NOT PRIME\n");
  return 0;
}
int is_prime(unsigned int x)
{
  int i, c = 0, y = x  / 2;
  for(i = 2; i <= y; i++){
    if((x % i) == 0)
      c++;
  }
  if(c == 0)
    return 1;
  else
    return 0;
}
