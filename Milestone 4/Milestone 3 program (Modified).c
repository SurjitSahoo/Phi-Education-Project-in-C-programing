#include <stdio.h>
int main()
{
  int number[50], choice, num, i, found, k = 0, position, sort, j, a;
  while(1) {
    found = 0;
    printf("\n\nChose your option\n");
    printf("\t1. Add an element to the array\n");
    printf("\t2. Search an element in the array\n");
    printf("\t3. Remove an element from the array\n");
    printf("\t4. Sort the array\n");
    printf("\t5. Print all the elements in the array\n");
    printf("\t6. exit\n");
    scanf("%d", &choice);

    switch (choice) {

    case 1 :

      if(k < 50){
        printf("Enter the number : ");
        scanf("%d", &num);
        for(i=0; i < k; i++){
          if(num == number[i]) {
            found=1;
            printf("Element already added. Please try again\n");
            break;
          }
        }
        if(found == 0){
          number[k]=num;
          k = k+1;
          printf("Element added successfully\n");
        }
      }
      else
        printf("Array full\n");
      break;

    case 2 :

      printf("Enter the element you want to search : ");
      scanf("%d", &num);
      for(i = 0; i < k; i++){
        if(num == number[i]){
          found = 1;
          printf("Found %d at index : %d\n", num, i+1);
          break;
        }
      }
      if(found == 0)
        printf("%d not found in the array\n", num);
      break;
      
    case 3 :
        
      printf("Enter the element to remove : ");
      scanf("%d", &num);
      for(i = 0; i < k; i++){
        if(num == number[i]){
          found = 1;
          position = i;
        }
      }
      if(found == 1){
        for(i = position; i < k; i++)
          number[i] = number[i+1];
        k = k-1;
        printf("Element removed\n");
      }
      if(found == 0)
        printf("%d not removed \n", num);
      break;
      
    case 4 :

      printf("How do you want to sort the numbers??\n\t1. Ascending\n\t2. Descending \n");
      scanf("%d", &sort);
      if(sort == 1){
        for(i = 0; i < k; i++){
          for(j = i + 1; j < k; j++){
            if(number[i] > number[j]) {
              a =  number[i];
              number[i] = number[j];
              number[j] = a;
            }
          }
        }
      }
      if(sort == 2){
        for(i = 0; i < k; i++){
          for(j = i + 1; j < k; j++){
            if(number[i] < number[j]) {
              a =  number[i];
              number[i] = number[j];
              number[j] = a;
            }
          }
        }
      }
      printf("The sorted numbers are given below \n");
      for(i = 0; i < k; ++i)
        printf("%d\n", number[i]);
      break;
        
    case 5 :

      printf("The array is displayed below\n");
      for(i = 0; i < k; i++)
        printf(" %d\n", number[i]);
      break;

    case 6 :
        
      return 0;
        
    default :
      
      printf("Invalid Option. Please try again\n");
      

    }
  }
}
