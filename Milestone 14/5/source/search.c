#include <stdlib.h>
#include "stringlib.h"
#include "dictionary.h"
//Search a word in the list
int search(struct node *head, char *word)
{
  int found = 0;
  while(head != NULL){
    if(str_compare(head->word, word) == 0){
      found = 1;
      break;
    }
    head = head->next;
  }
  return found;
}