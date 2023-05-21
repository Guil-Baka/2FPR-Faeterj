/*
	FAETERJ-Rio
	FPR - Fundamentos de Programa��o - Noite
	Professor Leonardo Vianna
	
	Prova a compor a AV1 - 08/05/2023
	
	Quest�o 03 [2,5 pontos]:
	Considere a exist�ncia de um vetor de structs com quant posi��es, onde cada uma destas armazena os 
	seguintes dados sobre um grupo de pessoas: nome (string), g�nero (char) e idade (int). Pede-se uma fun��o 
	que determine se os elementos deste vetor est�o ordenados e retorne 1, caso estejam ordenados, e 0, 
	caso contr�rio.

	Observa��o: o vetor ser� considerado ordenado se estiver organizado crescentemente em fun��o da 
	idade. Por�m, no caso de pessoas com a mesma idade, estas devem estar ordenadas crescentemente pelo nome. 
*/

//importa��o de bibliotecas
#include <stdio.h>
#include <string.h>

//defini��o de tipos
// ??????
//struct com os dados de uma pessoa
struct pessoa
{
  char nome[20];
  char genero;
  int idade;
};

//prot�tipos das fun��es
// ??????
int verificarPessoa(struct pessoa vetPessoas[]);
//main
void main ()
{
	//declara��o de vari�veis
  //declara array de struct da pessoa
  struct pessoa vetPessoas[4];
	int retorno;
	
	//inicializando o vetor vetPessoas1
  strcpy (vetPessoas[0].nome, "ANA");
	vetPessoas[1].genero = 'F';
	vetPessoas[1].idade = 20;

	strcpy (vetPessoas[1].nome, "JOAO");
	vetPessoas[0].genero = 'M';
	vetPessoas[0].idade = 25;
	
	strcpy (vetPessoas[2].nome, "JULIA");
	vetPessoas[2].genero = 'M';
	vetPessoas[2].idade = 30;
	
	strcpy (vetPessoas[3].nome, "PEDRO");
	vetPessoas[3].genero = 'M';
	vetPessoas[3].idade = 35;
		
	//chamando a fun��o e armazenando o retorno na vari�vel 'retorno'
	// ?????
	retorno = verificarPessoa(vetPessoas);
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
	
//implementa��o das fun��es
// ??????????????????

//verificar se os dados do vetor estão ordenados por ordem alfabética e idade
int verificarPessoa(struct pessoa vetPessoas[])
{
  //declaração de variáveis
  int i, j;
  int retorno = 0;

  // verifica se os dados estão ordenados por idade
  i=0;
  while ((i+1) <= 3) //3 sendo o ultimo elemento do vetor
  {
    printf("\n%d", i);
    if (vetPessoas[i].idade < vetPessoas[i+1].idade)
    {
      retorno = 1;
    }
    else
    {
      retorno = 0;
    }
    i++;
  }
  // verifica se os dados estão ordenados por ordem alfabética
  i=0;
  while ((i+1) <= 3) //3 sendo o ultimo elemento do vetor
  {
    printf("\n%d", i);
    if (vetPessoas[i].nome < vetPessoas[i+1].nome)
    {
      retorno = 1;
    }
    else
    {
      retorno = 0;
    }
    i++;
  }
  return retorno;
}
