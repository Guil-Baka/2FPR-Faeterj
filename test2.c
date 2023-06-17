#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define end 7
#define begin 6

int main()
{
  char s1[] = "e ai, vc vem?    ";
  char s2[] = "voce";


  encaixarString(s1,s2);
  //print string
  printf("%s\n",s1);
  return 0;
}

void encaixarString(char S1[],char S2[])
{
  int i,j;

  for(i=strlen(S1)-strlen(S2);i>=8 ;i--)
  {
    for(j=i;j>8;j--)
    {
      S1[i+2]=S1[j];
    }
    
  }

}


