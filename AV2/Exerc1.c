#include <stdio.h>
#include <stdlib.h>

//prototipos das funcoes

int main()
{
  int n1, n2; //intervalo
  int res;
  //recebe o intervalo
  printf("Digite o N1: ");
  scanf("%d", &n1);
  printf("Digite o N2: ");
  scanf("%d", &n2);

  res = divisoresRecursivo(n1, n2);

  printf("Resultado: %d\n", res);

  return 0;
}

//Funções
int quantDivisoresRecursivo(int divisor, int dividendo)
{
  if(divisor == 0)
  {
    return 0;
  }
  else
  {
    if(dividendo % divisor == 0)
    {
      return 1 + quantDivisoresRecursivo(divisor - 1, dividendo);
    }
    else
    {
      return quantDivisoresRecursivo(divisor - 1, dividendo);
    }
  }
}

