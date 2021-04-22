// Author: Mohamad Elchami Date: November 28th, 2017

#include <stdio.h>

#define txt "104902736_MyMessage.txt";

int main(void)
{
  FILE *fp;

  fp=fopen("txt", "r");

  if (fp==null)
  {
    printf("Cannot open %s\n", txt);
  }

  printf("\nGood Bye.");

  return(0);
}
