/*
	FAETERJ-Rio
	FPR - Manhã e Noite (aula extra)
	Data: 06/05/2023
	
	Lista de Exercícios VIII (Structs)
	
	Questão 02:
	Considere um vetor que, em cada posição, armazene os seguintes dados de um curso 
	de graduação: nome (por exemplo, Medicina, Engenharia, Direito, ...), 
	área (Humanas, Exatas, ...), cidade na qual funciona e a quantidade de alunos 
	matriculados no curso.
	
	Desenvolver uma função que, dado um vetor nesses moldes, um código inteiro cod e 
	uma string str, retorne a quantidade de alunos associados aos parâmetros.
	
	Se o código for igual a 1, str representará um curso  e, portanto, a função deverá 
	retornar a quantidade de alunos matriculados no curso str, destacando que o mesmo 
	curso pode encontrar-se em mais de uma posição do vetor (em cidades diferentes, 
	por exemplo). Por outro lado, se o código for 2, str representará uma área e, 
	portanto, deverá ser retornado o total de alunos matriculados em cursos daquela área.
*/

//importação de bibliotecas
#include <stdio.h>

//definição de tipos
typedef struct {
	char nome[20];
	char area[10];
	char cidade[20];
	int quantAlunos;
} TCurso;

//protótipos das funções
void preencherVetorCursos (TCurso vetCursos[], int tamanho);
int quantidadeAlunos (TCurso vetCursos[], int tamanho, int codigo, char str[]);

//main
void main ()
{
	//declaração de variáveis
	TCurso cursos[5];
	int resp;
	
	//preenchendo o vetor
	preencherVetorCursos (cursos, 5);
	
	//chamada 1 à função
	resp = quantidadeAlunos (cursos, 5, 1, "SISTEMAS");	
	printf ("%d alunos atenderam aos filtros da pesquisa 1\n\n", resp);
	
	//chamada 2 à função
	resp = quantidadeAlunos (cursos, 5, 2, "EXATAS");	
	printf ("%d alunos atenderam aos filtros da pesquisa 2\n\n", resp);
}

//implementação das funções
void preencherVetorCursos (TCurso vetCursos[], int tamanho)
{
	//declaração de variáveis
	int i;
	
	//varrendo o vetor
	for (i=0;i<tamanho;i++)
	{
		//lendo as informações de cada pessoa
		printf ("Curso: ");
		fflush (stdin);
		gets (vetCursos[i].nome);
		
		printf ("Area: ");
		fflush (stdin);
		gets (vetCursos[i].area);
		
		printf ("Cidade: ");
		fflush (stdin);
		gets (vetCursos[i].cidade);
		
		printf ("Quantidade de alunos: ");
		scanf ("%d", &vetCursos[i].quantAlunos);
		
		printf ("\n\n");
	}
}

int quantidadeAlunos (TCurso vetCursos[], int tamanho, int codigo, char str[])
{
	//declaração de variáveis
	int i, quant = 0;
	
	//testando o valor do código
	if (codigo == 1) //filtro: nome do curso
	{
		//percorrendo o vetor
		for (i=0;i<tamanho;i++)
		{
			//verificando se o curso da posição 'i' é aquele especificado no parâmetro 'str'
			if (strcmp (str, vetCursos[i].nome) == 0)
			{
				quant += vetCursos[i].quantAlunos;
			}
		}
	}
	else	//entende que o código é igual a 2
	{
		//percorrendo o vetor
		for (i=0;i<tamanho;i++)
		{
			//verificando se a área da posição 'i' é aquela especificada no parâmetro 'str'
			if (strcmp (str, vetCursos[i].area) == 0)
			{
				quant += vetCursos[i].quantAlunos;
			}
		}
	}
	
	//retornando a quantiade calculada
	return quant;
}
