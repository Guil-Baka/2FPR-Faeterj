#include <stdio.h>
#include <stdlib.h>
//reading the contents of a file as a char and printing them to the screen

// funcPrototypes
int readFiles(char fileName[], char fileMode[], int maxNum);

void main(){
  if((readFiles("fileA.txt","r" ,500 ) == 0)){
    printf("Error opening fileA.txt");
    exit(1);
  }
  else{
    printf("FileA.txt created successfully");
  }
}

int readFiles(char fileName[], char fileMode[], int maxNum){
  FILE *fileA;
  int i;
  char letters;

  fileA = fopen(fileName, fileMode);

  if (fileA == NULL)
  {
    return 0;
  }
  else
  {
    while (fscanf(fileA, "%c", &i) != EOF)
    {
      printf("%d \n", letters);
    }
    
    for (i = 0; i <= maxNum; i++)
    {
      fprintf(fileA, "%d \n", i);
    }
    return 1;
  }
  fclose(fileA);
}