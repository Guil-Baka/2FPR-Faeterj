/*
  FAETERJ-Rio
  FPR - Fundamentos de Programa��o - Noite
  Professor Leonardo Vianna

  Prova a compor a AV1 - 08/05/2023

  Quest�o 02 [2,5 pontos]:
  Dadas duas strings s1 e s2, implementar uma fun��o que verifique se todos os caracteres de s1 est�o em s2.
  Dependendo do resultado, os seguintes valores dever�o ser retornados:

    0:	nem todos os caracteres de s1 est�o em s2;
    1:	todos os caracteres de s1 est�o em s2, por�m n�o na mesma frequ�ncia;
    2:	todos os caracteres de s1 est�o em s2, na mesma frequ�ncia.
*/

// importa��o de bibliotecas
#include <stdio.h>
#include <string.h>

// prot�tipos das fun��es
//  ??????

int verificarStrings(char stringS1[], char stringS2[]);
// void printarString(char string1[], char string2[]);

// main
void main()
{
  // declara��o de vari�veis
  char string1[20], string2[20];
  int retorno;

  // obtendo as duas strings
  printf("Primeira string: ");
  fflush(stdin);
  gets(string1);

  printf("\n\n\nSegunda string: ");
  fflush(stdin);
  gets(string2);

  // chamando a fun��o e armazenando o retorno na vari�vel 'retorno'
  //  ?????

  retorno = verificarStrings(string1, string2);

  //print string para referencia no terminal
  // printarString(string1, string2); (não é necessário já está no switch do Professor)

  // testando o retorno
  switch (retorno)
  {
  case 0:
    printf("\nNem todos os caracteres de %s estao em %s.\n", string1, string2);
    break;

  case 1:
    printf("\nTodos os caracteres de %s estao em %s, porem nao na mesma frequencia.\n", string1, string2);
    break;

  case 2:
    printf("\nTodos os caracteres de %s estao em %s e na mesma frequencia.\n", string1, string2);
    break;
  }
}

// implementa��o das fun��es
// ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ?

//  função para verificar strings baseado no switch da main
int verificarStrings(char stringS1[],char stringS2[])
{
  // declaração de variáveis
  int retorno;
  //verifica se as strings são identicas
  if (strcmp(stringS1, stringS2) == 0)
  {
    return 2;
  }
  
  //verifica se os caracteres de stringS1 se repetem na mesma quantidade em stringS2 
    for (int i = 0; i < strlen(stringS1); i++)
    {
      int contador = 0;
      for (int j = 0; j < strlen(stringS2); j++)
      {
        if (stringS1[i] == stringS2[j])
        {
          contador++;
        }
      }
      if (contador == 0)
      {
        retorno = 0;
      }
      else if (contador != 0 && retorno != 0)
      {
        retorno = 1;
      }
    }
    return retorno;
}
  


// printar duas strings
// void printarStrings(char string1[], char string2[])
// {
//   printf("\n\n\nPrimeira string: %s", string1);
//   printf("\nSegunda string: %s", string2);
// }

