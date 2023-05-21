/*
	FAETERJ-Rio
	FPR - Noite
	Data: 17/04/2023
	
	Arquivos
	
	Exemplo 3: adicionar os n�meros de 1 a 100 ao arquivo "teste.txt",
	com uso de fun��o.
*/

//importa��o de bibliotecas
#include <stdio.h>

//prot�tipos das fun��es
int escrevendoNoArquivo (char nomeArq[], char modo[], int limite);

//main
void main ()
{
	//chamando a fun��o
	if (escrevendoNoArquivo ("numeros1.txt", "w", 500) == 0)
	{
		printf ("\nErro na abertura do arquivo!");
	}
	else
	{
		printf ("\nSucesso na manipulacao do arquivo!");
	}

	//chamando a fun��o
	if (escrevendoNoArquivo ("numeros1.txt", "a", 200) == 0)
	{
		printf ("\nErro na abertura do arquivo!");
	}
	else
	{
		printf ("\nSucesso na manipulacao do arquivo!");
	}
}

int escrevendoNoArquivo (char nomeArq[], char modo[], int limite)
{
	//declara��o de vari�veis
	int i;
	FILE *arquivo;		//passo 1: declarar a vari�vel FILE*
	
	//passo 2: "abrir" o arquivo
	arquivo = fopen (nomeArq, modo);
	
	//passo 3: verificar se houve erro na abertura do arquivo
	//if (arquivo == NULL)
	if (!arquivo)
	{
		return 0;
	}
	else
	{
		//escrevendo no arquivo os n�meros de 1 a 'limite'
		for (i=1;i<=limite;i++)
		{
			fprintf (arquivo, "%d\n", i);  //passo 4: manipular o arquivo
		}
		
		//passo 5: fechar o arquivo
		fclose (arquivo);
		
		return 1;
	}
}
