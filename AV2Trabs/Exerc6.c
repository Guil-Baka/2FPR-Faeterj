#include <stdio.h>
#include <stdlib.h>

typedef struct No {
  int valor;
  struct No* prox;
} TNo;

typedef struct checkNo {
  int valor;
  int qtd;
  struct checkNo* prox;
} LCheckNo;

//Redefinir nomes pq n quero ponteiro isso me assusta
typedef LCheckNo* LCheck;
typedef TNo* TLista;

//Protótipo das funções
int inserir (TLista *list, int numero);
void exibir (TLista list);
int criarLista2(TLista list, LCheck* check);
int inserirLista2(LCheck* check, int numero, int qtd);
int repeticao(LCheck check, int numero);


int main(void)
{
  TLista lista = NULL;
  LCheck check = NULL;
  int elementosLista[12] = {1,4,5,7,4,3,2,5,4,7,1,2};
  //inserir os elementos na lista ao contrario
  for (int i = 11; i >= 0; i--)
  {
    inserir(&lista, elementosLista[i]);
  } //ao contrario pra ficar igual o exemplo do professor
  //exibir os elementos da lista
  exibir(lista);
  //criar a lista 2 e exibir essa m*rda
  criarLista2(lista, &check);
  //To com preguiça de fazer a função pra liberar a memória :)
  //To puto pq foi dificil pra car*lho fazer essa m*rda
  //Boa noite Léo <3
}

//Função para inserir um elemento na lista
int inserir (TLista *list, int numero)
{
  TLista aux = (TLista) malloc(sizeof(TNo));
  if (aux == NULL) return 0;
  aux->valor = numero;
  aux->prox = *list;
  *list = aux;
  return 1;
}

//Função para exibir os elementos da lista
void exibir (TLista list)
{
  TLista aux = list;
  while (aux != NULL)
  {
    printf("%d ", aux->valor);
    aux = aux->prox;
  }
  printf("\n");
}

//Criar a lista 2 a partir da lista 1 armazenando os valores e a quantidade de vezes que eles aparecem e exibir
int criarLista2(TLista list, LCheck* check)
{
  //Avaliar a list e criar a lista 2
  TLista aux = list;
  LCheck aux2 = NULL;
  //enquanto a lista 1 não acabar
  while (aux != NULL)
  {
    //se o valor não estiver na lista 2
    if (repeticao(*check, aux->valor) == 0)
    {
      //inserir o valor na lista 2
      inserirLista2(check, aux->valor, 1);
    }
    //se o valor já estiver na lista 2
    else
    {
      //incrementar a quantidade de vezes que ele aparece
      aux2 = *check;
      while (aux2 != NULL)
      {
        if (aux2->valor == aux->valor)
        {
          aux2->qtd++;
          break;
        }
        aux2 = aux2->prox;
      }
    }
    aux = aux->prox;
  }
  //exiba os elementos da lista 2
  while (aux2 != NULL)
  {
    printf("Valor: %d, Quantidade: %d\n", aux2->valor, aux2->qtd);
    aux2 = aux2->prox;
  }
  return 1;
}
//Função para inserir um elemento na check
int inserirLista2(LCheck* check, int numero, int qtd)
{
  LCheck aux = (LCheck) malloc(sizeof(LCheckNo));
  if (aux == NULL) return 0;
  aux->valor = numero;
  aux->qtd = qtd;
  aux->prox = *check;
  *check = aux;
  return 1;
}
//Função para verificar se o elemento já está na lista
int repeticao(LCheck check, int numero)
{
  LCheck aux = check;
  while (aux != NULL)
  {
    if (aux->valor == numero)
    {
      return 1;
    }
    aux = aux->prox;
  }
  return 0;
}