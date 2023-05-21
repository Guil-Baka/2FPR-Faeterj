/*
	FAETERJ-Rio
	FPR - Manh� e Noite (aula extra)
	Data: 06/05/2023
	
	Lista de Exerc�cios VIII (Structs)
	
	Quest�o 03:
	Um grupo de pessoas foi entrevistado e cada uma informou o seu nome e o nome de 
	sua m�e. Estes dados foram armazenados em um vetor do qual cada posi��o consiste 
	em um struct.
	
	Desenvolver uma fun��o que receba um vetor como o descrito acima e retorne outro 
	contendo, para cada m�e, o n�mero de filhos entrevistados (portanto, um outro vetor 
	de structs).

	Nota: considerar que n�o existem duas ou mais m�es com o mesmo nome.
*/

//importa��o de bibliotecas
#include <stdio.h>
#include <string.h>

//defini��o de tipos
typedef struct {
	char nome[20];
	char nomeMae[20];
} TPessoa;

typedef struct {
	char nome[20];
	int quantFilhos;
} TMae;


//prot�tipos das fun��es
void preencherVetorEntrevistados (TPessoa vetEntrevistados[], int quantEntrevistados);
void exibirMaes (TMae vetMaes[], int quantMaes);
int buscarMae (TMae vetMaes[], int quantMaes, char nomeMae[]);

void preencherVetorMaes (TPessoa vetEntrevistados[], int quantEntrevistados, TMae vetMaes[], int *quantMaes);

//main
void main ()
{
	//declara��o de vari�veis
	TPessoa entrevistados[5];
	TMae maes[5];
	int numMaes;
	
	//preenchendo o vetor de entrevistados
	preencherVetorEntrevistados (entrevistados, 5);
	
	//chamada � fun��o
	preencherVetorMaes (entrevistados, 5, maes, &numMaes);
	
	//exibindo o vetor de m�es
	exibirMaes (maes, numMaes);
}

//implementa��o das fun��es
void preencherVetorEntrevistados (TPessoa vetEntrevistados[], int quantEntrevistados)
{
	//declara��o de vari�veis
	int i;
	
	//varrendo o vetor
	for (i=0;i<quantEntrevistados;i++)
	{
		//lendo as informa��es de cada pessoa entrevistada
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
	//declara��o de vari�veis
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
	//declara��o de vari�veis
	int i, pos, cont = 0;
	
	//varrendo o vetor de entrevistados
	for (i=0;i<quantEntrevistados;i++)	
	{
		//verificando se a m�e da posi��o 'i' n�o encontra-se no novo vetor
		pos = buscarMae (vetMaes, cont, vetEntrevistados[i].nomeMae);
		
		//se 'pos' for igual a -1 => a m�e ainda n�o est� no novo vetor
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
	
	//atualizando a quantidade de m�es, retornada por refer�ncia
	*quantMaes = cont;
}

int buscarMae (TMae vetMaes[], int quantMaes, char nomeMae[])
{
	//declara��o de vari�veis
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
	
	//se 'nomeMae' n�o for encontrado...
	return -1;
}
