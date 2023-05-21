/*
	FAETERJ-Rio
	FPR - Manh� e Noite 
	Data: 22/04/2023 (aula extra)
	
	Lista de Exerc�cios VII (Arquivos)
	
	Quest�o 05:
	Fa�a uma fun��o que, dado um arquivo A contendo n�meros reais, um por linha, crie 
	um novo arquivo B contendo os mesmos elementos de A, por�m ordenados decrescentemente 
	e sem repeti��o.
*/

//importa��o de bibliotecas
#include <stdio.h>
#include <float.h>

//prot�tipos das fun��es
int criarArquivoOrdenado (char nomeArquivoA[], char nomeArquivoB[]);

int buscarMaiorElemento (char nomeArq[], float limite, float *maior);

//main
void main ()
{
	//declara��o de vari�veis
	char nomeArqA[30], nomeArqB[30];
	
	//obtendo os nomes dos arquivos
	printf ("Entre com o nome do arquivo original: ");
	fflush (stdin);
	gets (nomeArqA);
	
	printf ("Entre com o nome do novo arquivo: ");
	fflush (stdin);
	gets (nomeArqB);
	
	//chamando a fun��o
	if (criarArquivoOrdenado (nomeArqA, nomeArqB) == 1)
	{
		printf ("\n\nO arquivo %s foi gerado com sucesso!", nomeArqB);
	}
	else
	{
		printf ("\n\nErro na abertura dos arquivos!");
	}	
}

//implementa��o das fun��es
int criarArquivoOrdenado (char nomeArquivoA[], char nomeArquivoB[])
{
	//declara��o de vari�veis
	FILE *arqB;
	float limite = FLT_MAX,
	      valor;
	
	//abrindo o arquivo B
	arqB = fopen (nomeArquivoB, "w");
	
	//verificando se houve erro na abertura do arquivo
	if (!arqB)
	{
		return 0;
	}
	else
	{
		//chamando a fun��o que buscar� o maior elemento do arquivo; por�m, este valor
		//deve ser inferior a um limite
		while (buscarMaiorElemento (nomeArquivoA, limite, &valor) != 0)
		{
			//inserindo o valor retornado no novo arquivo
			fprintf (arqB, "%.2f\n", valor);
			
			//atualizando o valor de 'limite'
			limite = valor;
		}
		
		//fechando o arquivo
		fclose (arqB);
		
		//retornando sucesso
		return 1;
	}
}

int buscarMaiorElemento (char nomeArq[], float limite, float *maior)
{
	//declara��o de vari�veis
	FILE *arq;
	float numero, ma = FLT_MIN;
	int achou = 0;
	
	//abrindo o arquivo
	arq = fopen (nomeArq, "r");
	
	//testando se houve erro
	if (!arq)
	{
		return -1;
	}
	else
	{
		//lendo cada valor do arquivo
		while (fscanf (arq, "%f", &numero) != EOF)
		{
			if ((numero < limite) && (numero > ma))  //verificando se o n�mero lido � o maior de todos
			{
				//atualizando o maior
				ma = numero;
				
				//atualizando a vari�vel 'achou'
				achou = 1;
			}
		}
		
		if (achou == 1) //retornar o maior elemento encontrado
		{
			*maior = ma;
		}
		
		return achou;
	}
}
