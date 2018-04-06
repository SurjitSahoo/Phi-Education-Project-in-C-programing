#include <stdio.h>
#include <stdlib.h>
#include "stringlib.h"
#include "dictionary.h"
/* lookup a node in the list */
void lookup(struct node *head, char *word)
{
  int found = 0;
  while(head != NULL){
    if(str_compare(head->word, word) == 0){
      found = 1;
      printf("\n\t%s\t\t\t%s\n", word, head->meaning);
      break;
    }
    head = head->next;
  }
  if(found == 0) printf("\nWord not found in the dictionary!!");
}
