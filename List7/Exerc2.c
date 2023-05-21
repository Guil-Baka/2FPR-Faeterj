/*
	FAETERJ-Rio
	FPR - Manh� e Noite 
	Data: 22/04/2023 (aula extra)
	
	Lista de Exerc�cios VII (Arquivos)
	
	Quest�o 02:
	Desenvolver uma fun��o que, dado um arquivo texto, verifique o n�mero de vezes 
	que um determinado caracter aparece no arquivo.
*/

//importa��o de bibliotecas
#include <stdio.h>

//prot�tipos das fun��es
int numOcorrencias (char nomeArquivo[], char ch);

//main
void main ()
{
	//declara��o de vari�veis
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
	
	//chamando a fun��o
	quant = numOcorrencias (nome, caracter);
	
	//testando o retorno da fun��o
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
		//colocando 'ch' em mai�sculo
		ch = toupper(ch);
		
		//passo 4: lendo valores enquanto existirem dados no arquivo
		while (fscanf (arq, "%c", &caracter) != EOF)  //EOF - End Of File
		{
			//verificando se o caracter lido � aquele sendo buscado
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
