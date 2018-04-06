#include <stdio.h>
#include <stdlib.h>
#include "stringlib.h"
#include "dictionary.h"
/* Delete a node from the list */
struct node *del(struct node *head, char *word)
{
  int found = 0;
  struct node *temp = head;
  struct node *prev = NULL;
  while(temp != NULL){
    if(str_compare(temp->word, word) == 0){
      found = 1;
      if(prev == NULL){ 
        /*If the node is the head*/
        head = head->next;
        free(temp);
        printf("Word Deleted..\n");
        break;
      }
      else{
        prev->next = temp->next;
        free(temp);
        printf("Word Deleted..\n");
        break;
      }
    }
    prev = temp;
    temp = temp->next;
  }
  if(found == 0) 
    printf("Word not found\n"); 
  return head;
}
