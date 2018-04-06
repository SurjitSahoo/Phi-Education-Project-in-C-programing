#include <stdio.h>
#include <stdlib.h>
struct node{
  int data;
  struct node* next;
};

/* Inserts a node at given index */
void insert(struct node** headRef, int index, int Data)
{
  int distanceFromHead = 1;
  struct node* head = *headRef;
  struct node* temp1 = (struct node*)malloc(sizeof(struct node));
  temp1->data = Data;
  if(index == 0){
    temp1->next = head;
    *headRef = temp1;
    return;
  }
  while(head != NULL){
    if(distanceFromHead == index){
      temp1->next = head->next;
      head->next = temp1;
    }
    head = head->next;
    distanceFromHead++;
  }
  /* For error handling */
  if(head == NULL && distanceFromHead < index) {
    printf("Error!! \nCan't add %d at position %d \nTry Again\n", Data, index);
  }
}

void print(struct node* head)
{
  printf("The list is\n");
  while(head != NULL){
    printf(" %d ", head->data);
    head = head->next;
  }
  printf("\n");
}

int main()
{
  struct node *head = NULL;
  insert(&head, 0, 3);
  insert(&head, 1, 4);
  insert(&head, 1, 7);
  insert(&head, 2, 9);
  insert(&head, 4, 8);
  insert(&head, 3, 8);
  insert(&head, 10, 8);
  print(head);
  return 0;
}
