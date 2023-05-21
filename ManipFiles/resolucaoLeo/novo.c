/*
	FAETERJ-Rio
	FPR - Noite
	Data: 17/04/2023
	
	Arquivos
	
	Exemplo 6: copiando o conte�do de um arquivo para outro
*/

//importa��o de bibliotecas
#include <stdio.h>

//prot�tipos das fun��es
int copiandoArquivo (char nomeArqOrigem[], char nomeArqDestino[]);

//main
void main ()
{
	//chamando a fun��o
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
	//declara��o de vari�veis
	FILE *arqO, *arqD;		//passo 1: declarar a vari�vel FILE*
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
