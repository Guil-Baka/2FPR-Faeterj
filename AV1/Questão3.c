/*
	FAETERJ-Rio
	FPR - Fundamentos de Programação - Noite
	Professor Leonardo Vianna
	
	Prova a compor a AV1 - 08/05/2023
	
	Questão 03 [2,5 pontos]:
	Considere a existência de um vetor de structs com quant posições, onde cada uma destas armazena os 
	seguintes dados sobre um grupo de pessoas: nome (string), gênero (char) e idade (int). Pede-se uma função 
	que determine se os elementos deste vetor estão ordenados e retorne 1, caso estejam ordenados, e 0, 
	caso contrário.

	Observação: o vetor será considerado ordenado se estiver organizado crescentemente em função da 
	idade. Porém, no caso de pessoas com a mesma idade, estas devem estar ordenadas crescentemente pelo nome. 
*/

//importação de bibliotecas
#include <stdio.h>
#include <string.h>

//definição de tipos
??????

//protótipos das funções
??????

//main
void main ()
{
	//declaração de variáveis
	???? vetPessoas[4];
	int retorno;
	
	//inicializando o vetor vetPessoas1
	strcpy (vetPessoas[0].nome, "JOAO");
	vetPessoas[0].genero = 'M';
	vetPessoas[0].idade = 25;
	
	strcpy (vetPessoas[1].nome, "ANA");
	vetPessoas[1].genero = 'F';
	vetPessoas[1].idade = 30;
	
	strcpy (vetPessoas[2].nome, "JULIA");
	vetPessoas[2].genero = 'M';
	vetPessoas[2].idade = 30;
	
	strcpy (vetPessoas[3].nome, "PEDRO");
	vetPessoas[3].genero = 'M';
	vetPessoas[3].idade = 35;
		
	//chamando a função e armazenando o retorno na variável 'retorno'
	?????
	
	//testando o retorno
	if (retorno == 1)
	{
		printf ("\nOs dados do vetor estao ordenados!");
	}
	else
	{
		printf ("\nOs dados do vetor NAO estao ordenados!");
	}
}
	
//implementação das funções
??????????????????
