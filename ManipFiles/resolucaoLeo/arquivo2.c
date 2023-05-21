/*
	FAETERJ-Rio
	FPR - Noite
	Data: 17/04/2023
	
	Arquivos
	
	Exemplo 2: adicionar os n�meros de 1 a 100 ao arquivo "teste.txt"
*/

//importa��o de bibliotecas
#include <stdio.h>

//main
void main ()
{
	//declara��o de vari�veis
	int i;
	FILE *arquivo;		//passo 1: declarar a vari�vel FILE*
	
	//passo 2: "abrir" o arquivo
	arquivo = fopen ("teste.txt", "a");
	
	//passo 3: verificar se houve erro na abertura do arquivo
	//if (arquivo == NULL)
	if (!arquivo)
	{
		printf ("\nErro na abertura do arquivo!");
	}
	else
	{
		//exibindo os n�meros de 1 a 100
		for (i=1;i<=100;i++)
		{
			fprintf (arquivo, "%d\n", i);  //passo 4: manipular o arquivo
		}
		
		//passo 5: fechar o arquivo
		fclose (arquivo);
		
		printf ("Arquivo gerado com sucesso!");
	}
}
