// Author: Mohamad Elchami Date: November 28th, 2017

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

//flip fuction
int flip()
{

 int rn=rand()% 2;

 if(rn == 0)
 {
   return 0;
 }

 else
 {
   return 1;
 }

}

//main fuction
int main(void)
{
  int t=0, h=0, counter;
  srand(time(NULL));

  for (counter=1; counter <= 100; counter++)
  {
    if (flip() == 0)
    {
      printf("Heads   ");
      h++;
    }

    else
    {
      printf("Tails   ");
      t++;
    }
  }

  printf("\n\nThe number of Heads was: %d\n", h);
  printf("The number of Tails was: %d\n", t);

  return 0;
}
