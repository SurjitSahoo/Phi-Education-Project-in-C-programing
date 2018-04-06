#include <stdio.h>
int main()
{
  FILE *fpointer;
  char ch = '\n';
  fpointer = fopen("test.txt", "r");
  while((ch == '\n') && (ch != EOF)){
    printf("Word : ");
    while(EOF != (ch = fgetc(fpointer)) && (ch != ':')){
      printf("%c", ch);
    }
    printf("\n");
    /* I could have the word and meaning as two strings.. character by character.
       But I'm printing them right on to the screen. */
    printf("Meaning : ");
    while(EOF != (ch = fgetc(fpointer)) && (ch != '\n')){
      printf("%c", ch);
    }
    printf("\n");
  }
  fclose(fpointer);
}
