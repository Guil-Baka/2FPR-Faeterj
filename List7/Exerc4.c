/*
	FAETERJ-Rio
	FPR - Manhã e Noite 
	Data: 22/04/2023 (aula extra)
	
	Lista de Exercícios VII (Arquivos)
	
	Questão 04:
	Desenvolver uma função que, dado um arquivo texto contendo números, determine 
	se estes encontram-se ordenados crescentemente.
*/

//importação de bibliotecas
#include <stdio.h>
#include <limits.h>

//protótipos das funções
int verificaOrdenacao (char nomeArquivo[]);

//main
void main ()
{
	//declaração de variáveis
	int resposta;
	char nome[30];
	
	//obtendo o nome do arquivo
	printf ("Entre com o nome do arquivo: ");
	fflush (stdin);
	gets (nome);

	//chamando a função
	resposta = verificaOrdenacao (nome);
	
	//testando o retorno da função
	switch (resposta)
	{
		case -1: printf ("\nErro na abertura do arquivo!");
		         break;
		         
		case 0:  printf ("\nO arquivo %s nao esta ordenado!", nome);
		         break;
		         
		case 1:  printf ("\nO arquivo %s esta ordenado!", nome);
	}	
}

int verificaOrdenacao (char nomeArquivo[])
{
	//declaração de variáveis
	FILE *arq;		//passo 1: declarar a variável FILE*
	int numero, anterior = INT_MIN;
	
	//passo 2: "abrir" o arquivo
	arq = fopen (nomeArquivo, "r");
		
	//passo 3: verificar se houve erro na abertura do arquivo
	//if (arq == NULL)
	if (!arq)
	{
		return -1;  //-1 sinalizando erro na abertura do arquivo
	}
	else
	{
		//passo 4: lendo valores enquanto existirem dados no arquivo
		while (fscanf (arq, "%d", &numero) != EOF)  //EOF - End Of File
		{			
			//verificando se o valor lido é menor do que o anterior
			if (numero < anterior)
			{
				//fechando o arquivo
				fclose (arq);
				
				return 0;
			}
			else
			{
				//atualizando o 'anterior'
				anterior = numero;
			}			
		}
		
		//passo 5: fechar o arquivo
		fclose (arq);
		
		return 1;  //arquivo está ordenado crescentemente
	}
}
