/*
  FAETERJ-Rio
  FPR - Fundamentos de Programa��o - Noite
  Professor Leonardo Vianna

  Prova a compor a AV1 - 08/05/2023

  Quest�o 01 [2,5 pontos]:
  Dada uma matriz MLxC, onde L e C s�o constantes, desenvolver uma fun��o que "troque" os elementos de
  duas colunas c1 e c2, respeitadas as seguintes regras:

    a. A troca s� ser� poss�vel se as colunas c1 e c2 existirem na matriz. Caso existam, a troca ser�
      realizada e o valor 1 retornado pela fun��o; por outro lado, 0 ser� retornado se uma ou as duas
      colunas forem inv�lidas;
    b. Ap�s a troca, a coluna c2 conter� exatamente os elementos originais da coluna c1, na mesma ordem.
      Por�m, os valores da coluna c1 ser�o os originais da c2, na ordem inversa.

  Exemplo:

  Trocar as colunas 1 e 3 da matriz abaixo:

          1	3	5	7	9
          4	6	5	8	0
          3	4	5	7	8
          5	9	1	2	3
          7	1	5	3	5
          4	0	2	1	5


          1	1	5	3	9
          4	3	5	6	0
          3	2	5	4	8
          5	7	1	9	3
          7	8	5	1	5
          4	7	2	0	5
*/

// importa��o de bibliotecas
#include <stdio.h>

// defini��o de constantes
#define L 6
#define C 5

// prot�tipos das fun��es
// ? ? ? ? ? ?

  void exibirMatriz(int M[L][C]);
  int trocarColunasInvertendoSegundaColuna(int M[L][C], int c1, int c2);
// main
void main()
{
  // declara��o de vari�veis
  int resp,coluna1,coluna2,
      matriz[L][C] = {
          {1, 3, 5, 7, 9},
          {4, 6, 5, 8, 0},
          {3, 4, 5, 7, 8},
          {5, 9, 1, 2, 3},
          {7, 1, 5, 3, 5},
          {4, 0, 2, 1, 5}};

  // exibindo a matriz antes da chamada � fun��o
  exibirMatriz(matriz);

  printf("Essa eh a matriz original.\n\n");
  printf("Agora, vamos trocar as colunas.\n\n");
  printf("Informe o numero da primeira coluna: ");
  scanf("%d", &coluna1);
  printf("Informe o numero da segunda coluna: ");
  scanf("%d", &coluna2);


  // chamando a fun��o e atribuindo o retorno � vari�vel 'resp'
  resp = trocarColunasInvertendoSegundaColuna(matriz, coluna1, coluna2);

  
  // testando o valor retornado
  if (resp == 1)
  {
    printf("\n\nMatriz apos a troca:\n\n");

    exibirMatriz(matriz);
  }
  else
  {
    printf("\n\nA troca nao foi realizada!");
  }
}

// implementa��o das fun��es
// ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ?

int trocarColunasInvertendoSegundaColuna(int M[L][C], int c1, int c2)
{
  // declara��o de vari�veis
  int i, aux;

  // testando se as colunas s�o v�lidas
  if (c1 < 0 || c1 >= C || c2 < 0 || c2 >= C)
  {
    return 0;
  }

  // trocando os elementos das colunas
  for (i = 0; i < L; i++)
  {
    aux = M[i][c1];
    M[i][c1] = M[i][c2];
    M[i][c2] = aux;
  }

  // invertendo a ordem dos elementos da coluna c1
  for (i = 0; i < L / 2; i++)
  {
    aux = M[i][c1];
    M[i][c1] = M[L - 1 - i][c1];
    M[L - 1 - i][c1] = aux;
  }
  return 1;
}

void exibirMatriz(int M[L][C])
{
  // declara��o de vari�veis
  int i, j;

  printf("Elementos da matriz:\n\n");

  for (i = 0; i < L; i++)
  {
    for (j = 0; j < C; j++)
    {
      printf("%3d ", M[i][j]);
    }

    printf("\n");
  }

  printf("\n\n");
}
