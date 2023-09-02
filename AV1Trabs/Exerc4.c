// Implementar uma função que, dado um
// arquivo texto A contendo números inteiros, um
// por linha, cria um novo arquivo texto, B,
// contendo os mesmos valores de A, porém em
// ordem inversa.

#include <stdio.h>
#include <stdlib.h>

//Protótipos das funções
int inverterArquivo(char *nomeArquivo);

int main()
{
  char nomeArquivo[100] = "arquivo.txt";

  //Chamada da função para inverter o arquivo
  inverterArquivo(nomeArquivo);
  //Eu não sei pq ta pulando linha :(   

  return 0;
}

int inverterArquivo(char *nomeArquivo)
{
  FILE *arquivo;
  FILE *arquivoInvertido;
  FILE *arquivoTemporario;

  char i;

  // abrir arquivo para leitura
  arquivo = fopen(nomeArquivo, "r");

  // abrir arquivo temporario para escrita
  arquivoTemporario = fopen("temporario.txt", "w");

  // ler o conteudo de arquivo e escrever em arquivo temporario
  while (fscanf(arquivo, "%d", &i) != EOF)
  {
    fprintf(arquivoTemporario, "%d\n", i);
  }

  // fechar arquivo e arquivo temporario
  fclose(arquivo);
  fclose(arquivoTemporario);

  // abrir arquivo temporario para leitura
  arquivoTemporario = fopen("temporario.txt", "r");
  // abrir arquivo invertido para escrita
  arquivoInvertido = fopen("invertido.txt", "w");

  if (fseek(arquivoTemporario, 0, SEEK_END) != 0)
  {
    printf("Erro ao posicionar ponteiro no final do arquivo temporario");
    return 1;
  }
  long posicao = ftell(arquivoTemporario);

  while (--posicao >=0)
  {
    fseek(arquivoTemporario, posicao, SEEK_SET);
    i = fgetc(arquivoTemporario);
    fputc(i, arquivoInvertido);
  }

  // fechar arquivo temporario e arquivo invertido
  fclose(arquivoTemporario);
  fclose(arquivoInvertido);
  
  // remover arquivo temporario
  remove("temporario.txt");
  return 0;
}