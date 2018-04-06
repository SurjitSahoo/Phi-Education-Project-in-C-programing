#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <assert.h>

struct node{
  char word[20];        // Store the word data of the dictionary
  char meaning[5][100]; // Store the meaning of the word
                        //meaning is a 2D array so that it can store multiple meanings. 
  struct node *next;    // stores the address of the next node
};

int search(struct node *head, char *word)
{
  int found = 0;
  while(head != NULL){
    if(strcmp(head->word, word) == 0){
      found = 1;
      break;
    }
    head = head->next;
  }
  return found;
}

/* Create a new node for the list */
struct node *newNode(struct node *head, char *word)
{
  int i, j;
  char meaning[5][100], ch = 'y';
  i = search(head, word);
  if(i == 1){
    printf("Word already exists..\n");
    return head;
  }
  struct node* newnode = (struct node*) calloc(1, sizeof(struct node));
  strcpy(newnode->word, word);
  for(j = 0; tolower(ch) == 'y' && j<5; j++){
    printf("Enter the meaning - \n");
    scanf(" %99[^\n]",meaning[j]);
    strcpy(newnode->meaning[j], meaning[j]);
    if(j != 4){
      printf("Add more meanings (y/n) ");
      scanf(" %c", &ch);
    }
    else printf("You cannot enter more than 5 meanings!\n");
  }
  newnode->next = NULL;
  return newnode;
}

/* Adds a new node to the list in sorted order */
void sortedInsert(struct node** headref, struct node* newnode)
{
  struct node* current;
  if(*headref == NULL || strcmp((*headref)->word, newnode->word) >=0 ){
    newnode->next = *headref;
    *headref = newnode;
  }
  else{
    current = *headref;
    while(current->next != NULL && strcmp(current->next->word, newnode->word) < 0){
      current = current->next;
    }
    newnode->next = current->next;
    current->next = newnode;
  }
}

/*lookup a node in the list */
void lookup(struct node *head, char *word)
{
  int found = 0, i;
  while(head != NULL){
    if(strcmp(head->word, word) == 0){
      found = 1;
      /* I am printing 1st meaning in the 1st line and the other meanings
         from the second line using for loop. After printing on screen it looks good.
      */
      printf("\n\t%s\t\t\t%s\n", word, head->meaning[0]);
      for(i = 1; i < 5; i++) printf("\t\t\t\t%s\n", head->meaning[i]);
      printf("\n");
      break;
    }
    head = head->next;
  }
  if(found == 0) printf("\nWord not found in the dictionary!!");
}

/* Delete a node from the list */
struct node *del(struct node *head, char *word)
{
  int found = 0;
  struct node *temp = head;
  struct node *prev = NULL;
  while(temp != NULL){
    if(strcmp(temp->word, word) == 0){
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

/* Print the Whole Dictionary */
void print(struct node *head)
{
  int i;
  printf("\n\n\t\t**Dictionary**\n");
  printf("\tWORD\t\t\tMEANING\n");
  printf("\t********************************");
  while(head != NULL){
    printf("\n\t%s\t\t\t%s\n", head->word, head->meaning[0]);
    for(i = 1; i < 5; i++){
      printf("\t\t\t\t%s\n", head->meaning[i]);
    }  
    head = head->next;
  }
  printf("\n");
}

int main()
{
  struct node *head = NULL;
  int choice;
  char word [20];
  struct node *new_node;
  while(1){
    printf("\n\tDictionary\n");
    printf("\n\t1. Add a word & it's meaning");
    printf("\n\t2. lookup a word");
    printf("\n\t3. remove a word from the dictionary ");
    printf("\n\t4. print all the entries in the dictionary");
    printf("\n\t5. exit");
    printf("\n\n\tEnter your choice : ");
    scanf("%d", &choice);
    switch(choice){
    
    case 1 :
    
      printf("Enter the word : ");
      scanf(" %s", word);
      new_node = newNode(head, word);
      sortedInsert(&head, new_node);
      break;
      
    case 2 :
    
      printf("Enter the word to lookup : ");
      scanf(" %s", word);
      lookup(head, word);
      break;
      
    case 3 :
    
      printf("Enter the word you want to delete : ");
      scanf(" %s", word);
      head = del(head, word);
      break;
      
    case 4 :
    
      print(head);
      break;
      
    case 5 :
    
      return 0;
      
    default :
      
      printf("Invalid Entry!!");
      break;
      
    }
  }
}