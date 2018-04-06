/*
                             *******************
******************************* C SOURCE FILE *******************************
**                           *******************                           **
**                                                                         **
** project  : Text to tweet converter                                      **
** filename : read_data.c                                                  **
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
#include <stdio.h>
#include <stdlib.h>
#include "dictionary.h"
/****************************************************************************/
void read_data(struct node **head, FILE *fp)
/****************************************************************************/
/*
* Read dictionary data from the file
*/
{
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
    //create a new node
    struct node *temp2 = (struct node*)malloc(sizeof(struct node));
    if(temp2 == NULL){
      printf("Couldn't make new node by malloc:");
      return;
    }
    *temp2 = temp;
    //if list is empty
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
/****************************************************************************/
/**                                                                        **/
/**                             EOF                                        **/
/**                                                                        **/
/****************************************************************************/
