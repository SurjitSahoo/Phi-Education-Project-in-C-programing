#include <stdio.h>
#include <stdlib.h>
struct node{
  int data;          //stores the data of the linked-list
  struct node* next; //stores the address of the next node
};

struct node *insert(struct node *head, int x)
{
  struct node* temp1 = (struct node*)malloc(sizeof(struct node));
  temp1->data = x;
  if(head == NULL){
    temp1->next = NULL;
    head = temp1;
    return head;
  }
  struct node* temp2 = head;
  while(temp2->next != NULL) {
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
/* Counts the number of times a given integer occurs */
int count(struct node* head, int n)
{
  int c = 0;
  while(head != NULL){
    if(head->data == n) c+=1;
      head = head->next;
  }
  return c;
}
/**************************************************/
int main()
{
  struct node *head = NULL;
  int n, c;
  head = insert(head, 3);
  head = insert(head, 4);
  head = insert(head, 7);
  head = insert(head, 9);
  head = insert(head, 8);
  head = insert(head, 8);
  printf("Enter the number to be searched : ");
  scanf("%d", &n);
  c = count(head, n);
  printf("%d is present %d times in the list\n", n,c);
  print(head);
  return 0;
}
