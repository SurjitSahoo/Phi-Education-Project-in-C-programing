#include <stdio.h>
#include "dictionary.h"

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
