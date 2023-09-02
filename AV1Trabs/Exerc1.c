#include <stdio.h>
#include <stdlib.h>

//Definir constantes para o valor de linha e coluna
#define linhas 5
#define colunas 6

//Protótipos das funções
void lerMatriz(int matriz[linhas][colunas]);
int empurrarColuna(int matriz[linhas][colunas], int coluna);

//Função principal
int main()
{
  // Declaração de variáveis
  int matriz[linhas][colunas] = {
          {1,  5,  7,  1,  4,  6},
          {6,  2,  1,  4,  7,  7},
          {3,  6,  9,  7,  0,  1},
          {2,  4,  5,  7,  2,  4},
          {2,  4,  8,  9,  1,  2}};
  //       C0  C1  C2  C3  C4  C5

  int colInicial=1;

  //Chamada da função para imprimir a matriz
  lerMatriz(matriz);

  //Chamada da função para empurrar a coluna
  empurrarColuna(matriz, colInicial);

  //Chamada da função para imprimir a matriz
  lerMatriz(matriz);

  return 0;
}

//função para imprimir a matriz
void lerMatriz(int matriz[linhas][colunas])
{
  int i, j=0;

  for (i = 0; i < linhas; i++)
  {
    printf("\n");
    printf("Linha %d: ", i);
    for (j = 0; j < colunas; j++)
    {
      printf("%d ", matriz[i][j]);
    }
    printf("\n");
  }
  printf("\n");
  printf("Fim da matriz");
  printf("\n");
}

//Empurra coluna X para fim da matriz
int empurrarColuna(int matriz[linhas][colunas], int coluna)
{
  //Declaração de variáveis
  int i, j=0;
  int aux=0;

  if (coluna<0)
  {
    return 0;
  }else{
  
  //for para percorrer as linhas
  for (i = 0; i < linhas; i++)
  {
    aux = matriz[i][coluna];
    //for para percorrer as colunas
    for (j = coluna; j < colunas; j++)
    {
      matriz[i][j] = matriz[i][j+1];
    }
    matriz[i][colunas-1] = aux;
  }
  return 1;
  }
}