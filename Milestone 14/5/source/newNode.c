#include <stdlib.h>
#include "stringlib.h"
#include "dictionary.h"
/* Create a new node for the list */
struct node *newNode(struct node *head, char *word, char *meaning)
{
  struct node* newnode = (struct node*) calloc(1, sizeof(struct node));
  str_copy(newnode->word, word);
  str_copy(newnode->sort, meaning);
  newnode->next = NULL;
  return newnode;
}