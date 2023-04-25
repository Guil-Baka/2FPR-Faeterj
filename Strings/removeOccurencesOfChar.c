#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int removeChars(char str[], char charToRemove) {
  
  int i,j, cont=0;

  for (i=0; str[i] != '\0'; i++) {
    if (str[i] == charToRemove) {
      for (j=i; str[j] != '\0'; j++) {
        str[j] = str[j+1];
      }
    }
    else {
      i++;
    }
  }
  return 1;
}


void main() {

  char str[] = "A B C D E F G H I J K L ";
  char charToRemove = 'C';

  printf("\n%s", str);

  removeChars(str, charToRemove);

  printf("\n%s", str);
}

