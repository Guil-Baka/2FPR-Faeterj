/*
	FAETERJ-Rio
	FPR - Fundamentos de Programa��o - Noite
	Professor Leonardo Vianna
	
	Prova a compor a AV1 - 08/05/2023
	
	Quest�o 02 [2,5 pontos]:
	Dadas duas strings s1 e s2, implementar uma fun��o que verifique se todos os caracteres de s1 est�o em s2. 
	Dependendo do resultado, os seguintes valores dever�o ser retornados:
	
		0:	nem todos os caracteres de s1 est�o em s2;
		1:	todos os caracteres de s1 est�o em s2, por�m n�o na mesma frequ�ncia;
		2:	todos os caracteres de s1 est�o em s2, na mesma frequ�ncia.
*/

//importa��o de bibliotecas
#include <stdio.h>

//prot�tipos das fun��es
??????

//main
void main ()
{
	//declara��o de vari�veis
	char string1[20], string2[20];
	int retorno;
	
	//obtendo as duas strings
	printf ("Primeira string: ");
	fflush (stdin);
	gets (string1);
	
	printf ("\nSegunda string: ");
	fflush (stdin);
	gets (string2);
	
	//chamando a fun��o e armazenando o retorno na vari�vel 'retorno'
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
	
//implementa��o das fun��es
??????????????????
