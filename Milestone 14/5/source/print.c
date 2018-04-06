#include <stdio.h>
#include <stdlib.h>
#include "dictionary.h"
/* Print the Whole Dictionary */
void print(struct node *head)
{
  printf("\n\n\t\t**Dictionary**\n");
  printf("\tWORD\t\t\tMEANING\n");
  printf("\t*******************************\n");
  while(head != NULL){
    printf("\t%s\t\t\t%s\n", head->word, head->meaning);  
    head = head->next;
  }
}
