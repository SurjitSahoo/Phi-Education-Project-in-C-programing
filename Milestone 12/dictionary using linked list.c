#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <assert.h>

struct node{
  char word[20];         // Store the word data of the dictionary
  char meaning[20];      // Store the meaning of the word
  struct node *next;     // stores the address of the next node
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
struct node *newNode(struct node *head, char *word, char *meaning)
{
  struct node* newnode = (struct node*) calloc(1, sizeof(struct node));
  strcpy(newnode->word, word);
  strcpy(newnode->meaning, meaning);
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
  int found = 0;
  while(head != NULL){
    if(strcmp(head->word, word) == 0){
      found = 1;
      printf("\n\t%s\t\t\t%s\n", word, head->meaning);
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
  	//search the word if it exists
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
  printf("\n\n\t\t**Dictionary**\n");
  printf("\tWORD\t\t\tMEANING\n");
  printf("\t*******************************\n");
  while(head != NULL){
    printf("\t%s\t\t\t%s\n", head->word, head->meaning);  
    head = head->next;
  }
}

/* Save dictionary data to the file on disk */
void WriteData(struct node *head)
{
  FILE *fp = fopen("dictionary.txt", "w");
  if(fp == NULL){
    printf("Error opening file..\n"); 
    return;
  } 
  while(head != NULL){
  	fprintf(fp, "\n%s:", head->word);
  	fprintf(fp, "%s", head->meaning);
  	head = head->next;
  }	
  fclose(fp);
  printf("Data saved successfully..\n");
}

/*Read dictionary data from the file */
void ReadData(struct node **head)
{
  FILE *fp = fopen("dictionary.txt", "r");
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
    fscanf(fp, " %[^\n]", temp.meaning);
    struct node *temp2 = (struct node*)malloc(sizeof(struct node));
    if(temp2 == NULL){
      printf("Couldn't make new node by malloc:");
      return;
    }
    *temp2 = temp;
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

int main()
{
  struct node *head = NULL;
  int choice, check;
  char word [20], meaning[20];
  struct node *new_node;
  while(1){
    printf("\n\tDictionary\n");
    printf("\n\t1. Add a word & it's meaning");
    printf("\n\t2. lookup a word");
    printf("\n\t3. remove a word from the dictionary ");
    printf("\n\t4. print all the entries in the dictionary");
    printf("\n\t5. Save dictionary to a file");
    printf("\n\t6. Load dictionary from file");
    printf("\n\t7. exit");
    printf("\n\n\tEnter your choice : ");
    scanf("%d", &choice);
    switch (choice){
    case 1 :
    
      printf("Enter the word : ");
      scanf(" %s", word);
      check = search(head, word);
      if(check == 1){
      	printf("word already exists\n");
      	break;
      }
      else{
      	printf("Enter the meaning : ");
      	scanf(" %[^\n]", meaning);
      	new_node = newNode(head, word, meaning);
      	sortedInsert(&head, new_node);
      }
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
    
      WriteData(head);
      break;
      
    case 6 :
      
      ReadData(&head);
      break;
            
    case 7 :
            
      return 0;
          
    default :
        
      printf("Invalid Entry!!");
      

    }
  }
}
