#include <stdio.h>
int main()
{
  int i, j, a, n,choice, number[50];
  printf("How many nubers you want to enter for sorting?? \n");
  scanf("%d", &n);
  printf("Enter the numbers \n");
  for(i = 0; i < n; i++)
    scanf("%d", &number[i]);
  printf("How do you want to sort the numbers??\n\t1. Ascending\n\t2. Discending \n");
  scanf("%d", &choice);
  if(choice == 1) {
    for(i = 0; i < n; i++) {
      for(j = i + 1; j < n; j++) {
        if(number[i] > number[j]) {
          a =  number[i];
          number[i] = number[j];
          number[j] = a;
        }
      }
    }
  }
  if(choice == 2) {
    for(i = 0; i < n; i++) {
      for(j = i + 1; j < n; j++) {
        if(number[i] < number[j]) {
          a =  number[i];
          number[i] = number[j];
          number[j] = a;
        }
      }
    }
  }
  printf("The sorted numbers are given below \n");
  for(i = 0; i < n; ++i) {
    printf("%d\n", number[i]);
  }
  return 0;
}
