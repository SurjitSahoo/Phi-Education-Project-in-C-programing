//Reverse linked-list using recursion

#include <stdio.h>
#include <stdlib.h>
struct node
{
  int data;
  struct node *next;
};

void insert(struct node **head, int x)
{
  struct node *temp = (struct node*)malloc(sizeof(struct node));
  temp->data = x;
  temp->next = NULL;
  if(*head != NULL) temp->next =  *head;
  *head = temp;
}

void print(struct node *head)
{
  while(head != NULL){
    printf("%d ", head->data);
    head = head->next;
  }
  printf("\n");
}

struct node *reverse(struct node *head)
{
  if(head == NULL) return NULL;
  if(head->next == NULL) return head;
  struct node *rest = reverse(head->next);
  head->next->next = head;
  head->next = NULL;
  return rest;
}

int main()
{
  struct node *head = NULL;
  insert(&head, 3);
  insert(&head, 9);
  insert(&head, 4);
  insert(&head, 7);
  printf("Source list : ");
  print(head);
  head = reverse(head);
  printf("Reversed list : ");
  print(head);
  return 0;
}