#include <stdio.h>
#include <stdlib.h>
struct node{
  int data;
  struct node* next;
};

struct node* insert(struct node* head, int x)
{
  struct node* temp1 = (struct node*)malloc(sizeof(struct node));
  temp1->data = x;
  if(head == NULL){
    temp1->next = NULL;
    head = temp1;
    return head;
  }
  struct node* temp2 = head;
  while(temp2->next != NULL){
    temp2 = temp2->next;
  }
  temp2->next = temp1;
  temp1->next = NULL;
  return head;
}

void print(struct node* head)
{
  while(head != NULL){
    printf(" %d ", head->data);
    head = head->next;
  }
  printf("\n");
}

void Reverse(struct node** headRef)
{
  struct node* result = NULL;
  struct node* current = *headRef;
  struct node* next;
  while (current != NULL){
    next = current->next;
    current->next = result;
    result = current;
    current = next;
  }
  *headRef = result;
}

int main()
{
  struct node *head = NULL;
  head = insert(head, 3);
  head = insert(head, 10);
  head = insert(head, 7);
  head = insert(head, 9);
  head = insert(head, 8);
  head = insert(head, 8);
  printf("The source list is : ");
  print(head);
  Reverse(&head);
  printf("The reversed list is : ");
  print(head);
  return 0;
}
