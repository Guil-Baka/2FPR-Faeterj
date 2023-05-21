/*
  FAETERJ-Rio
  FPR - Fundamentos de Programa��o - Noite
  Professor Leonardo Vianna

  Prova a compor a AV1 - 08/05/2023

  Quest�o 04 [2,5 pontos]:
  Fazer uma fun��o que, dado um arquivo texto com n�meros inteiros, um por linha, remova deste os valores
  da linha L1 � linha L2.

  Observa��es:
    1. Se a primeira linha for inv�lida, nada ser� realizado e o valor 0 retornado pela fun��o. O mesmo
       ocorrer� se a segunda linha for inferior � primeira;
    2. Se a linha L2 ultrapassar o final do arquivo, ser�o removidos todos os elementos da linha L1 ao final
       do arquivo;
    3. Sempre que a opera��o for realizada, o valor 1 dever� ser retornado.
*/

// importa��o de bibliotecas
#include <stdio.h>
#include <string.h>

// prot�tipos das fun��es
// ? ? ? ? ? ?
int deletarEntre(int linha1, int linha2);
// main
void main()
{
  // declara��o de vari�veis
  char nomeArquivo[20];
  int linha1, linha2, retorno;

  // associando o arquivo "teste.txt" � vari�vel 'nomeArquivo'
  strcpy(nomeArquivo, "teste.txt");

  // lendo as linhas que ser�o manipuladas
  printf("Primeira linha: ");
  scanf("%d", &linha1);

  printf("\nSegunda linha: ");
  scanf("%d", &linha2);

  // chamando a fun��o e armazenando o retorno na vari�vel 'retorno'
  // ? ? ? ? ?
  retorno = deletarEntre(linha1, linha2);
  // testando o retorno
  if (retorno == 1)
  {
    printf("\nAs linhas solicitadas foram removidas do arquivo %s!", nomeArquivo);
  }
  else
  {
    printf("\nAs linhas informadas sao invalidas!");
  }
}

// implementa��o das fun��es
// ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ?

// função para deletar linhas dentro do txt que estão entre L1 e L2
int deletarEntre(int linha1, int linha2)
{
  // abrir arquivo
  FILE *arquivo;
  arquivo = fopen("teste.txt", "r");
  // criar arquivo temporário
  FILE *arquivoTemp;
  arquivoTemp = fopen("temp.txt", "w");

  // copiar conteudo do arquivo para arquivoTemp ignorando as linhas entre linha1 e linha2
  int i = 1;
  char c;

  // verificar e a linha2 é menor que a linha1 e se a linha1 é menor que 0
  if (linha2 < linha1 || linha1 < 1)
  {
    return 0;
  }
  else
  {
    while ((c = getc(arquivo)) != EOF)
    {
      if (i < linha1 || i > linha2)
      {
        putc(c, arquivoTemp);
      }
      if (c == '\n')
      {
        i++;
      }
    }
    // substitui o arquivo temporario pelo arquivo original
    fclose(arquivo);
    fclose(arquivoTemp);
    remove("teste.txt");
    rename("temp.txt", "teste.txt");
    return 1;
  }
}