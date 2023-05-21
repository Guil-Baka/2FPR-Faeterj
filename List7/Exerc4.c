/*
	FAETERJ-Rio
	FPR - Manh� e Noite 
	Data: 22/04/2023 (aula extra)
	
	Lista de Exerc�cios VII (Arquivos)
	
	Quest�o 04:
	Desenvolver uma fun��o que, dado um arquivo texto contendo n�meros, determine 
	se estes encontram-se ordenados crescentemente.
*/

//importa��o de bibliotecas
#include <stdio.h>
#include <limits.h>

//prot�tipos das fun��es
int verificaOrdenacao (char nomeArquivo[]);

//main
void main ()
{
	//declara��o de vari�veis
	int resposta;
	char nome[30];
	
	//obtendo o nome do arquivo
	printf ("Entre com o nome do arquivo: ");
	fflush (stdin);
	gets (nome);

	//chamando a fun��o
	resposta = verificaOrdenacao (nome);
	
	//testando o retorno da fun��o
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
	//declara��o de vari�veis
	FILE *arq;		//passo 1: declarar a vari�vel FILE*
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
			//verificando se o valor lido � menor do que o anterior
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
		
		return 1;  //arquivo est� ordenado crescentemente
	}
}
