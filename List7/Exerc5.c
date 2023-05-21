/*
	FAETERJ-Rio
	FPR - Manhã e Noite 
	Data: 22/04/2023 (aula extra)
	
	Lista de Exercícios VII (Arquivos)
	
	Questão 05:
	Faça uma função que, dado um arquivo A contendo números reais, um por linha, crie 
	um novo arquivo B contendo os mesmos elementos de A, porém ordenados decrescentemente 
	e sem repetição.
*/

//importação de bibliotecas
#include <stdio.h>
#include <float.h>

//protótipos das funções
int criarArquivoOrdenado (char nomeArquivoA[], char nomeArquivoB[]);

int buscarMaiorElemento (char nomeArq[], float limite, float *maior);

//main
void main ()
{
	//declaração de variáveis
	char nomeArqA[30], nomeArqB[30];
	
	//obtendo os nomes dos arquivos
	printf ("Entre com o nome do arquivo original: ");
	fflush (stdin);
	gets (nomeArqA);
	
	printf ("Entre com o nome do novo arquivo: ");
	fflush (stdin);
	gets (nomeArqB);
	
	//chamando a função
	if (criarArquivoOrdenado (nomeArqA, nomeArqB) == 1)
	{
		printf ("\n\nO arquivo %s foi gerado com sucesso!", nomeArqB);
	}
	else
	{
		printf ("\n\nErro na abertura dos arquivos!");
	}	
}

//implementação das funções
int criarArquivoOrdenado (char nomeArquivoA[], char nomeArquivoB[])
{
	//declaração de variáveis
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
		//chamando a função que buscará o maior elemento do arquivo; porém, este valor
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
	//declaração de variáveis
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
			if ((numero < limite) && (numero > ma))  //verificando se o número lido é o maior de todos
			{
				//atualizando o maior
				ma = numero;
				
				//atualizando a variável 'achou'
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
