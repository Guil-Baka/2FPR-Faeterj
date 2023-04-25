#include <stdio.h>
#include <stdlib.h>

//Ex2: Add 100 numbers to fileA.txt created in Ex1

void main(){
  int i;
  FILE *fileA;

  fileA = fopen("fileA.txt", "a");

  if (fileA == NULL)
  {
    printf("Error opening fileA.txt");
    exit(1);
  }
  else{
    printf("FileA.txt created successfully");
    for (i = 0; i <= 100; i++)
    {
      fprintf(fileA, "%d\n ", i);
    }
  }
  fclose(fileA);
}