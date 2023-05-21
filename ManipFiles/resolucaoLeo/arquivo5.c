/*
	FAETERJ-Rio
	FPR - Noite
	Data: 17/04/2023
	
	Arquivos
	
	Exemplo 5: lendo o conteúdo de um arquivo e exibindo-o na tela.
*/

//importação de bibliotecas
#include <stdio.h>

//protótipos das funções
int leituraArquivo (char nomeArq[]);

//main
void main ()
{
	//chamando a função
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
	//declaração de variáveis
	FILE *arquivo;		//passo 1: declarar a variável FILE*
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
