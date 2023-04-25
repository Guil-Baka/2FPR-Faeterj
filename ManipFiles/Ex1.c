#include <stdio.h>
#include <stdlib.h>

void main(){

  int i;
  FILE *fileA;

  fileA = fopen("fileA.txt", "w");

                     //fileA==NULL is the same as fileA!=NULL
  if (fileA == NULL) // if fileA is NULL, then the file was not created
  {
    printf("Error opening fileA.txt");
    exit(1);
  }
  else{
    printf("FileA.txt created successfully");
    for (i = 0; i <= 1000; i++)
    {
      fprintf(fileA, "%d\n ", i);
    }
  }
  fclose(fileA);
}