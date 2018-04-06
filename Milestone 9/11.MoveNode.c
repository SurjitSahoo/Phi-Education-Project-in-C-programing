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

/* Takes two lists and moves the 1st node of the 2nd list
 to the head of the 1st list */
void MoveNode(struct node** destRef, struct node** sourceRef)
{
  struct node* newNode = *sourceRef;
  if(newNode == NULL) return;
  *sourceRef = newNode->next;
  newNode->next = *destRef;
  *destRef = newNode;
}

int main()
{
  struct node *A = NULL;
  struct node *B = NULL;
  A = insert(A, 3);
  A = insert(A, 4);
  A = insert(A, 7);
  B = insert(B, 9);
  B = insert(B, 8);
  B = insert(B, 8);
  printf("Before Move : \n");
  printf("List 'A' is : ");
  print(A);
  printf("List 'B' is : ");
  print(B);
  MoveNode(&A, &B);
  printf("\nAfter move\n");
  printf("List 'A' is : ");
  print(A);
  printf("List 'B' is : ");
  print(B);
  return 0;
}
