#include <stdio.h>
#include <stdlib.h>
#include "linkedlst.h"
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
