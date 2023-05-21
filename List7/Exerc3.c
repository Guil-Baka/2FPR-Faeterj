/*
	FAETERJ-Rio
	FPR - Manh� e Noite 
	Data: 22/04/2023 (aula extra)
	
	Lista de Exerc�cios VII (Arquivos)
	
	Quest�o 03:
	Desenvolver uma fun��o que, dado um arquivo texto, verifique o n�mero de letras 
	existentes no mesmo (entendendo que no arquivo podem existir letras, algarismos 
	e s�mbolos).
*/

//importa��o de bibliotecas
#include <stdio.h>

//prot�tipos das fun��es
int quantidadeLetras (char nomeArquivo[]);

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
	quant = quantidadeLetras (nome);
	
	//testando o retorno da fun��o
	switch (quant)
	{
		case -1: printf ("\nErro na abertura do arquivo!");
		         break;
		         
		case 0:  printf ("\nNao existem letras no arquivo %s!", nome);
		         break;
		         
		default: printf ("\nForam encontradas %d letras no arquivo %s.", quant, nome);
	}	
}

int quantidadeLetras (char nomeArquivo[])
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
			//colocando o caracter lido em mai�sculo
			caracter = toupper (caracter);
			
			//verificando se o caracter lido � uma letra
			if ((caracter >= 'A') && (caracter <= 'Z'))
			{
				cont++;
			}
		}
		
		//passo 5: fechar o arquivo
		fclose (arq);
		
		return cont;
	}
}
