#include <stdio.h>
#include <stdlib.h>

void main() {

  char test[]="A B C D E F G H I J K L M N O P Q R S T U V W X Y Z";
  char test2[2];

  printf("\n%s", test);
  
  cpy(test2, test);

  printf("\n%s", test2);
}

void cpy(char copied[], char main[]) {

  int i = 0;

  while (main[i] != '\0') {
    copied[i] = main[i];
    i++;
  }

  copied[i] = '\0';

}