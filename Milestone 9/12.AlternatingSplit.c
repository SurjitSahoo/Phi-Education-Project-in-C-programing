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

void MoveNode(struct node** destRef, struct node** sourceRef)
{
  struct node* newNode = *sourceRef;
  if(newNode == NULL) return;
  *sourceRef = newNode->next;
  newNode->next = *destRef;
  *destRef = newNode;
}

/*
Divides a list into two smaller lists, such that the smaller lists
have the alternating nodes of the source list.
*/
void AlternatingSplit(struct node* source, struct node** aRef, struct node** bRef)
{
  struct node* a = NULL;
  struct node* b = NULL;
  struct node* current = source;
  while(current != NULL){
    MoveNode(&a, &current);
    if(current != NULL) MoveNode(&b, &current);
  }
  *aRef = a;
  *bRef = b;
}

int main()
{
  struct node *source = NULL;
  struct node *A = NULL;
  struct node *B = NULL;
  source = insert(source, 3);
  source = insert(source, 4);
  source = insert(source, 7);
  source = insert(source, 9);
  source = insert(source, 8);
  source = insert(source, 8);
  printf("Parent list is : ");
  print(source);
  AlternatingSplit(source, &A, &B);
  printf("\nSublists are\n");
  printf("A : ");
  print(A);
  printf("B : ");
  print(B);
  return 0;
}
