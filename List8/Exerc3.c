/*
	FAETERJ-Rio
	FPR - Manhã e Noite (aula extra)
	Data: 06/05/2023
	
	Lista de Exercícios VIII (Structs)
	
	Questão 03:
	Um grupo de pessoas foi entrevistado e cada uma informou o seu nome e o nome de 
	sua mãe. Estes dados foram armazenados em um vetor do qual cada posição consiste 
	em um struct.
	
	Desenvolver uma função que receba um vetor como o descrito acima e retorne outro 
	contendo, para cada mãe, o número de filhos entrevistados (portanto, um outro vetor 
	de structs).

	Nota: considerar que não existem duas ou mais mães com o mesmo nome.
*/

//importação de bibliotecas
#include <stdio.h>
#include <string.h>

//definição de tipos
typedef struct {
	char nome[20];
	char nomeMae[20];
} TPessoa;

typedef struct {
	char nome[20];
	int quantFilhos;
} TMae;


//protótipos das funções
void preencherVetorEntrevistados (TPessoa vetEntrevistados[], int quantEntrevistados);
void exibirMaes (TMae vetMaes[], int quantMaes);
int buscarMae (TMae vetMaes[], int quantMaes, char nomeMae[]);

void preencherVetorMaes (TPessoa vetEntrevistados[], int quantEntrevistados, TMae vetMaes[], int *quantMaes);

//main
void main ()
{
	//declaração de variáveis
	TPessoa entrevistados[5];
	TMae maes[5];
	int numMaes;
	
	//preenchendo o vetor de entrevistados
	preencherVetorEntrevistados (entrevistados, 5);
	
	//chamada à função
	preencherVetorMaes (entrevistados, 5, maes, &numMaes);
	
	//exibindo o vetor de mães
	exibirMaes (maes, numMaes);
}

//implementação das funções
void preencherVetorEntrevistados (TPessoa vetEntrevistados[], int quantEntrevistados)
{
	//declaração de variáveis
	int i;
	
	//varrendo o vetor
	for (i=0;i<quantEntrevistados;i++)
	{
		//lendo as informações de cada pessoa entrevistada
		printf ("Nome: ");
		fflush (stdin);
		gets (vetEntrevistados[i].nome);
		
		printf ("Nome da mae: ");
		fflush (stdin);
		gets (vetEntrevistados[i].nomeMae);
		
		printf ("\n\n");
	}
}
void exibirMaes (TMae vetMaes[], int quantMaes)
{
	//declaração de variáveis
	int i;
	
	//varrendo o vetor
	printf ("\n\n");
	
	for (i=0;i<quantMaes;i++)
	{
		printf ("Nome da mae: %s\n", vetMaes[i].nome);
		printf ("Numero de filhos: %d\n\n", vetMaes[i].quantFilhos);
	}	
}

void preencherVetorMaes (TPessoa vetEntrevistados[], int quantEntrevistados, TMae vetMaes[], int *quantMaes)
{
	//declaração de variáveis
	int i, pos, cont = 0;
	
	//varrendo o vetor de entrevistados
	for (i=0;i<quantEntrevistados;i++)	
	{
		//verificando se a mãe da posição 'i' não encontra-se no novo vetor
		pos = buscarMae (vetMaes, cont, vetEntrevistados[i].nomeMae);
		
		//se 'pos' for igual a -1 => a mãe ainda não está no novo vetor
		if (pos < 0)
		{
			strcpy (vetMaes[cont].nome, vetEntrevistados[i].nomeMae);
			vetMaes[cont].quantFilhos = 1;
			cont++;
		}
		else
		{
			vetMaes[pos].quantFilhos++;
		}
	}
	
	//atualizando a quantidade de mães, retornada por referência
	*quantMaes = cont;
}

int buscarMae (TMae vetMaes[], int quantMaes, char nomeMae[])
{
	//declaração de variáveis
	int i;
	
	//varrendo o vetor
	for (i=0;i<quantMaes;i++)
	{
		//verificando se 'nomeMae' foi encontrada no vetor
		if (strcmp (vetMaes[i].nome, nomeMae) == 0)
		{
			return i;
		}
	}
	
	//se 'nomeMae' não for encontrado...
	return -1;
}
