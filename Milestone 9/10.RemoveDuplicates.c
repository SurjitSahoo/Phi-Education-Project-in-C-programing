#include <stdio.h>
#include <stdlib.h>
struct node{
  int data;
  struct node* next;
};

void sortedInsert(struct node** headref, struct node* newnode)
{
  struct node* current;
  if(*headref == NULL || (*headref)->data >= newnode->data){
    newnode->next = *headref;
    *headref = newnode;
  }
  else{
    current = *headref;
    while(current->next != NULL &&
          current->next->data < newnode->data){
      current = current->next;
    }
    newnode->next = current->next;
    current->next = newnode;
  }
}

struct node *newNode(int data)
{
  struct node* newnode = (struct node*) malloc(sizeof(struct node));
  newnode->data = data;
  newnode->next = NULL;
  return newnode;
}

void print(struct node *head)
{
  while(head != NULL){
    printf("%d  ", head->data);
    head = head->next;
  }
  printf("\n");
}

/* Takes a sorted list in increasing order and removes 
 duplicate nodes */
void RemoveDuplicates(struct node* head)
{
  struct node* current = head;
  if(current == NULL) return;
  while(current->next!=NULL){
    if(current->data == current->next->data){
      struct node* nextNext = current->next->next;
      free(current->next);
      current->next = nextNext;
    }
    else current = current->next;
  }
}
int main()
{
  struct node* head = NULL;
  struct node *new_node = newNode(8);
  sortedInsert(&head, new_node);
  new_node = newNode(3);
  sortedInsert(&head, new_node);
  new_node = newNode(12);
  sortedInsert(&head, new_node);
  new_node = newNode(9);
  sortedInsert(&head, new_node);
  new_node = newNode(3);
  sortedInsert(&head, new_node);
  new_node = newNode(7);
  sortedInsert(&head, new_node);
  print(head);
  RemoveDuplicates(head);
  print(head);
  return 0;
}
