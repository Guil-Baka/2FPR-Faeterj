#include <stdio.h>
#include <stdlib.h>

typedef struct No{
  int valor;
  struct No *prox;
} TNo;

typedef TNo* TLista;

//prototipos das funcoes
int menu();
int inserirNaFila(TLista *fila, TLista *ultimo, int valor);
int removerDaFila(TLista *fila, TLista *ultimo, int *valor);
void imprimirFila(TLista fila);
int excluirValoresNoIntervalo(TLista *fila, TLista *ultimo);
int removerValorEspecificoDaFila(TLista *fila, TLista *ultimo, int valor);



//main
void main()
{
  TLista fila = NULL;
  TLista ultimo = NULL;
  int valor;
  //menu
  int op = menu();
  while(op != 6)
  {
    switch(op)
    {
      case 1:
        //limpa console
        system("cls");
        //recebe o valor a ser inserido
        printf("Digite o valor a ser inserido: ");
        scanf("%d", &valor);
        //insere o valor na fila
        inserirNaFila(&fila, &ultimo, valor);
        break;
      case 2:
        //limpa console
        system("cls");
        //remove o primeiro elemento da fila
        removerDaFila(&fila, &ultimo, &valor);
        printf("Valor removido: %d\n", valor);
        break;
      case 3:
        //limpa console
        system("cls");
        //imprime a fila
        imprimirFila(fila);
        break;
      case 4:
        //limpa console
        system("cls");
        //exclui os valores entre N1 e N2
        // printf("Valores excluidos: %d\n", excluirValores(&fila, &ultimo));
        break;
      case 5:
        //limpa console
        system("cls");
        //remove valor especifico da fila
        printf("Digite o valor a ser removido: ");
        scanf("%d", &valor);
        removerValorEspecificoDaFila(&fila, &ultimo, valor);
        break;
      default:
        printf("Opcao invalida!\n");
    }
    //recebe a proxima opção
    op = menu();
  }
}

//funcoes

//menu de operaçoes
int menu()
{
  int op;
  printf("1 - Inserir na fila\n");
  printf("2 - Remover da fila\n");
  printf("3 - Imprimir fila\n");
  printf("4 - Excluir valores entre N1 e N2\n");
  printf("5 - Remover valor especifico da fila\n");
  printf("6 - Sair\n");
  printf("Digite a opcao: ");
  scanf("%d", &op);
  //retorna a opção escolhida
  return op;
}

int inserirNaFila(TLista *fila, TLista *ultimo, int valor)
{
  TLista aux;
  //alocar memoria para o novo elemento
  aux = (TLista) malloc(sizeof(TNo));

  //erro na alocação?
  if(!aux) // if(aux == NULL)
  {
      return 0;
  }
  else
  {
    //iserir 'numero' na memoria alocada
    aux->valor = valor;
    //como é uma fila, a pessoa/elemento que chegou vai para o final da fila (Ultimo) e o proximo dela é NULL
    aux->prox = NULL;
    //verifica se o ultimo não é NULL
    if(*ultimo)
    {
      //se a fila não estiver vazia, o ultimo elemento da fila aponta para o novo elemento
      (*ultimo)->prox = aux;
    }
    else
    {
      //se a fila estiver vazia, o novo elemento é agora o primeiro da fila
      *fila = aux;
    }
    //o novo elemento é agora o ultimo da fila
    *ultimo = aux; //poderia ser *ultimo = (*ultimo)->prox;
    //inserido com sucesso retorna 1
    return 1;
  }
}

int removerDaFila(TLista *fila, TLista *ultimo, int *valor)
{
  TLista aux;
  //se a fila tá vazia não tem como remover
  if (!(fila)) 
  {
    return 0;
  }
  else
  {
    //Salvando temporariamente o primeiro elemento da fila
    aux = *fila;
    //o primeiro elemento da fila agora é o proximo do primeiro elemento
    *fila = aux->prox; //poderia ser *fila = (*fila)->prox;
    //se a fila ficou vazia, o ultimo elemento é NULL
    if(!(*fila))
    {
      *ultimo = NULL;
    }
    //o valor do primeiro elemento é salvo em 'valor'
    *valor = aux->valor;
    //liberando a memoria do primeiro elemento
    free(aux);
    //removido com sucesso retorna 1
    return 1;
  }
}

int removerValorEspecificoDaFila(TLista *fila, TLista *ultimo, int valor)
{
  //vars
  TLista aux;
  //se a fila tá vazia não tem como remover
  if (!(fila)) 
  {
    return 0;
  }
  else
  {
    //receber valor
    //Se o valor a ser removido não for o primeiro elemento da fila
    if((*fila)->valor != valor)
    {
      //percorre a fila até achar o valor
      for(aux = *fila; aux->prox != NULL && aux->prox->valor != valor; aux = aux->prox);
      //se o valor não foi encontrado
      if(aux->prox == NULL)
      {
        return 0;
      }
      else
      {
        //se o valor foi encontrado, o elemento que aponta para ele, agora aponta para o proximo dele
        aux->prox = aux->prox->prox;
        //se o valor a ser removido é o ultimo elemento da fila
        if(aux->prox == NULL)
        {
          //o ultimo elemento da fila agora é o elemento que aponta para ele
          *ultimo = aux;
        }
      }
    }
    else
    {
      //se o valor a ser removido é o primeiro elemento da fila
      //Salvando temporariamente o primeiro elemento da fila
      aux = *fila;
      //o primeiro elemento da fila agora é o proximo do primeiro elemento
      *fila = aux->prox; //poderia ser *fila = (*fila)->prox;
      //se a fila ficou vazia, o ultimo elemento é NULL
      if(!(*fila))
      {
        *ultimo = NULL;
      }
      //liberando a memoria do primeiro elemento
      free(aux);
    }
    
  }

}

//função que imprime a fila
void imprimirFila(TLista fila)
{
  TLista aux;
  //se a fila estiver vazia, não tem o que imprimir
  if(!fila)
  {
    printf("Fila vazia!\n");
  }
  else
  {
    //percorre a fila imprimindo os valores
    for(aux = fila; aux != NULL; aux = aux->prox)
    {
      printf("%d ", aux->valor);
    }
    printf("\n");
  }
}

//função para excluir os valores entre N1 e N2
int excluirValoresNoIntervalo(TLista *fila, TLista *ultimo)
{
  
}
