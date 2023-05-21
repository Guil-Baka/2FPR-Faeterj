/*
	FAETERJ-Rio
	FPR - Manhã e Noite 
	Data: 22/04/2023 (aula extra)
	
	Lista de Exercícios VII (Arquivos)
	
	Questão 02:
	Desenvolver uma função que, dado um arquivo texto, verifique o número de vezes 
	que um determinado caracter aparece no arquivo.
*/

//importação de bibliotecas
#include <stdio.h>

//protótipos das funções
int numOcorrencias (char nomeArquivo[], char ch);

//main
void main ()
{
	//declaração de variáveis
	int quant;
	char nome[30];
	char caracter;
	
	//obtendo o nome do arquivo
	printf ("Entre com o nome do arquivo: ");
	fflush (stdin);
	gets (nome);
	
	//obtendo o caracter a ser buscado
	printf ("Entre com o caracter a ser buscado: ");
	fflush (stdin);
	scanf ("%c", &caracter);
	
	//chamando a função
	quant = numOcorrencias (nome, caracter);
	
	//testando o retorno da função
	switch (quant)
	{
		case -1: printf ("\nErro na abertura do arquivo!");
		         break;
		         
		case 0:  printf ("\nO caracter %c nao foi encontrado no arquivo %s!", caracter, nome);
		         break;
		         
		default: printf ("\nForam encontradas %d ocorrencias do caracter %c no arquivo %s.", quant, caracter, nome);
	}	
}

int numOcorrencias (char nomeArquivo[], char ch)
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
		//colocando 'ch' em maiúsculo
		ch = toupper(ch);
		
		//passo 4: lendo valores enquanto existirem dados no arquivo
		while (fscanf (arq, "%c", &caracter) != EOF)  //EOF - End Of File
		{
			//verificando se o caracter lido é aquele sendo buscado
			if (toupper(caracter) == ch)
			{
				cont++;
			}
		}
		
		//passo 5: fechar o arquivo
		fclose (arq);
		
		return cont;
	}
}
