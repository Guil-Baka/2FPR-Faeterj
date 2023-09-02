// Questão 04 [2,5 pontos]:
// Para a implementação de filas com prioridades, são
// utilizadas várias filas, uma para cada possível
// prioridade, criando-se, portanto, um vetor de filas (ou
// seja, TLista[]). Por exemplo, em uma estrutura com
// TAM filas (onde TAM é uma constante), podemos
// considerar que os nós da fila de índice 0 possuem
// maior prioridade do que os da fila 1 à fila TAM-1; esta
// fila, por sua vez, possui nós com maior prioridade do
// que os da fila 2 à fila TAM-1 e, assim, sucessivamente.

// Pede-se que sejam implementadas as funções de
// inserção e remoção nesta estrutura, considerando que:
// 1. Para que um novo elemento seja inserido, será
// necessário também informar a sua prioridade
// (de 0 a TAM-1);

// 2. Ao remover um elemento, será retirado da
// estrutura o primeiro nó da fila que, dentre
// aquelas que possuem elementos, possui a
// maior prioridade.

#include <stdio.h>
#include <stdlib.h>

#define TAM 5

typedef struct No
{
  int valor;
  struct No *prox;
} TNo;

typedef TNo *TLista;

// prototipos das funcoes
int menu();
void exibir(TLista *fila);
void imprimirFila(TLista fila);
int inserirNaFila(TLista *fila, TLista *ultimo, int valor);
int removerDaFila(TLista *fila, TLista *ultimo, int *valor);

int main(void)
{
  TLista filas[TAM], ultimos[TAM];
  int op, valor, prioridade;
  // inicializa as filas
  for (int i = 0; i < TAM; i++)
  {
    filas[i] = NULL;
    ultimos[i] = NULL;
  }
  // menu
  op = menu();

  while (op != 4)
  {
    switch (op)
    {
    case 1:
      // limpa console
      system("cls");
      // recebe o valor a ser inserido
      printf("Digite o valor a ser inserido: ");
      scanf("%d", &valor);
      // recebe a prioridade
      printf("Digite a prioridade: ");
      scanf("%d", &prioridade);
      // insere o valor na fila
      inserirNaFila(&filas[prioridade], &ultimos[prioridade], valor);
      break;
    case 2:
      // limpa console
      system("cls");
      // remove o primeiro elemento da fila
      removerDaFila(&filas, &ultimos, &valor);
      printf("Valor removido: %d\n", valor);
      break;
    case 3:
      // limpa console
      system("cls");
      // imprime a fila
      exibir(filas);
      break;
    }
    // menu
    op = menu();
  }
}

// funções
int menu()
{
  int op;
  printf("1 - Inserir\n");
  printf("2 - Remover\n");
  printf("3 - Exibir\n");
  printf("4 - Sair\n");
  printf("Digite a opcao: ");
  scanf("%d", &op);
  return op;
}

void exibir(TLista *fila)
{
  // exibe cada elemento da fila prioridade por prioridade
  for (int i = 0; i < TAM; i++)
  {
    printf("Fila %d: ", i);
    imprimirFila(fila[i]);
  }
}

void imprimirFila(TLista fila)
{
  TLista aux = fila;
  while (aux != NULL)
  {
    printf("%d ", aux->valor);
    aux = aux->prox;
  }
  printf("\n");
}

int inserirNaFila(TLista *fila, TLista *ultimo, int valor)
{
  TLista aux = (TLista)malloc(sizeof(TNo));
  if (aux == NULL)
    return 0;
  aux->valor = valor;
  aux->prox = NULL;
  if (*fila == NULL)
  {
    *fila = aux;
  }
  else
  {
    (*ultimo)->prox = aux;
  }
  *ultimo = aux;
  return 1;
}
// função ira remover da fila por prioridade, ou seja ira começar pela fila de maior prioridade que é a 0 até chegar na de menor prioridade que é a TAM-1
int removerDaFila(TLista *fila, TLista *ultimo, int *valor)
{
  TLista aux;
  // percorre as filas
  for (int i = 0; i < TAM; i++)
  {
    // verifica se a fila possui elementos
    if (fila[i] != NULL)
    {
      // remove o primeiro elemento da fila
      aux = fila[i];
      *valor = aux->valor;
      fila[i] = aux->prox;
      free(aux);
      return 1;
    }
  }
  return 0;
}
