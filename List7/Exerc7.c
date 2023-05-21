/*
	FAETERJ-Rio
	FPR - Manh� e Noite 
	Data: 24/04/2023
	
	Lista de Exerc�cios VII (Arquivos)
	
	Quest�o 07:
	Desenvolver uma fun��o que, dados dois 
	arquivos textos arqA e arqB, crie um novo 
	arquivo arqC, considerando que:

	- arqA e arqB cont�m n�meros reais, um por 
	linha, ordenados crescentemente e sem 
	repeti��o no arquivo; 
	- arqC deve conter apenas os n�meros comuns 
	aos dois arquivos originais;
	- Assim como arqA e arqB, arqC tamb�m n�o 
	possuir� repeti��es de elementos e estes 
	dever�o estar ordenados de forma crescente.
*/

//importa��o de bibliotecas
#include <stdio.h>
#include <float.h>

//prot�tipos das fun��es
int interseccao (char nomeArqA[], char nomeArqB[], char nomeArqC[]);

//main
void main ()
{
	//declara��o de vari�veis
	char nomeA[30], nomeB[30], nomeC[30];
	int resposta;
	
	//obtendo os nomes dos arquivos
	printf ("Entre com o nome do primeiro arquivo: ");
	fflush (stdin);
	gets (nomeA);
	
	printf ("Entre com o nome do segundo arquivo: ");
	fflush (stdin);
	gets (nomeB);

	printf ("Entre com o nome do arquivo que contera a interseccao: ");
	fflush (stdin);
	gets (nomeC);
	
	//chamando a fun��o
	resposta = interseccao (nomeA, nomeB, nomeC);
	
	if (resposta == 1)
	{
		printf ("\n\nO arquivo %s foi gerado com sucesso!", nomeC);
	}
	else
	{
		printf ("\n\nErro na abertura dos arquivos!");
	}	
}

//implementa��o das fun��es
int interseccao (char nomeArqA[], char nomeArqB[], char nomeArqC[])
{
	//declara��o de vari�veis
	FILE *arqA, *arqB, *arqC;
	float numeroA, numeroB;
	int fimA = 0, fimB = 0;
	
	//abrindo os arquivos
	arqA = fopen (nomeArqA, "r");
	arqB = fopen (nomeArqB, "r");
	arqC = fopen (nomeArqC, "w");
	
	//verificando se algum arquivo apresentou erro na abertura
	//if ((arqA == NULL) || (arqB == NULL) || (arqC == NULL))
	if ((!arqA) || (!arqB) || (!arqC))
	{
		return 0;
	}
	else
	{
		//lendo o primeiro elemento do arquivo A
		fscanf (arqA, "%f", &numeroA);
		
		//lendo o primeiro elemento do arquivo B
		fscanf (arqB, "%f", &numeroB);
		
		while ((fimA == 0) && (fimB == 0))
		{
			//comparar os elementos
			if (numeroA < numeroB)
			{
				//lendo o pr�ximo valor do arquivo A
				if (fscanf (arqA, "%f", &numeroA) == EOF)
				{
					fimA = 1;
				}
			}
			else
			{
				if (numeroA > numeroB)
				{		
					//lendo o pr�ximo valor do arquivo B
					if (fscanf (arqB, "%f", &numeroB) == EOF)
					{
						fimB = 1;
					}
				}
				else
				{
					//numeroA = numeroB
					
					//escreve em C qualquer um dos elementos
					fprintf (arqC, "%.1f\n", numeroA);
					//OU    fprintf (arqC, "%.1f\n", numeroB);

					//lendo o pr�ximo valor dos dois arquivos
					if (fscanf (arqA, "%f", &numeroA) == EOF)
					{
						fimA = 1;
					}
					
					if (fscanf (arqB, "%f", &numeroB) == EOF)
					{
						fimB = 1;
					}
				}
			}
		}
		
		//fechando os arquivos
		fclose (arqA);
		fclose (arqB);
		fclose (arqC);
		
		return 1;
	}
}
