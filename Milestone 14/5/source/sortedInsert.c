#include <stdlib.h>
#include "stringlib.h"
#include "dictionary.h"
/* Adds a new node to the list in sorted order */
void sortedInsert(struct node** headref, struct node* newnode)
{
  struct node* current;
  if(*headref == NULL || str_compare((*headref)->word, newnode->word) >=0 ){
    newnode->next = *headref;
    *headref = newnode;
  }
  else{
    current = *headref;
    while(current->next != NULL && str_compare(current->next->word, newnode->word) < 0){
      current = current->next;
    }
    newnode->next = current->next;
    current->next = newnode;
  }
}
