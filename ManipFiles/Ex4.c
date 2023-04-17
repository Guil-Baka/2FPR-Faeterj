#include <stdio.h>
#include <stdlib.h>

// funcPrototypes
int readFiles(char fileName[], char fileMode[], int maxNum);

void main(){
  if((writeToFile("fileA.txt","w" ,500 ) == 0)){
    printf("Error opening fileA.txt");
    exit(1);
  }
  else{
    printf("FileA.txt created successfully");
  }
}

int readFiles(char fileName[], char fileMode[], int maxNum){
  FILE *fileA;
  int i,numero;

  fileA = fopen(fileName, fileMode);

  if (fileA == NULL)
  {
    return 0;
  }
  else
  {
    while (fscanf(fileA, "%d", &i) != EOF)
    {
      printf("%d \n", numero);
    }
    
    for (i = 0; i <= maxNum; i++)
    {
      fprintf(fileA, "%d \n", i);
    }
    return 1;
  }
  fclose(fileA);
}