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

/* Takes two lists and appends second list to the end of the first list */
void Append(struct node** aRef, struct node** bRef)
{
  struct node* current;
  if(*aRef == NULL) *aRef = *bRef;
  else{
    current = *aRef;
    while (current->next != NULL) current = current->next;
    current->next = *bRef;
  }
  *bRef=NULL;
}

int main()
{
  struct node *A = NULL;
  struct node *B = NULL;
  A = insert(A, 3);
  A = insert(A, 4);
  A = insert(A, 7);
  A = insert(A, 9);
  A = insert(A, 8);
  A = insert(A, 8);
  B = insert(B, 11);
  B = insert(B, 18);
  B = insert(B, 15);
  B = insert(B, 19);
  printf("The List 'A' is : ");
  print(A);
  printf("The List 'B' is : ");
  print(B);
  Append(&A, &B);
  printf("After appending the list is : ");
  print(A);
  return 0;
}