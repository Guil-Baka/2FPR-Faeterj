#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void main(){

  char test[]="A B C D E F G H I J K L ";
  char test2[]="M N O P Q R S T U V W X Y Z";
  char test3[]="A B C D E F G H I J K L ";
  char test4[]="M N O P Q R S T U V W X Y Z";

  concat(test, test2);

  printf("\n%s\n", test);

  concat2(test3, test4);

  printf("\n%s", test3);
}

void concat(char str1[], char str2[]) {

  int i = 0, j = 0;

  while (str1[i] != '\0') {
    i++;
  }

  while (str2[j] != '\0') {
    str1[i] = str2[j];
    i++;
    j++;
  }

  str1[i] = '\0';

}

// void concat2(char destino[], char origem[]){

//   int tam = strlen(origem),i;
//   for ( i = 0; destino[i]; i++)
//   {
//     origem[tam+i] = destino[i];  
//   }
//   origem[tam+1] = '\0';
// }