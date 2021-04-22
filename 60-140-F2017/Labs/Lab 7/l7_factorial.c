// Authur: Mohamad Elchami  Date: November 14th, 2017 Discription: Calculates the factorial of a given positive integer//
#include<stdio.h>

int main(void)
{
  int integer, factorial, n;
  short sfactorial;
  unsigned short usfactorial;
  unsigned int uifactorial;
  long lfactorial;
  unsigned long ulfactorial;
  long long llfactorial;
  unsigned long long ullfactorial;
  long double ldfactorial;


  while (1)
  {
    printf("Enter a positive integer (or a negative integer to exit): ");
    scanf("%d", &integer);

    if (integer < 0)
    {
      break;
    }

    else
    {
        factorial = 1;
        sfactorial = 1;
        usfactorial = 1;
        uifactorial = 1;
        lfactorial = 1;
        ulfactorial = 1;
        llfactorial = 1;
        ullfactorial = 1;
        ldfactorial = 1;

        for( n = integer; n > 1 ; n--)
        {
          factorial *= n;
          sfactorial *= n;
          usfactorial *= n;
          uifactorial *= n;
          lfactorial *= n;
          ulfactorial *= n;
          llfactorial *= n;
          ullfactorial *= n;
          ldfactorial *= n;
        }

        printf ("The factorial of %d:\n", integer);
        printf("%hi (short, size = 2)\n", sfactorial);
        printf("%hu (unsigned short, size = 2)\n", usfactorial);
        printf("%d (int, size = 4)\n", factorial);
        printf("%u (unsigned int, size = 4)\n", uifactorial);
        printf("%li (long, size = 4)\n", lfactorial);
        printf("%lu (unsigned long, size = 4)\n", ulfactorial);
        printf("%lli (long long, size = 8)\n", llfactorial);
        printf("%llu (unsigned long long, size = 8)\n", ullfactorial);
        printf("%Lg (long double, size = 12)\n", ldfactorial);

    }
  }

  printf("Thank you for using my software. :)\n");

return 0;
}
