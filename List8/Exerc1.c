/*
	FAETERJ-Rio
	FPR - Manhã e Noite (aula extra)
	Data: 06/05/2023
	
	Lista de Exercícios VIII (Structs)
	
	Questão 01:
	Considere um vetor que armazene alguns dados coletados de um grupo de pessoas em 
	uma pesquisa, a saber: nome, gênero, idade e altura.

	Desenvolver uma função que receba os parâmetros gênero, faixa de idade (idade 
	inicial e idade final) e faixa de altura (altura inferior e altura superior) e 
	retorne a quantidade de pessoas que atendem aos filtros por ele representados.

	Nota: caso o gênero especificado seja igual a M, serão considerados os homens que 
	estiverem nas faixas de idade e altura especificadas; o mesmo ocorrerá com as 
	mulheres, quando o gênero for F. Porém, se o gênero contiver qualquer valor 
	diferente de M ou F, todas as pessoas que atenderem aos filtros de idade e altura 
	serão contabilizadas.
*/

//importação de bibliotecas
#include <stdio.h>

//definição de tipos
typedef struct {
	char nome[20];
	char genero;
	int idade;
	float altura;
} TPessoa;

//protótipos das funções
void preencherVetorPessoas (TPessoa vetPessoas[], int tamanho);
int buscarPessoas (TPessoa vetPessoas[], int tamanho, char genero, int idadeInferior, int idadeSuperior, float alturaInferior, float alturaSuperior);

//main
void main ()
{
	//declaração de variáveis
	TPessoa pessoas[5];
	int resp;
	
	//preenchendo o vetor
	preencherVetorPessoas (pessoas, 5);
	
	//chamada 1 à função
	resp = buscarPessoas (pessoas, 5, 'F', 20, 30, 1.60, 1.75);	
	printf ("%d pessoas atenderam aos filtros da pesquisa 1\n\n", resp);
	
	//chamada 2 à função
	resp = buscarPessoas (pessoas, 5, 'X', 25, 40, 1.70, 1.80);	
	printf ("%d pessoas atenderam aos filtros da pesquisa 2\n\n", resp);
}

//implementação das funções
void preencherVetorPessoas (TPessoa vetPessoas[], int tamanho)
{
	//declaração de variáveis
	int i;
	
	//varrendo o vetor
	for (i=0;i<tamanho;i++)
	{
		//lendo as informações de cada pessoa
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
	//declaração de variáveis
	int i, cont = 0;
	
	//convertendo genero para maiúsculo
	genero = toupper (genero);
	
	//percorrendo o vetor
	for (i=0;i<tamanho;i++)
	{
		//verificando se o gênero é M ou F
		if ((genero == 'M') || (genero == 'F'))
		{
			//aplicando os filtros (gênero, faixa de idade e faixa de altura)
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
