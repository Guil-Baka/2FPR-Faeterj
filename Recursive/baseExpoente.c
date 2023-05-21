#include <stdio.h>
#include <stdlib.h>
#include <sys/timeb.h>

int main()
{
  printf("Digite a base: ");
  int base;
  scanf("%d", &base);
  printf("Digite o expoente: ");
  int expoente;
  scanf("%d", &expoente);

  int resultado = 1;

  resultado = recursivePow(base, expoente);


  printf("O resultado é: %d", resultado);
  
  //wait x seconds
  sleep(10);
  return 0;
}

int recursivePow(int base, int expoente)
{
  if (expoente == 0)
  {
    return 1;
  }
  else
  {
    return base * recursivePow(base, expoente - 1);
  }
}
