/*
                             *******************
******************************* C HEADER FILE *******************************
**                           *******************                           **
**                                                                         **
** project    : Text to tweet converter                                    **
** filename   : stringlib.h                                                **
** version    : 1                                                          **
** date       : June 02, 2017                                              **
**                                                                         **
*****************************************************************************
VERSION HISTORY:
----------------
Version      : 1
Date         : June 02, 2017
Revised by   : Surjit Kumar Sahoo
Description  : Original version.
*/

#ifndef _LINK_SAMPLE_STRING_H
#define _LINK_SAMPLE_STRING_H

/****************************************************************************/
/**                                                                        **/
/**                         EXPORTED FUNCTIONS                             **/
/**                                                                        **/
/****************************************************************************/
int str_length(char *str);
/****************************************************************************/
/*
* Returns the length of the string or -1 on error
*/

/****************************************************************************/
int str_copy(char *str1, char *str2);
/****************************************************************************/
/*
* Copies str2 to str1, returns 0 on success and -1 on error
*/

/****************************************************************************/
int str_compare(char *str1, char *str2);
/****************************************************************************/
/*
* Compares two strings
* If str1 is less than str2, returns -1
* If str1 is greater than str2, retuns 1
* If both are equal then returns 0
*/

/****************************************************************************/
int str_find_char(char *str, char *ch);
/****************************************************************************/
/*
* Returns position of the character in the string or -1 on error
*/

/****************************************************************************/
int str_find_substring(char *str1, char *str2);
/****************************************************************************/
/*
* returns position of substring str2 in str1 or -1 on error
*/

/****************************************************************************/
char *strcopy(char *str);
/****************************************************************************/
/*
* Copies given string and returns the address of the given string for
  the new string memory is allocated in the heap
*/

/****************************************************************************/
char **str_split(char *str, char c);
/****************************************************************************/
/*
* Tokenize a given string based on the given delimeter
*/

/****************************************************************************/
void *mem_copy(void *dest, const void *src, unsigned int n);
/****************************************************************************/
/*
* Copies n bytes from src to dst 
*/
#endif
