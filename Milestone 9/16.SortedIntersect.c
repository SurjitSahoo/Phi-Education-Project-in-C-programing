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
    while (current->next != NULL &&
           current->next->data < newnode->data){
      current = current->next;
    }
    newnode->next = current->next;
    current->next = newnode;
  }
}

/* Adds the new node to the begining of the list */
void push(struct node** head_ref, int new_data)
{
  struct node* new_node = (struct node*) malloc(sizeof(struct node));
  new_node->data = new_data;
  new_node->next = (*head_ref);
  (*head_ref)    = new_node;
}

struct node *newNode(int data)
{
  struct node* newnode = (struct node*) malloc(sizeof(struct node));
  newnode->data = data;
  newnode->next = NULL;
  return newnode;
}

/* Prints the list */
void print(struct node *head)
{
  while(head != NULL){
    printf("%d  ", head->data);
    head = head->next;
  }
  printf("\n");
}

/***********************************************************************/
/* Given two sorted lists, retrns a new list 
representing the intersection of the two lists */
struct node* SortedIntersect(struct node* a, struct node* b)
{
  struct node dummy;
  struct node *tail = &dummy;
  dummy.next = NULL;
  while(a!=NULL && b!=NULL){
    if(a->data == b->data){
      push((&tail->next), a->data);
      tail = tail->next;
      a = a->next;
      b = b->next;
    }
    else if(a->data < b->data) a = a->next;
    else b = b->next;
  }
  return(dummy.next);
}
/*************************************************************************/

int main()
{
  struct node *A = NULL;
  struct node *B = NULL;
  struct node *intersectList = NULL;
  struct node *new_node = newNode(8);
  sortedInsert(&A, new_node);
  new_node = newNode(3);
  sortedInsert(&A, new_node);
  new_node = newNode(12);
  sortedInsert(&A, new_node);
  new_node = newNode(9);
  sortedInsert(&A, new_node);
  new_node = newNode(1);
  sortedInsert(&A, new_node);
  new_node = newNode(7);
  sortedInsert(&B, new_node);
  new_node = newNode(3);
  sortedInsert(&B, new_node);
  new_node = newNode(6);
  sortedInsert(&B, new_node);
  new_node = newNode(9);
  sortedInsert(&B, new_node);
  new_node = newNode(1);
  sortedInsert(&B, new_node);
  printf("The source lists are\n");
  printf("A : ");
  print(A);
  printf("B : ");
  print(B);
  intersectList = SortedIntersect(A, B);
  printf("Intersection List is : ");
  print(intersectList);
  return 0;
}
