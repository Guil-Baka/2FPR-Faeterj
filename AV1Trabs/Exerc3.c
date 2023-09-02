// Uma Clínica Veterinária mantém um vetor de
// structs, do qual cada posição armazena as
// seguintes informações: código do cadastro,
// nome do pet, nome do tutor, e-mail de contato,
// data da última vacina.
// Desenvolver uma função que, dado um vetor
// com esta estrutura, gere um arquivo texto com
// os dados dos pets com vacina vencida (mais de
// um ano da última).
// Cada linha do arquivo terá a seguinte sintaxe:

// email|mensagem

// E a mensagem terá o formato apresentado
// abaixo:
// Prezado <nome_tutor>, a vacina do pet
// <nome_pet> venceu no dia dd/mm/aaaa.
// Podemos agendar a nova dose?

#include <stdio.h>
#include <stdlib.h>

//structs
struct cadastro
{
  int codigo;
  char nomePet[100];
  char nomeTutor[100];
  char email[100];
  char dataVacina[100];
};

//protótipos das funções
int populateStruct(struct cadastro *clientes, int tam);
int writeStructToFile(struct cadastro *clientes, int tam);
int writeStuctVacinaVencidaToFile(struct cadastro *clientes, int tam);

//define
#define tamanho 2

int main(int argc, char const *argv[])
{
  int i=0;

  //vetor da struct
  struct cadastro cliente[tamanho];

  populateStruct(cliente, tamanho);

  writeStructToFile(cliente, tamanho);
  
  return 0;
}

int populateStruct(struct cadastro *clientes, int tam)
{
  int i=0;
  for (i = 0; i < tam; i++)
  {
    printf("Digite o código do cadastro: ");
    scanf("%d", &clientes[i].codigo);
    printf("Digite o nome do pet: ");
    scanf("%s", &clientes[i].nomePet);
    printf("Digite o nome do tutor: ");
    scanf("%s", &clientes[i].nomeTutor);
    printf("Digite o email de contato: ");
    scanf("%s", &clientes[i].email);
    printf("Digite a data da última vacina: ");
    scanf("%s", &clientes[i].dataVacina);
  }
  return 0;
}

int writeStructToFile(struct cadastro *clientes, int tam)
{
  int i=0;
  FILE *arq;
  arq = fopen("clientes.txt", "w");
  if (arq == NULL)
  {
    printf("Erro ao abrir o arquivo.\n");
    return 1;
  }
  for (i = 0; i < tam; i++)
  {
    fprintf(arq, "%d|%s|%s|%s|%s\n", clientes[i].codigo, clientes[i].nomePet, clientes[i].nomeTutor, clientes[i].email, clientes[i].dataVacina);
  }
  fclose(arq);
  return 0;
}

int writeStuctVacinaVencidaToFile(struct cadastro *clientes, int tam)
{
  int i=0;
  FILE *arq;
  arq = fopen("vacinaVencida.txt", "w");
  if (arq == NULL)
  {
    printf("Erro ao abrir o arquivo.\n");
    return 1;
  }
  for (i = 0; i < tam; i++)
  {
    fprintf(arq, "Prezado %s, a vacina do pet %s venceu no dia %s. Podemos agendar a nova dose?\n", clientes[i].nomeTutor, clientes[i].nomePet, clientes[i].dataVacina);
  }
  fclose(arq);
  return 0;
}

