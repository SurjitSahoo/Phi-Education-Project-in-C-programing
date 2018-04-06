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
Takes two lists and combines them to make one list such that
the new list have alternating nodes of the sorurce lists.
*/
struct node* ShuffleMerge(struct node* a, struct node* b)
{
  struct node temp;
  struct node* tail = &temp;
  temp.next = NULL;
  while (1){
    if(a==NULL){
      tail->next = b;
      break;
    }
    else if(b==NULL){
      tail->next = a;
      break;
    }
    else{
      MoveNode(&(tail->next), &a);
      tail = tail->next;
      MoveNode(&(tail->next), &b);
      tail = tail->next;
    }
  }
  return(temp.next);
}

int main()
{
  struct node *A = NULL;
  struct node *B = NULL;
  struct node *MergedList = NULL;
  A = insert(A, 5);
  A = insert(A, 8);
  A = insert(A, 6);
  A = insert(A, 1);
  B = insert(B, 5);
  B = insert(B, 4);
  B = insert(B, 3);
  B = insert(B, 2);
  printf("Before merge the lists are \n");
  printf("A : ");
  print(A);
  printf("B : ");
  print(B);
  MergedList = ShuffleMerge(A, B);
  printf("After merge the list is : ");
  print(MergedList);
  return 0;
}
