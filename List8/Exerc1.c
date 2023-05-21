/*
	FAETERJ-Rio
	FPR - Manh� e Noite (aula extra)
	Data: 06/05/2023
	
	Lista de Exerc�cios VIII (Structs)
	
	Quest�o 01:
	Considere um vetor que armazene alguns dados coletados de um grupo de pessoas em 
	uma pesquisa, a saber: nome, g�nero, idade e altura.

	Desenvolver uma fun��o que receba os par�metros g�nero, faixa de idade (idade 
	inicial e idade final) e faixa de altura (altura inferior e altura superior) e 
	retorne a quantidade de pessoas que atendem aos filtros por ele representados.

	Nota: caso o g�nero especificado seja igual a M, ser�o considerados os homens que 
	estiverem nas faixas de idade e altura especificadas; o mesmo ocorrer� com as 
	mulheres, quando o g�nero for F. Por�m, se o g�nero contiver qualquer valor 
	diferente de M ou F, todas as pessoas que atenderem aos filtros de idade e altura 
	ser�o contabilizadas.
*/

//importa��o de bibliotecas
#include <stdio.h>

//defini��o de tipos
typedef struct {
	char nome[20];
	char genero;
	int idade;
	float altura;
} TPessoa;

//prot�tipos das fun��es
void preencherVetorPessoas (TPessoa vetPessoas[], int tamanho);
int buscarPessoas (TPessoa vetPessoas[], int tamanho, char genero, int idadeInferior, int idadeSuperior, float alturaInferior, float alturaSuperior);

//main
void main ()
{
	//declara��o de vari�veis
	TPessoa pessoas[5];
	int resp;
	
	//preenchendo o vetor
	preencherVetorPessoas (pessoas, 5);
	
	//chamada 1 � fun��o
	resp = buscarPessoas (pessoas, 5, 'F', 20, 30, 1.60, 1.75);	
	printf ("%d pessoas atenderam aos filtros da pesquisa 1\n\n", resp);
	
	//chamada 2 � fun��o
	resp = buscarPessoas (pessoas, 5, 'X', 25, 40, 1.70, 1.80);	
	printf ("%d pessoas atenderam aos filtros da pesquisa 2\n\n", resp);
}

//implementa��o das fun��es
void preencherVetorPessoas (TPessoa vetPessoas[], int tamanho)
{
	//declara��o de vari�veis
	int i;
	
	//varrendo o vetor
	for (i=0;i<tamanho;i++)
	{
		//lendo as informa��es de cada pessoa
		printf ("Genero: ");
		fflush (stdin);
		scanf ("%c", &vetPessoas[i].genero);
		
		printf ("Idade: ");
		scanf ("%d", &vetPessoas[i].idade);
		
		printf ("Altura: ");
		scanf ("%f", &vetPessoas[i].altura);
	}
}

int buscarPessoas (TPessoa vetPessoas[], int tamanho, char genero, int idadeInferior, int idadeSuperior, float alturaInferior, float alturaSuperior)
{
	//declara��o de vari�veis
	int i, cont = 0;
	
	//convertendo genero para mai�sculo
	genero = toupper (genero);
	
	//percorrendo o vetor
	for (i=0;i<tamanho;i++)
	{
		//verificando se o g�nero � M ou F
		if ((genero == 'M') || (genero == 'F'))
		{
			//aplicando os filtros (g�nero, faixa de idade e faixa de altura)
			if ((vetPessoas[i].genero == genero) &&
			    ((vetPessoas[i].idade >= idadeInferior) && (vetPessoas[i].idade <= idadeSuperior)) &&
			    ((vetPessoas[i].altura >= alturaInferior) && (vetPessoas[i].altura <= alturaSuperior)))
			{
				cont++;
			}
		}
		else
		{
			//aplicando os filtros (faixa de idade e faixa de altura)
			if (((vetPessoas[i].idade >= idadeInferior) && (vetPessoas[i].idade <= idadeSuperior)) &&
			    ((vetPessoas[i].altura >= alturaInferior) && (vetPessoas[i].altura <= alturaSuperior)))
			{
				cont++;
			}
		}
	}
	
	//retornando a quantidade de pessoas que atenderam aos filtros
	return cont;
}
