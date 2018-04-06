/*
                             *******************
******************************* C SOURCE FILE *******************************
**                           *******************                           **
**                                                                         **
** project  : Text to tweet converter                                      **
** filename : convert.c	                                                   **
** version  : 1	                                                           **
** date     : June 02, 2017                                                **
**                                               	                   **
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

void sorted_insert(struct node** headref, struct node* newnode);
/****************************************************************************/
void sortlist(struct node **headRef)
/****************************************************************************/
{
  struct node* result = NULL;
  struct node* current = *headRef;
  struct node* next;
  while (current!=NULL){
    next = current->next;
    sorted_insert(&result, current);
    current = next;
  }
  *headRef = result;
}
/****************************************************************************/
/**                                                                        **/
/**                             EOF                                        **/
/**                                                                        **/
/****************************************************************************/
