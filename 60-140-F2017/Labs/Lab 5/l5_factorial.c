// Authur: Mohamad Elchami  Date: October 29th, 2017 Discription: Calculates the factorial of a given positive integer//
#include<stdio.h>

int main(void)
{
  int integer, factorial, n;
  while (1)
  {
    printf("Enter a positive integer (or a negative integer to exit): ");
    scanf("%d", &integer);

    if (integer < 0)
    {
      break;
    }

    else if (integer > 12)
    {
      printf("Cannot compute factorial greater than 12.\n");
    }

    else
    {
        factorial = 1;

        for( n = integer; n > 1 ; n--)
        {
          factorial *= n;
        }

        printf("The factorial of %d is: %d \n", integer, factorial);
    }

  }

  printf("Thank you for using my software. :)\n");

return 0;
}
