/*
                             *******************
******************************* C HEADER FILE *******************************
**                           *******************                           **
**                                                                         **
** project    : Text to tweet converter                                    **
** filename   : linkedlst.h                                                **
** version    : 1                                                          **
** date       : June 02, 2017                                              **
**                                                                         **
*****************************************************************************
VERSION HISTORY:
----------------
Version       : 1
Date          : June 02, 2017
Revised by    : Surjit Kumar Sahoo
Description   : Original version.
*/
#ifndef _LINK_LINKED_LIST_H
#define _LINK_LINKED_LIST_H

/****************************************************************************/
/**                                                                        **/
/**                          MODULES USED                                  **/
/**                                                                        **/
/****************************************************************************/
#include "dictionary.h"

/****************************************************************************/
/**                                                                        **/
/**                         EXPORTED FUNCTIONS                             **/
/**                                                                        **/
/****************************************************************************/
int count(struct node* head, int n);
/****************************************************************************/
/*
* Counts the number of times a given integer occurs in the list
*/

/****************************************************************************/
int GetNth(struct node* head, int index);
/****************************************************************************/
/*
* Returns the data value stored at given index
*/

/****************************************************************************/
void DeleteList(struct node** headRef);
/****************************************************************************/
/*
* Deletes the whole list deallocating all of it's memory and resets
  the head to NULL
*/

/****************************************************************************/
int pop(struct node **headRef);
/****************************************************************************/
/*
* Deletes the head node and returns the data value of that node
* Sets the head pointer to point to the second node
*/

/****************************************************************************/
void insertNth(struct node** headRef, int index, int Data);
/****************************************************************************/
/*
* Inserts a node at given index
*/

 /****************************************************************************/
void sortedInsert(struct node** headref, struct node* newnode);
/****************************************************************************/
/*
* Given a sorted list in increasing order, inserts new node to the corect
  sorted position
*/

/****************************************************************************/
void print(struct node *head);
/****************************************************************************/
/*
* Prints the list
*/

/****************************************************************************/
void push(struct node** head_ref, int new_data);
/****************************************************************************/
/*
* Adds the new node to the begining of the list
*/

/****************************************************************************/
void InsertSort(struct node** headRef);
/****************************************************************************/
/*
*  Given a list, change it to be in sorted order (using SortedInsert())
*/

/****************************************************************************/
void Append(struct node** aRef, struct node** bRef);
/****************************************************************************/
/*
*  Takes two lists and appends second list to the end of the first list
*/

/****************************************************************************/
void FrontBackSplit(struct node* source, struct node** frontRef, struct node** backRef);
/****************************************************************************/
/*
* Splits the list into two halfs.
* If the number of nodes are odd then the extra node goes to the first list.
*/

 /****************************************************************************/
void RemoveDuplicates(struct node* head);
/****************************************************************************/
/*
* Takes a sorted list in increasing order and removes duplicate nodes
 */

 /****************************************************************************/
void MoveNode(struct node** destRef, struct node** sourceRef);
/****************************************************************************/
/*
* Takes two lists and moves the 1st node of the 2nd list to the head
  of the 1st list
*/

/****************************************************************************/
void AlternatingSplit(struct node* source, struct node** aRef, struct node** bRef);
/****************************************************************************/
/*
* Divides a list into two smaller lists, such that the smaller lists
  have the alternating nodes of the source list.
*/

/****************************************************************************/
struct node* ShuffleMerge(struct node* a, struct node* b);
/****************************************************************************/
/*
* Takes two lists and combines them to make one list such that
  the new list have alternating nodes of the sorurce lists.
*/

/****************************************************************************/
struct node *SortedMerge(struct node *a, struct node *b);
/****************************************************************************/
/*
* Takes two soreted lists and merges them to create new sorted list
*/

/****************************************************************************/
void MergeSort(struct node** headRef);
/****************************************************************************/
/*
* Splits the list into two halfs and sorts them using FrontBackSplit() and
  SortedMerge() and finaly merges the two lists to get the list sorted
*/

/****************************************************************************/
struct node* SortedIntersect(struct node* a, struct node* b);
/****************************************************************************/
/*
* Given two sorted lists, retrns a new list representing the intersection
  of the two lists
*/

/****************************************************************************/
void Reverse(struct node** headRef);
/****************************************************************************/
/*
* Reverse a linked list
*/

/****************************************************************************/
int countNode(struct node* head);
/****************************************************************************/
/*
* Counts number of nodes in the list 
*/
#endif
