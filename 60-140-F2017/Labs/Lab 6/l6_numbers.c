// Athur: Mohamad Elchami Date: November 6th, 2015 Discription:
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
int main(void)
{
  int number, rn, n, spaces;

  printf("Enter a number between 2 and 9: ");
  scanf("%d", &number);

  time_t t;
   srand((unsigned) time(&t));

  for (; number > 0; number--)
  {

    rn = rand() % 8 + 2;

    if(rn<5)
    {
      printf("%d:", rn);

      for (rn -= 1; rn > 0; --rn)
      {
        printf("%d", number);
      }

      printf("\n");
    }

    else
    {
      printf("%d:", rn);

      for (spaces = rn; spaces > 0; spaces-- )
      {
        printf(" ");
      }

      for (n = 10 - rn; n > 0; --n )
      {
        printf("%d", number);
      }

      printf("\n");

    }
  }

return 0;

}
