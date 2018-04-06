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

int count(struct node* head)
{
  int c = 0;
  while(head != NULL){
    c+=1;
    head = head->next;
  }
  return c;
}

/*
Splits the list into two halfs. If the number of nodes are odd
then the extra node goes to the first list.
*/
void FrontBackSplit(struct node* source, struct node** frontRef, struct node** backRef)
{
  int len = count(source);
  int i;
  struct node* current = source;
  if(len < 2){
    *frontRef = source;
    *backRef = NULL;
  }
  else{
    int hopCount = (len-1)/2;
    for(i = 0; i<hopCount; i++){
      current = current->next;
    }
    *frontRef = source;
    *backRef = current->next;
    current->next = NULL;
  }
}

int main()
{
  struct node *head = NULL;
  struct node *front, *back;
  head = insert(head, 3);
  head = insert(head, 4);
  head = insert(head, 7);
  head = insert(head, 9);
  head = insert(head, 8);
  head = insert(head, 8);
  head = insert(head, 10);
  printf("Before splitting the list is \n");
  print(head);
  FrontBackSplit(head, &front, &back);
  printf("After splitting\n");
  printf("Front list is \n");
  print(front);
  printf("Back list is \n");
  print(back);
  return 0;
}
