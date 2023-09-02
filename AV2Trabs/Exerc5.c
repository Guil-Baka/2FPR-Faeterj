#include <stdio.h>

//Prototipo da funcao
int contarDivisores(int n, int div, int counter);

int main()
{
  int numero;
  int quantDivisores;
  
  printf("Digite um numero inteiro: ");
  scanf("%d", &numero);

  quantDivisores = contarDivisores(numero, numero, 0);

  printf("O numero %d tem %d divisores\n", numero, contarDivisores(numero, numero, 0));

  return 0;
}

//Div divisor, n numero, counter contador
int contarDivisores(int n, int div, int counter)
{
  if (div == 0)
  {
    return counter;
  }
  else
  {
    if (n % div == 0)
    {
      counter++;
    }
    return contarDivisores(n, div - 1, counter);
  }
}
