#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

/**********************************************************************************************************
*                            Function Prototypes
**********************************************************************************************************/
/** I have taken two comparison functions for 1 data type **/
int CompIntAscending(void *x, void *y);
int CompIntDescending(void *x, void *y);
int CompFloatAscending(void *x, void *y);
int CompFloatDescending(void *x, void *y);
int CompCharAscending(void *x, void *y);
int CompCharDescending(void *x, void *y);
int CompStrAscending(void *x, void *y);
int CompStrDecending(void *x, void *y);
void *mem_copy(void *dest, const void *src, unsigned int n);
void *Sort(void* arr, int (*compareFcn)(void*, void*), int sizeOfElement, int numElements);

/********************************************************************************************************
*                             Main Function
********************************************************************************************************/
int main()
{
  int max;
  int choice, num[50], i, sortOpt ;
  float floatNum[50] ;
  char c[50] ;
  char str[50][50] ;

  printf("what do you want to sort?\n");
  printf("\t1. Integers");
  printf("\n\t2. Float");
  printf("\n\t3. Character");
  printf("\n\t4. Strings");
  printf("\n\n\tEnter your choice : ");
  scanf("%d", &choice);
  switch (choice) {
    case 1 :
      
      printf("How many Numbers you want to sort ? ");
      scanf("%d", &max);
      printf("Enter the numbers\n");
      for(i = 0; i < max; i++) scanf("%d", &num[i]);
      printf("How do you want to sort ?\n\t1. Ascending \n\t2. Descending\n");
      scanf("%d", &sortOpt);
      if(sortOpt == 1) Sort((void*)num, CompIntAscending, sizeof(int), max);
      else Sort((void*)num, CompIntDescending, sizeof(int), max);
      printf("Sorted elements are are - \n");
      for(i = 0; i < max; i++) printf(" %d\n", num[i]);
      break;
      
    case 2 :
      
      printf("How many Float numbers you want to sort ? ");
      scanf("%d", &max);
      printf("Enter the numbers\n");
      for(i = 0; i < max; i++) scanf("%f", &floatNum[i]);
      printf("How do you want to sort ?\n\t1. Ascending \n\t2. Descending\n");
      scanf("%d", &sortOpt);
      if(sortOpt == 1) Sort((void*)floatNum, CompFloatAscending, sizeof(float), max);
      else Sort((void*)floatNum, CompFloatDescending, sizeof(float), max);
      printf("Sorted elements are are - \n");
      for(i = 0; i < max; i++) printf(" %f\n", floatNum[i]);
      break;
      
    case 3 :
      
      printf("How many Characters you want to sort ? ");
      scanf("%d", &max);
      printf("Enter the Characters\n");
      for(i = 0; i < max; i++) scanf(" %c", &c[i]);
      printf("How do you want to sort ?\n\t1. Ascending \n\t2. Descending\n");
      scanf("%d", &sortOpt);
      if(sortOpt == 1) Sort((void*)c, CompCharAscending, sizeof(char), max);
      else Sort((void*)c, CompCharDescending, sizeof(char), max);
      printf("Sorted elements are are - \n");
      for(i = 0; i < max; i++) printf(" %c\n", c[i]);
      break;
      
    case 4 :
      
      printf("How many Strings you want to sort ? ");
      scanf("%d", &max);
      printf("Enter the strings\n");
      for(i = 0; i < max; i++) scanf(" %s", str[i]); //Enter strings without s pace
      printf("How do you want to sort ?\n\t1. Ascending \n\t2. Descending\n");
      scanf("%d", &sortOpt);
      if(sortOpt == 1) Sort((void*)str, CompStrAscending, sizeof(str[50]), max);
      else Sort((void*)str, CompStrDecending, sizeof(str[50]), max);
      printf("Sorted elements are are - \n");
      for(i = 0; i < max; i++) printf(" %s\n", str[i]);
      break;
      
    default :
      printf("Invalid Entry. Try again !!\n");
    }
    return 0;
}

