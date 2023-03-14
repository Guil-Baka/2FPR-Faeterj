#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void main(){
  // tamanho de test vai assumir a quantidade de caracteres da string
  char test[] = "Hello World";      //String array de char Definido assim
  char test2[20];                   //String array de char Definido assim

  printf("\nThe string is: %s", test); //print string
  test[0] = 'h';                       //Altera o primeiro caractere da string
  printf("\nThe string now is: %s", test);
  
  printf("\n");                  //sizeof retorna a quantidade de char da string
  printf("%lu\n", sizeof(test)); //lu significa unsigned long
  printf("\n");                  //unsigned nunca pode ser negativo.

  printf("\n Digite uma string: ");
  //scanf("%s", test); scanf não lê espaços, apenas caracteres
  gets(test); //gets lê espaços
  printf("\nA string digitada foi: %s", test);
  printf("\n");

  test2 = strcpy(test); //copia a string test para test2
}
