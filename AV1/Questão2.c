/*
	FAETERJ-Rio
	FPR - Fundamentos de Programação - Noite
	Professor Leonardo Vianna
	
	Prova a compor a AV1 - 08/05/2023
	
	Questão 02 [2,5 pontos]:
	Dadas duas strings s1 e s2, implementar uma função que verifique se todos os caracteres de s1 estão em s2. 
	Dependendo do resultado, os seguintes valores deverão ser retornados:
	
		0:	nem todos os caracteres de s1 estão em s2;
		1:	todos os caracteres de s1 estão em s2, porém não na mesma frequência;
		2:	todos os caracteres de s1 estão em s2, na mesma frequência.
*/

//importação de bibliotecas
#include <stdio.h>

//protótipos das funções
??????

//main
void main ()
{
	//declaração de variáveis
	char string1[20], string2[20];
	int retorno;
	
	//obtendo as duas strings
	printf ("Primeira string: ");
	fflush (stdin);
	gets (string1);
	
	printf ("\nSegunda string: ");
	fflush (stdin);
	gets (string2);
	
	//chamando a função e armazenando o retorno na variável 'retorno'
	?????
	
	//testando o retorno
	switch (retorno)
	{
		case 0: printf ("\nNem todos os caracteres de %s estao em %s.\n", string1, string2);
		        break;
		        
		case 1: printf ("\nTodos os caracteres de %s estao em %s, porem nao na mesma frequencia.\n", string1, string2);
		        break;
		        
		case 2: printf ("\nTodos os caracteres de %s estao em %s e na mesma frequencia.\n", string1, string2);
		        break;
	}
}
	
//implementação das funções
??????????????????
