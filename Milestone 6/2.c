#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

/** Tokenize a given string based on given character **/
char **str_split(char *str, char c)
{
  assert(str != NULL);
  char **tokens = NULL;
  int count = 0;
  while(*str){
    while(*str == c)
      ++str;
    if(!*str)
      break;
    tokens = realloc(tokens, (count+1) * sizeof(*tokens));
      tokens[count++] = str;
    while(*str && *str != c)
      ++str;
    if(*str)
      *str++ = 0;
  }
  tokens = realloc(tokens, (count+1) * sizeof(*tokens));
  tokens[count] = NULL;
  return tokens;
}

int main()
{
  char a[100], c;
  char **token;
  printf("Enter the string : ");
  scanf("%99[^\n]", a);
  printf("Enter the delimiter : ");
  scanf(" %c", &c);
  char **tokens = str_split(a, c);
  for(token = tokens; *token != NULL; ++token)
    printf("'%s'\n", *token);
  free(tokens);
  return 0;
}
