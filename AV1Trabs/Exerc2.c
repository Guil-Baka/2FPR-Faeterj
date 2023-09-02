#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Protótipos das funções
void exibirString(char str[]);
void substituirString(char str1[], char str2[], int A, int B);

int main()
{
  //Declaração de variáveis
  char str1[] = "e ai, vc vem?    ";
  char str2[] = "voce";
  
  //Exibir as strings
  printf("String 1: ");
  exibirString(str1);

  printf("String 2: ");
  exibirString(str2);

  //Chamada da função para substituir os elementos entre as posições A e B da string 1 pela string 2
  substituirString(str1, str2, 6, 7);

  //Exibir a string 1
  printf("String 1: ");
  exibirString(str1);


  return 0;
}

//Função para exibir a string
void exibirString(char str[])
{
  int i=0;

  while (str[i] != '\0')
  {
    printf("%c", str[i]);
    i++;
  }
  printf("|||");
  printf("\n");
}

//Função para adicionar a string 2 entre as posições A e B da string 1 preservando o restante da string 1
void substituirString(char str1[], char str2[], int A, int B)
{
  //Declaração de variáveis
  int i=0, j=0, k=0, tamStr1=0, tamStr2=0, tamStr3=0;
  char str3[100];

  //Determinar o tamanho da string 1
  tamStr1 = strlen(str1);

  //Determinar o tamanho da string 2
  tamStr2 = strlen(str2);

  //Copiar elementos de str1 apos a pos B para str3
  for (i = B+1; i < tamStr1; i++)
  {
    str3[k] = str1[i];
    k++;
  }

  //Copiar elementos de str2 para str1 da pos A até A+strlen(str2)
  for (i = A; i < A+tamStr2; i++)
  {
    str1[i] = str2[j];
    j++;
  }
  
  //Copiar elemenos de str3 para str1 da pos A+strlen(str2) até o fim da string 1
  for (i = A+tamStr2; i < tamStr1; i++)
  {
    str1[i] = str3[tamStr3];
    tamStr3++;
  }
}

