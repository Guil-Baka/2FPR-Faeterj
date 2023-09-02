#include <stdio.h>
#include <stdlib.h>

#define qElementos 12

typedef struct No
{
  int valor;
  struct No *prox;
} TNo;

typedef TNo *TLista;

// prototipos das funcoes

int main(void)
{
  int i, pos;
  TLista lista = NULL;
  // popular lista usando for
  for (i = 0; i < qElementos; i++)
  {
    inserir(&lista, i);
  }
  // exibir lista
  exibir(lista);
  // pedir posicao
  printf("Digite a posicao a ser removida: ");
  scanf("%d", &pos);
  pos = removerPosicaoRecursivo(&lista, pos);
  // elemento foi removido?
  if (pos == 1)
  {
    printf("Elemento removido com sucesso!\n");
  }
  else
  {
    printf("Elemento nao removido!\n");
  }
  // exibir lista novamente
  exibir(lista);
}

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

int removerPosicaoRecursivo(TLista *lista, int posicao)
{
  if (posicao == 1)
  {
    TLista aux = *lista;
    *lista = (*lista)->prox;
    free(aux);
    return 1;
  }
  else
  {
    return removerPosicaoRecursivo(&(*lista)->prox, posicao - 1);
  }
}
