#include <stdio.h>
#include <stdlib.h>

#define qElementos 20

typedef struct No
{
  int valor;
  struct No *prox;
} TNo;

typedef TNo *TLista;

// prototipos das funcoes
int inserir(TLista *lista, int numero);
int exibir(TLista lista);
int criarSubListas(TLista *lista, TLista *L1, TLista *L2, int N);

int main(void)
{
  int numero;
  TLista L1 = NULL, L2 = NULL, lista = NULL;
  // gerar lista com for
  for (int i = 1; i < qElementos; i++)
  {
    inserir(&lista, i);
  }
  // exibe a lista
  printf("Lista: ");
  exibir(lista);
  // receber os valores
  printf("Digite o numero: ");
  scanf("%d", &numero);
  // criar sublistas
  criarSubListas(&lista, &L1, &L2, numero);
  // exibir lista L1
  printf("Lista L1(Menores que N): ");
  exibir(L1);
  // exibir lista L2
  printf("Lista L2(Maiores ou igual a N): ");
  exibir(L2);
}

// funções

int inserir(TLista *lista, int numero)
{
  TLista aux = (TLista)malloc(sizeof(TNo));
  if (aux == NULL)
    return 0;
  aux->valor = numero;
  aux->prox = *lista;
  *lista = aux;
  return 1;
}

int exibir(TLista lista)
{
  TLista aux = lista;
  while (aux != NULL)
  {
    printf("%d ", aux->valor);
    aux = aux->prox;
  }
  printf("\n");
  return 1;
}

// popular as listas L1 com os valores inferiores a N e L2 com os valores superiores ou iguais a N
int criarSubListas(TLista *lista, TLista *L1, TLista *L2, int N)
{
  TLista aux = *lista;
  // de forma recursiva
  if (aux == NULL)
  {
    return 0;
  }
  else
  {
    if (aux->valor < N)
    {
      inserir(L1, aux->valor);
    }
    else
    {
      inserir(L2, aux->valor);
    }
    criarSubListas(&aux->prox, L1, L2, N);
  }
}

// while (aux != NULL)
// {
//   if (aux->valor < N)
//   {
//     inserir(L1, aux->valor);
//   }
//   else
//   {
//     inserir(L2, aux->valor);
//   }
//   aux = aux->prox;
// }

// TLista aux = (TLista) malloc(sizeof(TNo));
//   if (aux == NULL)
//   {
//     return 0;
//   }
//   else
//   {
//     //percorrer lista
//     while (aux != NULL)
//     {
//       if (aux->valor < numero)
//       {
//         inserir(L1, aux->valor);
//       }
//       aux = aux->prox;
//     }
//   }
