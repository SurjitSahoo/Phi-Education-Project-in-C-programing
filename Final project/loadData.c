/*
                             *******************
******************************* C SOURCE FILE *******************************
**                           *******************                           **
**                                                                         **
** project  : Text to tweet converter                                      **
** filename : loadData.c                                                   **
** version  : 1                                                            **
** date     : June 02, 2017                                                **
**                                                                         **
*****************************************************************************
VERSION HISTORY:
----------------
Version     : 1
Date        : June 02, 2017
Revised by  : Surjit Kumar Sahoo
Description : Original version.
*/
/****************************************************************************/
/**                                                                        **/
/**                          MODULES USED                                  **/
/**                                                                        **/
/****************************************************************************/
#include "dictionary.h"
#include <stdlib.h>

void sorted_insert(struct node** headref, struct node* newnode);
/****************************************************************************/
struct node* loadData(struct node *head, FILE *fp)
/****************************************************************************/
{
  if(fp == NULL){
    printf("Error opening file..\n");
    return head;
  }
  struct node temp;
  temp.next = NULL;
  int c = 0;
  struct node *hp = head;

  while(!feof(fp)){
    fscanf(fp, " %[^:]", temp.word);
    fseek(fp, 1, SEEK_CUR);
    fscanf(fp, " %[^\n]", temp.sort);
    //search if the element already exists in the list. if not add it
    //in sorted order
    if((c = search(hp, temp.word)) == 0){
      struct node *temp2 = (struct node*)malloc(sizeof(struct node));
      if(temp2 == NULL){
        printf("Couldn't make new node by malloc:");
        return head;
      }
      *temp2 = temp;
      sorted_insert(&head, temp2);
    }
  }
  fclose(fp);
  printf("Batch load successful..\n");
  return head;
}
/****************************************************************************/
/**                                                                        **/
/**                             EOF                                        **/
/**                                                                        **/
/****************************************************************************/
