/*
	FAETERJ-Rio
	FPR - Manh� e Noite 
	Data: 22/04/2023 (aula extra)
	
	Lista de Exerc�cios VII (Arquivos)
	
	Quest�o 01:
	Desenvolver uma fun��o que, dado um arquivo texto, verifique o n�mero de caracteres 
	no mesmo.
*/

//importa��o de bibliotecas
#include <stdio.h>

//prot�tipos das fun��es
int quantidadeCaracteres (char nomeArquivo[]);

//main
void main ()
{
	//declara��o de vari�veis
	int quant;
	char nome[30];
	
	//obtendo o nome do arquivo
	printf ("Entre com o nome do arquivo: ");
	fflush (stdin);
	gets (nome);
	
	//chamando a fun��o
	quant = quantidadeCaracteres (nome);
	
	//testando o retorno da fun��o
	switch (quant)
	{
		case -1: printf ("\nErro na abertura do arquivo!");
		         break;
		         
		case 0:  printf ("\nArquivo vazio!");
		         break;
		         
		default: printf ("\nO arquivo %s contem %d caracteres.", nome, quant);
	}	
}

int quantidadeCaracteres (char nomeArquivo[])
{
	//declara��o de vari�veis
	FILE *arq;		//passo 1: declarar a vari�vel FILE*
	char caracter;
	int cont = 0;
	
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
		while (fscanf (arq, "%c", &caracter) != EOF)  //EOF - End Of File
		{
			cont++;
		}
		
		//passo 5: fechar o arquivo
		fclose (arq);
		
		return cont;
	}
}
