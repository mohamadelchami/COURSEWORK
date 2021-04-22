//Author: Mohamad Elchami Date Feb 21, 2018 Description: String practice

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void Reverse(char *pBuffer3);
void RecursiveReverse(char *pBuffer3, char placement, short length);

int main()
{
  // Part 1
  printf("\n======================================================================\n");
  printf("Part 1: \n\n");
  int wordcount=0;
  short menu;
  char Buffer1[] = {'t','h','i','s',' ','i','s',' ','t','h','e',' ','f','i','r','s','t',' ','b','u','f','f','e','r','.','\0'} ;
  char Buffer2[] =  "this is the second buffer." ;
  char Buffer3[80];

  //ask for string input for Buffer3
  printf("Enter a string for Buffer3: ");
  fgets(Buffer3, 80, stdin);

  //print the strings
  printf("\nThe first buffer is: \n %s \n", Buffer1);
  printf("\nThe second buffer is: \n %s \n", Buffer2);
  printf("\nThe third Buffer is: \n %s \n", Buffer3);

  // ========================= OUTPUTS ===============================
  // Buffer1 prints "this is the first buffer."
  // Buffer2 prints "this is the first buffer."
  // Buffer3 prints only the first word entered because scanf stops at the first space. use fgets
  // =================================================================
  printf("\n======================================================================\n");


  // part 2
  printf("\n======================================================================\n");
  printf("Part 2: \n\n");
  printf("Buffer 3: ");
  char *pBuffer = Buffer3;
  while (*pBuffer != '\0')
  {
    printf("%c", *pBuffer);
    pBuffer++;
  }
  printf("\n======================================================================\n");


  //Part 3
  printf("\n======================================================================\n");
  printf("Part3: \n\n");

  printf("Which function do you want to call?: \n");
  printf("1. Reverse\n");
  printf("2. Recursive Reverse\n");
  printf("Enter a command: ");
  scanf("%hd", &menu);
  printf("\n");

  short length;

  switch(menu)
  {
    case 1: printf("Reverse:\n");
            Reverse(Buffer3);
            break;

    case 2: length = strlen(Buffer3);
            printf("Recursive Reverse:\n");
            RecursiveReverse(Buffer3, 0, length-1);
            printf("\n======================================================================\n");
            break;

    default: printf("Enter either 1 or 2.");
            break;
  }

  return 0;
}

//Reverse: Reversed Buffer3 string
//Input: pointer to Buffer3
//Output: None, Prints the string reversed
void Reverse(char *pBuffer3)
{
  char *p1 = pBuffer3;
  char *p2 = pBuffer3;

  while(*p2 != '\0')
  {
    p2++;
  }

  p2--;

  char hold;

  for(char hold ; p1 < p2; p1++, p2--)
  {
    hold = *p2;
    *p2 = *p1;
    *p1 = hold;
  }

  //displays the reversed string
  while(*pBuffer3 != '\0')
  {
    printf("%c", *pBuffer3);
    pBuffer3++;
  }

  printf("\n======================================================================\n");
}

//RecursiveReverse: Reverses a string recursively
//Input: Pointer to Buffer3
//Output: None, prints the Buffer3 string recursively
void RecursiveReverse(char *pBuffer4, char placement, short length)
{

  char hold;
  hold = pBuffer4[placement];
  pBuffer4[placement] = pBuffer4[length-placement];
  pBuffer4[length-placement] = hold;

  if (placement == length/ 2)
  {
    while(*pBuffer4 != '\0')
    {
      printf("%c", *pBuffer4);
      pBuffer4++;
    }
  }

  else
  {
    RecursiveReverse(pBuffer4, ++placement, length);
  }

}
