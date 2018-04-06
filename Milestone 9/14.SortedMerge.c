#include <stdio.h>
#include <stdlib.h>
struct node{
  int data;
  struct node* next;
};

void sortedInsert(struct node** headref, struct node* newnode)
{
  struct node* current;
  if(*headref == NULL || (*headref)->data >= newnode->data){
    newnode->next = *headref;
    *headref = newnode;
  }
  else{
    current = *headref;
    while(current->next != NULL &&
          current->next->data < newnode->data){
      current = current->next;
    }
    newnode->next = current->next;
    current->next = newnode;
  }
}

struct node *newNode(int data)
{
  struct node* newnode = (struct node*) malloc(sizeof(struct node));
  newnode->data = data;
  newnode->next = NULL;
  return newnode;
}

void print(struct node *head)
{
  while(head != NULL){
    printf("%d  ", head->data);
    head = head->next;
  }
  printf("\n");
}

void MoveNode(struct node **destRef, struct node **sourceRef)
{
  struct node *newNode = *sourceRef;
  if(newNode == NULL) return;
  *sourceRef = newNode->next;
  newNode->next = *destRef;
  *destRef = newNode;
}

/* Takes two soreted lists and merges them to create new sorted list */
struct node *SortedMerge(struct node *a, struct node *b)
{
  struct node dummy;
  struct node *tail = &dummy;
  dummy.next = NULL;
  while(1){
    if(a == NULL){
      tail->next = b;
      break;
    }
    else if(b == NULL){
      tail->next = a;
      break;
    }
    if(a->data <= b->data)
      MoveNode(&(tail->next), &a);
    else MoveNode(&(tail->next), &b);
    tail = tail->next;
  }
  return(dummy.next);
}

int main()
{
  struct node *A = NULL;
  struct node *B = NULL;
  struct node *MergedList = NULL;
  struct node *new_node = newNode(8);
  sortedInsert(&A, new_node);
  new_node = newNode(3);
  sortedInsert(&A, new_node);
  new_node = newNode(12);
  sortedInsert(&A, new_node);
  new_node = newNode(9);
  sortedInsert(&A, new_node);
  new_node = newNode(3);
  sortedInsert(&A, new_node);
  new_node = newNode(7);
  sortedInsert(&A, new_node);
  new_node = newNode(11);
  sortedInsert(&B, new_node);
  new_node = newNode(6);
  sortedInsert(&B, new_node);
  new_node = newNode(2);
  sortedInsert(&B, new_node);
  new_node = newNode(8);
  sortedInsert(&B, new_node);
  new_node = newNode(5);
  sortedInsert(&B, new_node);
  printf("List A is : ");
  print(A);
  printf("List B is : ");
  print(B);
  MergedList = SortedMerge(A, B);
  printf("The merged list is : ");
  print(MergedList);
  return 0;
}
