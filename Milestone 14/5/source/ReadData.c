#include <stdio.h>
#include <stdlib.h>
#include "dictionary.h"
/*Read dictionary data from the file */
void ReadData(struct node **head)
{
  FILE *fp = fopen("dictionary.txt", "r");
  if(fp == NULL){
    printf("Error opening file..\n");
    return;
  }
  struct node temp;
  temp.next = NULL;
  struct node *hp, *curr;
  hp = *head;
  while(!feof(fp)){
    fscanf(fp, " %[^:]", temp.word);
    fseek(fp, 1, SEEK_CUR);
    fscanf(fp, " %[^\n]", temp.sort);
    struct node *temp2 = (struct node*)malloc(sizeof(struct node));
    if(temp2 == NULL){
      printf("Couldn't make new node by malloc:");
      return;
    }
    *temp2 = temp;
    if(hp == NULL){
      curr = hp = temp2;
    } 
    else
      curr = curr->next = temp2;
  }
  fclose(fp);
  *head = hp;
  printf("Data loaded successfully..\n");
}
