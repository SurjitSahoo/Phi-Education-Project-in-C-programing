#ifndef _LINK_SAMPLE_STRING_H
#define _LINK_SAMPLE_STRING_H

/* Returns the length of the string or -1 on error*/
int str_length(char *str);

/* Copies str2 to str1, returns 0 on success and -1 on error */
int str_copy(char *str1, char *str2);

/* 
if str1 is less than str2, returns -1
if str1 is greater than str2, retuns 1
if both are equal then returns 0
*/
int str_compare(char *str1, char *str2);

/* Returns position of the character in the string or -1 on error */
int str_find_char(char *str, char *ch);

/*returns position of substring str2 in str1 or -1 on error*/
int str_find_substring(char *str1, char *str2);

/* Copies given string and returns the address of the given string */
/* for the new string memory is allocated in the heap */
char *strcopy(char *str);


/* Tokenize a given string based on the given delimeter */
char **str_split(char *str, char c);

/* Copies n bytes from src to dst */
void *mem_copy(void *dest, const void *src, unsigned int n);

#endif
