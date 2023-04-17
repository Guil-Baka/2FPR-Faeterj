#include <stdio.h>
#include <stdlib.h>

void main(){
  char str1[] = "A B C D E F G H I J K L ";

  func(str1);
}

void func (char s[]){

  printf("%s",s);
  char *p;

  p=s;

  while (*p != '\0')
  {
    (*p)++; // Pega o conteudo no valor de memoria e incrementa. Ou seja o valor ascii do caractere A subira 1 transformando-o em B.
    // printf("%c",*p);
    p++; // Incrementa a continuação do While.
  }
  printf("%s",s);
}