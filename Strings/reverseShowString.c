#include <stdio.h>
#include <stdlib.h>

void main(){
  char str[] = "A B C D E F G H I J K L ";
  reverseString(str);
}


void reverseString(char str[]){
  int i = 0;

  while (str[i] != '\0')
  {
    i++;
  }

  i--;

  while (i >= 0)
  {
    printf("%c",str[i]);
    i--;
  }
}