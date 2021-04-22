// Author: Mohamad Elchami Date: November 30th, 2017

#include <stdio.h>

int main(int argc, char *argv[])
{
  FILE *fp;
  char *txt=NULL;
  char ch;

  printf("\n");

  if(argc<2)
  {
    printf("Cannot open %s\n", txt);
  }

  else
  {
    txt = argv[1];
    printf("%s", txt);
  }

  printf("\n\n");

  fp = fopen(txt, "r");

  while((ch = fgetc(fp)) != EOF)
  {
    printf("%c", ch);
  }

  printf("\nGood Bye.\n");

  return(0);
}
