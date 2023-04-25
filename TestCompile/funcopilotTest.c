#include <stdio.h>
#include <stdlib.h>
#include <string.h> 

// QUESTÃO 06:
// Considere uma loja que mantém em uma
// matriz o total vendido por cada funcionário
// pelos diversos meses do ano. Ou seja, uma
// matriz de 12 linhas (uma por mês) e 10 colunas
// (10 funcionários). Pede-se o desenvolvimento
// de uma função para cada item abaixo:

// a. Calcular o total vendido durante o ano;
// b. Dado um mês fornecido pelo usuário,
// determinar o total vendido nesse mês;
// c. Dado um funcionário fornecido pelo
// usuário, determinar o total vendido por ele
// durante o ano;
// d. Determinar o mês com maior índice de
// vendas;
// e. Determinar o funcionário que menos
// vendeu durante o ano.

void main()
{
    int matriz[12][10];
    int i, j;
    int totalVendasAno = 0;
    int totalVendasMes = 0;
    int totalVendasFuncionario = 0;
    int mes = 0;
    int funcionario = 0;
    int maiorVendaMes = 0;
    int menorVendaFuncionario = 0;

    // Preenchendo a matriz com valores aleatórios
    for (i = 0; i < 12; i++)
    {
        for (j = 0; j < 10; j++)
        {
            matriz[i][j] = rand() % 100;
        }
    }

    // Imprimindo a matriz
    for (i = 0; i < 12; i++)
    {
        for (j = 0; j < 10; j++)
        {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }

    // a. Calcular o total vendido durante o ano;
    totalVendasAno = calculateTotalSalesYear(matriz);
    printf("Total vendido durante o ano: %dq", totalVendasAno);

}

int calculateTotalSalesYear()
{
    int i, j;
    int totalVendasAno = 0;

    for (i = 0; i < 12; i++)
    {
        for (j = 0; j < 10; j++)
        {
            totalVendasAno += matriz[i][j];
        }
    }

    return totalVendasAno;
}
