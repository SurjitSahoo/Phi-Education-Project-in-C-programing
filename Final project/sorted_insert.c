/*
                             *******************
******************************* C SOURCE FILE *******************************
**                           *******************                           **
**                                                                         **
** project  : Text to tweet converter                                      **
** filename : sorted_insert.c                                              **
** version  : 1                                                            **
** date     : June 02, 2017                                                **
**                                      	                           **
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
#include <stdlib.h>
#include "stringlib.h"
#include "dictionary.h"
/****************************************************************************/
void sorted_insert(struct node** headref, struct node* newnode)
/****************************************************************************/
/*
* Adds a new node to the list in descending sorted order 
*/
{
  struct node* current;
  if(*headref == NULL || str_compare((*headref)->word, newnode->word) <= 0){
    newnode->next = *headref;
    *headref = newnode;
  }
  else{
    current = *headref;
    while(current->next != NULL && str_compare(current->next->word, newnode->word) > 0){
      current = current->next;
    }
    newnode->next = current->next;
    current->next = newnode;
  }
}
/****************************************************************************/
/**                                                                        **/
/**                             EOF                                        **/
/**                                                                        **/
/****************************************************************************/
