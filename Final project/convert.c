/*
                             *******************
******************************* C SOURCE FILE *******************************
**                           *******************                           **
**                                                                         **
** project  : Text to tweet converter                                      **
** filename : convert.c                                                    **
** version  : 1	                                                           **
** date     : June 02, 2017                                                **
**                          	                                           **
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
#include <stdio.h>
#include <assert.h>
#include "stringlib.h"
#include "dictionary.h"
/****************************************************************************/
void convert(char *tweet, struct node *head, char *srcString)
/****************************************************************************/
{
  assert(head != NULL && srcString != NULL);
  struct node *refhead = head;
  int position, toReplaceLen, replacementLen, chng = 0, resLen, found;
  char newsrc[500];
  str_copy(newsrc, srcString);
  char result[500];
  str_copy(result, srcString); //In case nothing is changed
  while(head != NULL){
    found = 0;
    position = str_find_substring(newsrc, head->word);
    if(position >= 0){
      found = 1;
      toReplaceLen = str_length(head->word);
      replacementLen = str_length(head->sort);
      //if *to be replaced* is present at the beginning
      if(position == 0){
        mem_copy(result, head->sort, replacementLen);
        str_copy(result + replacementLen, newsrc + toReplaceLen);
      }
      else{
        // copy part of old sentence before replacement
        mem_copy(result, newsrc, position);
        //copy replacement
        mem_copy(result + position, head->sort, replacementLen);
        //copy the rest
        str_copy(result + (position + replacementLen), newsrc + (position + toReplaceLen));
      }
      chng++; //Count the number of phrases changed
    }
    //update newsrc
    str_copy(newsrc, result);
    resLen = str_length(result);
    newsrc[resLen] = '\0';
    head = head->next;
    //When one phrase is changed, reset head to the beginning
    if(found == 1) head = refhead;
  }
  if((chng == 0) && (resLen <= 140))
    printf("\nNothing to change. You are good to go..\n");
  str_copy(tweet, result);
}
/****************************************************************************/
/**                                                                        **/
/**                             EOF                                        **/
/**                                                                        **/
/****************************************************************************/
