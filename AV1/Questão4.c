/*
	FAETERJ-Rio
	FPR - Fundamentos de Programação - Noite
	Professor Leonardo Vianna
	
	Prova a compor a AV1 - 08/05/2023
	
	Questão 04 [2,5 pontos]:
	Fazer uma função que, dado um arquivo texto com números inteiros, um por linha, remova deste os valores 
	da linha L1 à linha L2.
	
	Observações: 
		1. Se a primeira linha for inválida, nada será realizado e o valor 0 retornado pela função. O mesmo 
		   ocorrerá se a segunda linha for inferior à primeira;
		2. Se a linha L2 ultrapassar o final do arquivo, serão removidos todos os elementos da linha L1 ao final 
		   do arquivo;
		3. Sempre que a operação for realizada, o valor 1 deverá ser retornado. 
*/

//importação de bibliotecas
#include <stdio.h>
#include <string.h>

//protótipos das funções
??????

//main
void main ()
{
	//declaração de variáveis
	char nomeArquivo[20];
	int linha1, linha2, retorno;
	
	//associando o arquivo "teste.txt" à variável 'nomeArquivo'
	strcpy (nomeArquivo, "teste.txt");
		
	//lendo as linhas que serão manipuladas
	printf ("Primeira linha: ");
	scanf ("%d", linha1);
	
	printf ("\nSegunda linha: ");
	scanf ("%d", linha2);
			
	//chamando a função e armazenando o retorno na variável 'retorno'
	?????
	
	//testando o retorno
	if (retorno == 1)
	{
		printf ("\nAs linhas solicitadas foram removidas do arquivo %s!", nomeArquivo);
	}
	else
	{
		printf ("\nAs linhas informadas sao invalidas!");
	}
}
	
//implementação das funções
??????????????????
