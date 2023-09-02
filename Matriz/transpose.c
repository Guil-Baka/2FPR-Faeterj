#include <stdio.h>

// define linhas e colunas
#define LIN 5
#define COL 8

// protótipos das funções
void exibirMatriz(int matriz[LIN][COL], int lin, int col);
void transporMatriz(int matriz[LIN][COL]);

int main(void)
{
  // matriz de 5x8
  int matriz[LIN][COL] = {{0, 1, 2, 3, 4, 5, 6, 7},
                          {10, 11, 12, 13, 14, 15, 16, 17},
                          {20, 21, 22, 23, 24, 25, 26, 27},
                          {30, 31, 32, 33, 34, 35, 36, 37},
                          {40, 41, 42, 43, 44, 45, 46, 47}};

  // exibe a matriz
  printf("Matriz original:\n");
  exibirMatriz(matriz, LIN, COL);
  // transpõe a matriz
  transporMatriz(matriz);

  // exibe a matriz transposta
  printf("\nMatriz transposta:\n");
  exibirMatriz(matriz, COL, LIN);
  return 0;
}

// exibir a matriz independente do tamanho
void exibirMatriz(int matriz[LIN][COL], int lin, int col)
{
  int i, j;

  for (i = 0; i < lin; i++)
  {
    for (j = 0; j < col; j++)
    {
      printf("%3d ", matriz[i][j]);
    }
    printf("\n");
  }
}

// transfere as linhas para as colunas
void transporMatriz(int matriz[LIN][COL])
{
  int i, j, aux;

  for (i = 0; i < LIN; i++)
  {
    for (j = i + 1; j < COL; j++)
    {
      aux = matriz[i][j];
      matriz[i][j] = matriz[j][i];
      matriz[j][i] = aux;
    }
  }
}
