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

int count(struct node* head)
{
  int c = 0;
  while(head != NULL){
    c += 1;
    head = head->next;
  }
  return c;
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

/* Splits the list into two halfs. If the number of nodes are odd
then the extra node goes to the first list */
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

/* 
 Splits the list into two halfs and sorts them using 
 FrontBackSplit() and SortedMerge() and finaly merges the
 two lists to get the list sorted 
 */
void MergeSort(struct node** headRef)
{
  struct node* head = *headRef;
  struct node* a;
  struct node* b;
  if((head == NULL) || (head->next == NULL)) return;
  FrontBackSplit(head, &a, &b);
  MergeSort(&a);
  MergeSort(&b);
  *headRef = SortedMerge(a, b);
}

int main()
{
  struct node *head = NULL;
  head = insert(head, 3);
  head = insert(head, 2);
  head = insert(head, 7);
  head = insert(head, 5);
  head = insert(head, 9);
  head = insert(head, 8);
  head = insert(head, 10);
  printf("The source list is : ");
  print(head);
  MergeSort(&head);
  printf("The sorted list is : ");
  print(head);
  return 0;
}