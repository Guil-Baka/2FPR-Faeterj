/*
	FAETERJ-Rio
	FPR - Manh� e Noite (aula extra)
	Data: 06/05/2023
	
	Lista de Exerc�cios VIII (Structs)
	
	Quest�o 02:
	Considere um vetor que, em cada posi��o, armazene os seguintes dados de um curso 
	de gradua��o: nome (por exemplo, Medicina, Engenharia, Direito, ...), 
	�rea (Humanas, Exatas, ...), cidade na qual funciona e a quantidade de alunos 
	matriculados no curso.
	
	Desenvolver uma fun��o que, dado um vetor nesses moldes, um c�digo inteiro cod e 
	uma string str, retorne a quantidade de alunos associados aos par�metros.
	
	Se o c�digo for igual a 1, str representar� um curso  e, portanto, a fun��o dever� 
	retornar a quantidade de alunos matriculados no curso str, destacando que o mesmo 
	curso pode encontrar-se em mais de uma posi��o do vetor (em cidades diferentes, 
	por exemplo). Por outro lado, se o c�digo for 2, str representar� uma �rea e, 
	portanto, dever� ser retornado o total de alunos matriculados em cursos daquela �rea.
*/

//importa��o de bibliotecas
#include <stdio.h>

//defini��o de tipos
typedef struct {
	char nome[20];
	char area[10];
	char cidade[20];
	int quantAlunos;
} TCurso;

//prot�tipos das fun��es
void preencherVetorCursos (TCurso vetCursos[], int tamanho);
int quantidadeAlunos (TCurso vetCursos[], int tamanho, int codigo, char str[]);

//main
void main ()
{
	//declara��o de vari�veis
	TCurso cursos[5];
	int resp;
	
	//preenchendo o vetor
	preencherVetorCursos (cursos, 5);
	
	//chamada 1 � fun��o
	resp = quantidadeAlunos (cursos, 5, 1, "SISTEMAS");	
	printf ("%d alunos atenderam aos filtros da pesquisa 1\n\n", resp);
	
	//chamada 2 � fun��o
	resp = quantidadeAlunos (cursos, 5, 2, "EXATAS");	
	printf ("%d alunos atenderam aos filtros da pesquisa 2\n\n", resp);
}

//implementa��o das fun��es
void preencherVetorCursos (TCurso vetCursos[], int tamanho)
{
	//declara��o de vari�veis
	int i;
	
	//varrendo o vetor
	for (i=0;i<tamanho;i++)
	{
		//lendo as informa��es de cada pessoa
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
	//declara��o de vari�veis
	int i, quant = 0;
	
	//testando o valor do c�digo
	if (codigo == 1) //filtro: nome do curso
	{
		//percorrendo o vetor
		for (i=0;i<tamanho;i++)
		{
			//verificando se o curso da posi��o 'i' � aquele especificado no par�metro 'str'
			if (strcmp (str, vetCursos[i].nome) == 0)
			{
				quant += vetCursos[i].quantAlunos;
			}
		}
	}
	else	//entende que o c�digo � igual a 2
	{
		//percorrendo o vetor
		for (i=0;i<tamanho;i++)
		{
			//verificando se a �rea da posi��o 'i' � aquela especificada no par�metro 'str'
			if (strcmp (str, vetCursos[i].area) == 0)
			{
				quant += vetCursos[i].quantAlunos;
			}
		}
	}
	
	//retornando a quantiade calculada
	return quant;
}