/************************************************************************************************************
*                                  Function Definitions
************************************************************************************************************/
void* Sort(void* arr, int (*compareFcn)(void*, void*), int sizeOfElement, int numElements)
{
  if(!arr || !compareFcn || !numElements || !sizeOfElement)
    return NULL;

  int i, j ;
  void *temp = calloc(1, sizeOfElement);
  for(i = 0; i < numElements; i++)
    for(j = i+1; j < numElements; j++)
      /* Compare two consecutive elements */
      if(compareFcn((((char*)arr) + (i*sizeOfElement)),
                    (((char*)arr) + (j*sizeOfElement)) ) > 0){
        mem_copy(temp, (((char*)arr) + (i*sizeOfElement)), sizeOfElement);
        mem_copy((((char*)arr) + (i*sizeOfElement)),
                 (((char*)arr) + (j*sizeOfElement)), sizeOfElement);
        mem_copy((((char*)arr) + (j*sizeOfElement)), temp, sizeOfElement);
      }
  free(temp);
  return arr;
}

/************************************************************************************************************/
void *mem_copy(void *dest, const void *src, unsigned int n)
{
  assert(src != NULL);  
  int i;
  char* newsrc = (char*)src;
  char* newdest = (char*)dest;
  if(newdest < newsrc){
    for(i = 0; i < n; i++)
      newdest[i] = newsrc[i];
  }
  else{
    /* Copy backwards so that memory won't overlap */
    for(i = n - 1; i >= 0; i--)
      newdest[i] = newsrc[i];
    }
  return dest;
}

/***************************************** Int Comparison *****************************************************/
int CompIntAscending(void *x, void *y)
{
  int a = *((int*)x);
  int b = *((int*)y);
  if(a > b) return 1;
  else return -1;
}
int CompIntDescending(void *x, void *y)
{
  int a = *((int*)x);
  int b = *((int*)y);
  if(a > b) return -1;
  else return 1;
}

/**************************************** Float Comparison ******************************************************/
int CompFloatAscending(void *x, void *y)
{
  float a = *((float*)x);
  float b = *((float*)y);
  if(a > b) return 1;
  else return -1;
}
int CompFloatDescending(void *x, void *y)
{
  float a = *((float*)x);
  float b = *((float*)y);
  if(a > b) return -1;
  else return 1;
}

/***************************************** Char Comparison *******************************************************/
int CompCharAscending(void *x, void *y)
{
  char a = *((char*)x);
  char b = *((char*)y);
  if(a > b) return 1;
  else return -1;
}
int CompCharDescending(void *x, void *y)
{
  char a = *((char*)x);
  char b = *((char*)y);
  if(a > b) return -1;
  else return 1;
}

/******************************************* String Comparison ***************************************************/
int CompStrAscending(void *x, void *y)
{
  char *a = (char*)x;
  char *b = (char*)y;
  int c1 = 0, c2 = 0, cmp = 0, i = 0;
  while(a[c1] != '\0') c1 += 1;
  while(b[c2] != '\0') c2 += 1;
  while((i < c1) && (i < c2)){
    if(a[i] == b[i]){
      i++;
      continue;
    }
    if(a[i] < b[i]){
      cmp = (-1);
      break;
    }
    if(a[i] > b[i]){
      cmp = 1;
      break;
    }
  }
  return cmp;
}
int CompStrDecending(void *x, void *y)
{
  char *a = (char*)x;
  char *b = (char*)y;
  int c1 = 0, c2 = 0, cmp = 0, i = 0;
  while(a[c1] != '\0') c1 += 1;
  while(b[c2] != '\0') c2 += 1;
  while((i < c1) && (i < c2)){
    if(a[i] == b[i]){
      i++;
      continue;
    }
    if(a[i] < b[i]){
      cmp = 1;
      break;
    }
    if(a[i] > b[i]){
      cmp = (-1);
      break;
    }
  }
  return cmp;
}
