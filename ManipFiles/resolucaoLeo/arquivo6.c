/*
	FAETERJ-Rio
	FPR - Noite
	Data: 17/04/2023
	
	Arquivos
	
	Exemplo 6: copiando o conteúdo de um arquivo para outro
*/

//importação de bibliotecas
#include <stdio.h>

//protótipos das funções
int copiandoArquivo (char nomeArqOrigem[], char nomeArqDestino[]);

//main
void main ()
{
	//chamando a função
	if (copiandoArquivo ("arquivo6.c", "novo.c") == 0)
	{
		printf ("\nErro na abertura do arquivo!");
	}
	else
	{
		printf ("\n\nSucesso na manipulacao do arquivo!");
	}
}

int copiandoArquivo (char nomeArqOrigem[], char nomeArqDestino[])
{
	//declaração de variáveis
	FILE *arqO, *arqD;		//passo 1: declarar a variável FILE*
	char caracter;
	
	//passo 2: "abrir" o arquivo
	arqO = fopen (nomeArqOrigem, "r");
	arqD = fopen (nomeArqDestino, "w");
	
	//passo 3: verificar se houve erro na abertura do arquivo
	//if ((arqO == NULL) || (arqD == NULL))
	if ((!arqO) || (!arqD))
	{
		return 0;
	}
	else
	{
		//passo 4: lendo valores enquanto existirem dados no arquivo
		while (fscanf (arqO, "%c", &caracter) != EOF)  //EOF - End Of File
		{
			fprintf (arqD, "%c", caracter);
		}
		
		//passo 5: fechar o arquivo
		fclose (arqO);
		fclose (arqD);
		
		return 1;
	}
}
