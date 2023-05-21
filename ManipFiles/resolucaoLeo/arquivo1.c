/*
	FAETERJ-Rio
	FPR - Noite
	Data: 17/04/2023
	
	Arquivos
	
	Exemplo 1: escrever os números de 1 a 1000 no arquivo "teste.txt"
*/

//importação de bibliotecas
#include <stdio.h>

//main
void main ()
{
	//declaração de variáveis
	int i;
	FILE *arquivo;		//passo 1: declarar a variável FILE*
	
	//passo 2: "abrir" o arquivo
	arquivo = fopen ("teste.txt", "w");
	
	//passo 3: verificar se houve erro na abertura do arquivo
	//if (arquivo == NULL)
	if (!arquivo)
	{
		printf ("\nErro na abertura do arquivo!");
	}
	else
	{
		//exibindo os números de 1 a 1000
		for (i=1;i<=1000;i++)
		{
			fprintf (arquivo, "%d\n", i);  //passo 4: manipular o arquivo
		}
		
		//passo 5: fechar o arquivo
		fclose (arquivo);
		
		printf ("Arquivo gerado com sucesso!");
	}
}
