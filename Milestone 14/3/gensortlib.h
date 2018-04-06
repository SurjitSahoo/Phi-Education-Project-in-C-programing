#ifndef _LINK_GENERIC_SORT_H
#define _LINK_GENERIC_SORT_H

/* Copies n bytes from src to dst */
void *mem_copy(void *dest, const void *src, unsigned int n);

/*
 A function to sort array of any data type
 Arguments -
 1st arg : array to be sorted 
 2nd arg : pointer to compare function
 3rd arg : size of single element in the array
 4th arg : number of total elements 
*/
void* Sort(void* arr, int (*compareFcn)(void*, void*), int sizeOfElement, int numElements);

#endif