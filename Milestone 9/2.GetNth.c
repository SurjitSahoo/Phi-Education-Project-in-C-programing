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
/* Returns the data value stored at given index */
int GetNth(struct node* head, int index)
{
  int i;
  for(i = 0; (i <= index) && (head != NULL); i++){
    if(i == index) return head->data;
    head = head->next;
  }
  return 0;
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
  printf("Enter the index number : ");
  scanf("%d", &n);
  c = GetNth(head, n);
  if(c != 0) printf("value at index %d is %d\n", n,c);
  else printf("Error. Try again!!\n");
  print(head);
  return 0;
}
