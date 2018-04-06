/*
                             *******************
******************************* C SOURCE FILE *******************************
**                           *******************                           **
**                                                                         **
** project  : Text to tweet converter                                      **
** filename : main.c                                                       **
** version  : 1                                                            **
** date     : June 02, 2017                                                **
**                              	                                   **
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
#include <stdio.h>
#include <stdlib.h>
#include "stringlib.h"
#include "dictionary.h"

/****************************************************************************/
/**                                                                        **/
/**                      DEFINITIONS AND MACROS                            **/
/**                                                                        **/
/****************************************************************************/
#define MAX 500

/****************************************************************************/
/**                                                                        **/
/**                   PROTOTYPES OF LOCAL FUNCTIONS                        **/
/**                                                                        **/
/****************************************************************************/
void sortlist(struct node **headRef);
void sorted_insert(struct node** headref, struct node* newnode);
void read_data(struct node **head, FILE *fp);
void convert(char *tweet, struct node *head, char *srcString);
struct node* loadData(struct node *head, FILE *fp);

/****************************************************************************/
int main(int argc, char *argv[])
/****************************************************************************/
{
  (void)argc;
  FILE *fp = fopen(argv[1], "r");
  FILE *lg;
  FILE *p;
  if(fp == NULL) printf("Error opening file..\n");
  struct node *head = NULL;
  read_data(&head, fp);
  sortlist(&head);
  int choice, check, logOpt = 0;
  char srcString[MAX], tweet[MAX] = "", newWord[10], sortForm[10], newFile[100];
  while(1){
    printf("\t\n** GET YOUR TWEET **\n");
    printf("\n1. Convert a sentense to tweet");
    printf("\n2. Add new word to dictionary");
    printf("\n3. Save current dictionary to a file");
    printf("\n4. Batch load new dictionary items from a fle");
    printf("\n5. Log your conversions");
    printf("\n\n0. Exit");
    printf("\n\nEnter your choice : ");
    scanf("%d", &choice);
    switch(choice){

    case 1 :

      printf("\nEnter your sentense/phrase\n");
      scanf(" %499[^\n]", srcString);
      convert(tweet, head, srcString);
      if(str_length(tweet) <= 140){
        printf("Your tweet is\n%s", tweet);
        if(logOpt == 1){
          fprintf(lg, "Input : %s\n", srcString);
          fprintf(lg, "Output : %s\n", tweet);
        }
      }
      else{
        printf("\nUnable to convert your phrase!!");
        if(logOpt == 2){
          fprintf(lg, "Input : %s\n", srcString);
          fprintf(lg, "Output : %s\n", tweet);
        }
      }
      if(logOpt == 3){
        fprintf(lg, "Input : %s\n", srcString);
        fprintf(lg, "Output : %s\n", tweet);
      }
      break;

    case 2 :

      printf("\nEnter the word/phrase\n");
      scanf(" %[^\n]", newWord);
      check = search(head, newWord);
      if(check == 1)
        printf("Word already exists..\n");
      else{
        printf("Enter it's sort form : ");
        scanf(" %s", sortForm);
        //create a new node
        struct node* new_node = (struct node*) calloc(1, sizeof(struct node));
        str_copy(new_node->word, newWord);
        str_copy(new_node->sort, sortForm);
        new_node->next = NULL;
        //insert node to the list in descending sorted order
        sorted_insert(&head, new_node);
        printf("Data entered successfully..\n");
      }
      break;

    case 3 :

      WriteData(head);
      break;

    case 4 :

      printf("Enter the file name without space : ");
      scanf(" %99[^\n]", newFile);
      p = fopen(newFile, "r");
      head = loadData(head, p);
      break;

    case 5 :

      lg = fopen("conversions.log", "a");
      if(lg == NULL) printf("Error opening log file..\n");
      else{
        printf("\nWhat do you want to log?\n");
        printf("\n1. Successful conversions");
        printf("\n2. Failed conversions");
        printf("\n3. All conversions\n");
        scanf("%d", &logOpt);
        if(logOpt != 1 && logOpt != 2 && logOpt != 3)
          printf("Invalid Input. Try again..\n");
      }
      break;

    case 0 :

      return 0;

    default :

      printf("\nInvalid Entry!!\n");

    }

  }

}
/****************************************************************************/
/**                                                                        **/
/**                             EOF                                        **/
/**                                                                        **/
/****************************************************************************/
