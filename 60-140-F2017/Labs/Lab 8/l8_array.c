// Author: Mohamad Elchami Date:November 22nd, 2017

#include <stdio.h>
#include <math.h>
#include <time.h>
#include <stdlib.h>

int main(void)
{
  int width, height, count, number, x;
  float percent;
  char character;

  count = 0;
  number = 1;

  //Rand function component
  srand(time(NULL));

  //input prompt
  printf("9 < w < 21, 2 < h < 61\n");
  printf("Enter the width and heigh (w h): ");
  scanf("%d %d", &width, &height);

  //Master Loop
  for(; number < height;)
  {
    //generates random number
    int random = rand()%(width-2)+2;

    printf("%d:\t", random);

    //print components
    if(random < width/2)
    {
      for(x=0; x<random-1; x++)
      {
        //print numbers
        if(number<10)
        {
          printf("%d", number);
        }
        //prints chatacters
        else if (number<36)
        {
          character = 'a'-10+number;
          printf("%c", character);
        }
        else
        {
          character = 'A'-36+number;
          printf("%c", character);
        }
      }
    }
    //if within upper bounds of width/2
    else
    {
      //prints spaces
      for(x=0; x<random; x++)
      {
        printf(" ");
      }

      //prints numbers
      for(x=0; x<width-random; x++)
      {
        if(number<10)
        {
          printf("%d", number);
        }
        //prints characters
        else if(number<36)
        {
          character ='a'-10+number;
          printf("%c", character);
        }
        else
        {
          character = 'A'-36+number;
          printf("%c", character);
        }
      }
    }

    printf("\n");

    number++;

    count++;

  }
  //closing statement
  percent=((float)count/height)*100;
  printf("Amound %d numbers, the percentage of %d is %.2f%c.\n", height, x, percent, 37);

  return 0;

}
