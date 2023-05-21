/*
	FAETERJ-Rio
	FPR - Manhã e Noite 
	Data: 24/04/2023
	
	Lista de Exercícios VII (Arquivos)
	
	Questão 07:
	Desenvolver uma função que, dados dois 
	arquivos textos arqA e arqB, crie um novo 
	arquivo arqC, considerando que:

	- arqA e arqB contém números reais, um por 
	linha, ordenados crescentemente e sem 
	repetição no arquivo; 
	- arqC deve conter apenas os números comuns 
	aos dois arquivos originais;
	- Assim como arqA e arqB, arqC também não 
	possuirá repetições de elementos e estes 
	deverão estar ordenados de forma crescente.
*/

//importação de bibliotecas
#include <stdio.h>
#include <float.h>

//protótipos das funções
int interseccao (char nomeArqA[], char nomeArqB[], char nomeArqC[]);

//main
void main ()
{
	//declaração de variáveis
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
	
	//chamando a função
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

//implementação das funções
int interseccao (char nomeArqA[], char nomeArqB[], char nomeArqC[])
{
	//declaração de variáveis
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
				//lendo o próximo valor do arquivo A
				if (fscanf (arqA, "%f", &numeroA) == EOF)
				{
					fimA = 1;
				}
			}
			else
			{
				if (numeroA > numeroB)
				{		
					//lendo o próximo valor do arquivo B
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

					//lendo o próximo valor dos dois arquivos
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
