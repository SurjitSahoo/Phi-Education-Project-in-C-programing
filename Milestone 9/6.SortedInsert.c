#include <stdio.h>
#include <stdlib.h>
struct node{
  int data;
  struct node* next;
};

/* Given a sorted list in increasing order, inserts new node
 to the corect sorted position */
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

/* Create a new node */
struct node *newNode(int data)
{
  struct node* newnode = (struct node*) malloc(sizeof(struct node));
  newnode->data = data;
  newnode->next = NULL;
  return newnode;
}

/* Prints the list */
void print(struct node *head)
{
  struct node *temp = head;
  printf("The list is\n");
  while(temp != NULL){
    printf("%d  ", temp->data);
    temp = temp->next;
  }
  printf("\n");
}

/* The main function */
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
  return 0;
}
