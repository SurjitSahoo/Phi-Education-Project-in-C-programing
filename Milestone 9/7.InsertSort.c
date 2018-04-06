#include <stdio.h>
#include <stdlib.h>
struct node{
  int data;
  struct node* next;
};

void sortedInsert(struct node **headref, struct node *newnode)
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

/*Given a list, change it to be in sorted order (using SortedInsert())*/
void InsertSort(struct node** headRef)
{
  struct node* result = NULL;
  struct node* current = *headRef;
  struct node* next;
  while (current!=NULL){
    next = current->next;
    sortedInsert(&result, current);
    current = next;
  }
  *headRef = result;
}

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

int main()
{
  struct node *head = NULL;
  head = insert(head, 3);
  head = insert(head, 10);
  head = insert(head, 7);
  head = insert(head, 12);
  head = insert(head, 8);
  head = insert(head, 8);
  printf("Before InsertSort\n");
  print(head);
  InsertSort(&head);
  printf("After InsertSort\n");
  print(head);
  return 0;
}
