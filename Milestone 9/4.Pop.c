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
  printf("The list is\n");
  while(head != NULL){
    printf(" %d ", head->data);
    head = head->next;
  }
  printf("\n");
}
/**************************************************/
/* Deletes the head node and returns the data value of that node */
int pop(struct node **headRef)
{
  int ans;
  struct node *head = *headRef;
  if(head == NULL) return 0;
  ans = head->data;
  *headRef = head->next;
  free(head);
  return(ans);
}
/**************************************************/
int main()
{
  struct node *head = NULL;
  int n;
  head = insert(head, 3);
  head = insert(head, 4);
  head = insert(head, 7);
  head = insert(head, 9);
  head = insert(head, 8);
  head = insert(head, 8);
  printf("Before using pop()\n");
  print(head);
  n = pop(&head);
  printf("pop() returned : %d\n", n);
  printf("After using pop()\n");
  print(head);
  return 0;
}
