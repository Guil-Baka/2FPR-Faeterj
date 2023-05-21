/*
	FAETERJ-Rio
	FPR - Manhã e Noite 
	Data: 22/04/2023 (aula extra)
	
	Lista de Exercícios VII (Arquivos)
	
	Questão 01:
	Desenvolver uma função que, dado um arquivo texto, verifique o número de caracteres 
	no mesmo.
*/

//importação de bibliotecas
#include <stdio.h>

//protótipos das funções
int quantidadeCaracteres (char nomeArquivo[]);

//main
void main ()
{
	//declaração de variáveis
	int quant;
	char nome[30];
	
	//obtendo o nome do arquivo
	printf ("Entre com o nome do arquivo: ");
	fflush (stdin);
	gets (nome);
	
	//chamando a função
	quant = quantidadeCaracteres (nome);
	
	//testando o retorno da função
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
	//declaração de variáveis
	FILE *arq;		//passo 1: declarar a variável FILE*
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
