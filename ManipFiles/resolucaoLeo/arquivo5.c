/*
	FAETERJ-Rio
	FPR - Noite
	Data: 17/04/2023
	
	Arquivos
	
	Exemplo 5: lendo o conte�do de um arquivo e exibindo-o na tela.
*/

//importa��o de bibliotecas
#include <stdio.h>

//prot�tipos das fun��es
int leituraArquivo (char nomeArq[]);

//main
void main ()
{
	//chamando a fun��o
	if (leituraArquivo ("arquivo5.c") == 0)
	{
		printf ("\nErro na abertura do arquivo!");
	}
	else
	{
		printf ("\n\nSucesso na manipulacao do arquivo!");
	}
}

int leituraArquivo (char nomeArq[])
{
	//declara��o de vari�veis
	FILE *arquivo;		//passo 1: declarar a vari�vel FILE*
	char caracter;
	
	//passo 2: "abrir" o arquivo
	arquivo = fopen (nomeArq, "r");
	
	//passo 3: verificar se houve erro na abertura do arquivo
	//if (arquivo == NULL)
	if (!arquivo)
	{
		return 0;
	}
	else
	{
		//passo 4: lendo valores enquanto existirem dados no arquivo
		while (fscanf (arquivo, "%c", &caracter) != EOF)  //EOF - End Of File
		{
			printf ("%c", caracter);
		}
		
		//passo 5: fechar o arquivo
		fclose (arquivo);
		
		return 1;
	}
}
