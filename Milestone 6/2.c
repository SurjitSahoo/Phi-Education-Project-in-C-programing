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
    // skip the delimiter if it's present at the beginning of the string
    while(*str == c)
      ++str;
    //check if the string exists after skiping the delimiter
    if(!*str)
      break;
    /*
      Here we're creating array of pointers
      realloc() creates a location of 4 bytes to store address and assigns the pointer to tokens
      now tokens points to the newly created location, which will store address of string(token)
    */
    tokens = realloc(tokens, (count+1) * sizeof(*tokens));
    /*
      str is a pointer it holds address of the beginning of the string
      note down that address where the token string begins
    */
    tokens[count++] = str;
    //find the position of the delimiter
    while(*str && *str != c)
      ++str;
    /*
      replace the delimiter with NULL
      NULL terminated series of characters is a string
      now one token is created
    */
    if(*str)
      *str++ = 0;
  }
  /*
    when all the tokens are created
    assign NULL to the end of the array, so that we'll know array of tokens end here
  */
  tokens = realloc(tokens, (count+1) * sizeof(*tokens)); //create last address location for token
  tokens[count] = NULL; //points to NULL i.e. end of the tokens array.
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
