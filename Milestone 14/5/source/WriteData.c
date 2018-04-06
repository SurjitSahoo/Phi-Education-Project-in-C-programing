#include <stdio.h>
#include <stdlib.h>
#include "dictionary.h"
/* Save dictionary data to the file on disk */
void WriteData(struct node *head)
{
  FILE *fp = fopen("dictionary.txt", "w");
  if(fp == NULL){
    printf("Error opening file..\n"); 
    return;
  } 
  while(head != NULL){
    fprintf(fp, "\n%s:", head->word);
    fprintf(fp, "%s", head->sort);
    head = head->next;
  } 
  fclose(fp);
  printf("Data saved successfully..\n");
}
